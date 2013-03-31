/* Exercise 7.27 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 19
#define COLS 19

#define LOOPS ROWS * COLS

#define RIGHT 1
#define DOWN  2
#define LEFT  3
#define UP    4

void mazeTraverse(char maze[][COLS], int r, int c, int ret[], int route);
void mazeGenerator(char maze[][COLS], int ret[]);

void pmaze(char maze[][COLS]);

void go(char maze[][COLS], int *r, int *c, int route);

int ahead(char maze[][COLS], int *r, int *c, int route, int check);
int toright(char maze[][COLS], int r, int c, int route);
int chroute(int route, int nroute);

int main(void)
{
   char maze[ROWS][COLS];
   int ret[4] = { 0 }, route;

   srand( time(NULL) );

   mazeGenerator(maze, ret);

   /* Set the route */
   if(!ret[0]) route = DOWN;
   else if(ret[0] == ROWS - 1) route = UP;
   else if(!ret[1]) route = RIGHT;
   else if(ret[1] == COLS - 1) route = LEFT;

   mazeTraverse(maze, ret[0], ret[1], ret, route);

   return 0;
} /* E0F main */

/* Generate a maze and put it to the "maze" matrix */
void mazeGenerator(char maze[][COLS], int ret[])
{
   int row, col, i = 0;

   /* Inizialize the maze */
   for(row = 0; row < ROWS; row++)
      for(col = 0; col < COLS; col++)
	 maze[row][col] = '#'; 

   row = rand() % ROWS; 
   col = !row || row == ROWS-1 ? 1 + rand()%(COLS-2) : rand()%2 ? COLS-1 : 0;

   ret[0] = row;
   ret[1] = col;

   if(!ret[1] || ret[1] == COLS - 1) {
      ret[2] = rand() % 2 ? 0 : ROWS - 1;
      ret[3] = 1 + rand() % (COLS - 2);
   }
   else {
      ret[2] = 1 + rand() % (ROWS - 2);
      ret[3] = rand() % 2 ? 0 : COLS - 1;
   }

   maze[ret[0]][ret[1]] = '.'; /* Start point */
   maze[ret[2]][ret[3]] = 'E'; /* End point */

   /* Create the path */ 
   while(i++ < LOOPS) {
      row = 1 + rand() % (ROWS - 2);
      col = 1 + rand() % (COLS - 2);

      maze[row][col] = '.';
   }

} /* eof mazeGenerator() */

/* Traverse a maze founding the exit, if exists */
void mazeTraverse(char maze[][COLS], int r, int c, int ret[], int route)
{
   static int print = 1;

   maze[r][c] = (maze[r][c] != 'x' && maze[r][c] != 'X') ? 'x' : 'X';

   if(print) { /* Don't show the route changes */
      printf("\n");
      pmaze(maze);
   }

   if(ahead(maze, &r, &c, route, 1)) {
      if(toright(maze, r, c, route)) {

	 /* A little fix */
	 maze[r][c] = maze[r][c] == 'x' ? '.' : 'X';

	 route = chroute(route, LEFT);
	 print = 0;
      }
      else print = 1;
   }
   else {
      if(!toright(maze, r, c, route)) {
	 route = chroute(route, RIGHT);
      }
      else print = 1;
   }

   if(r == ret[0] && c == ret[1]) {
      printf("Closed maze!\n");
      return;
   }
   else if(r == ret[2] && c == ret[3]) {
      printf("Exit found: row %d, col %d.\n", ret[2], ret[3]);
      return;
   }
   else
      mazeTraverse(maze, r, c, ret, route);

} /* eof mazeTraverse() */

/* Print a maze */
void pmaze(char maze[][COLS])
{
   int i, j;

   for(i = 0; i < ROWS; i++) {
      for(j = 0; j < COLS; j++) {
	 printf("%c ", maze[i][j]);
      }
      printf("\n");
   }

} /* eof pmaze() */

/* Ehm.. go ahead :-) */
int ahead(char maze[][COLS], int *r, int *c, int route, int check)
{
   switch(route)
   {
      case RIGHT:
         if(maze[*r][*c + 1] == '#' && check)
	    return 1;
	 else
	    ++*c;
	 break;
      case DOWN:
	 if(maze[*r + 1][*c] == '#' && check)
	    return 1;
	 else
	    ++*r;
	 break;
      case LEFT:
	 if(maze[*r][*c - 1] == '#' && check)
	    return 1;
	 else
	    --*c;
	 break;
      case UP:
	 if(maze[*r - 1][*c] == '#' && check)
	    return 1;
	 else
	    --*r;
	 break;
      default:
	 printf("Where are you going?\n");
	 exit(-1);
   }

   return 0;
} /* eof ahead() */

/* Check if the wall is to the right side */
int toright(char maze[][COLS], int r, int c, int route)
{
   switch(route)
   {
      case RIGHT:
	 if(maze[r + 1][c] == '#')
	    return 1;
	 break;
      case DOWN:
	 if(maze[r][c - 1] == '#')
	    return 1;
	 break;
      case LEFT:
	 if(maze[r - 1][c] == '#')
	    return 1;
	 break;
      case UP:
	 if(maze[r][c + 1] == '#')
	    return 1;
	 break; 
      default:
	 printf("What's your position?\n");
	 exit(-1);

   } 

   return 0;
} /* eof toright() */

/* Turn to left */
int chroute(int route, int nroute)
{
   switch(route) {
      case RIGHT:
	 if(nroute == RIGHT)
	    route = DOWN;
	 else if(nroute == DOWN)
	    route = LEFT;
	 else if(nroute == LEFT)
	    route = UP;
	 else if(nroute == UP)
	    ; /* don't change */
	 else
	    route = 0;
	 break;
      case DOWN:
	 if(nroute == RIGHT)
	    route = LEFT;
	 else if(nroute == DOWN)
	    route = UP;
	 else if(nroute == LEFT)
	    route = RIGHT;
	 else if(nroute == UP)
	    ; /* don't change */
	 else
	    route = 0;
	 break;
      case LEFT:
	 if(nroute == RIGHT)
	    route = UP;
	 else if(nroute == DOWN)
	    route = RIGHT;
	 else if(nroute == LEFT)
	    route = DOWN;
	 else if(nroute == UP)
	    ; /* don't change */
	 else
	    route = 0;
	 break;
      case UP:
	 if(nroute == RIGHT || nroute == UP ||
	    nroute == LEFT || nroute == DOWN) {
	    route = nroute;
	 }
	 else
	    route = 0;
	 break;
      default:
	 printf("Where do you want to go?\n");
	 exit(-1);
   }


   if(!route) {
      printf("ERROR: invalid route: %d\n", nroute);
      return -1;
   }

   return route;
} /* eof chroute() */

