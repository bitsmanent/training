/* Exercise 7.26 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 12
#define LOOPS 100

#define RIGHT 1
#define DOWN  2
#define LEFT  3
#define UP    4

void mazeTraverse(char maze[][SIZE], int r, int c, int ret[], int route);
void mazeGenerator(char maze[][SIZE], int ret[]);

void pmaze(char maze[][SIZE]);

void go(char maze[][SIZE], int *r, int *c, int route);

int ahead(char maze[][SIZE], int *r, int *c, int route, int check);
int toright(char maze[][SIZE], int r, int c, int route);
int chroute(int route, int nroute);

int main(void)
{
   char maze[SIZE][SIZE];
   int ret[4] = { 0 }, route;

   srand( time(NULL) );

   mazeGenerator(maze, ret);

   /* Set the route */
   if(!ret[0]) route = DOWN;
   else if(ret[0] == SIZE - 1) route = UP;
   else if(!ret[1]) route = RIGHT;
   else if(ret[1] == SIZE - 1) route = LEFT;

   mazeTraverse(maze, ret[0], ret[1], ret, route);

   return 0;
} /* E0F main */

/* Generate a maze and put it to the "maze" matrix */
void mazeGenerator(char maze[][SIZE], int ret[])
{
   int row, col, i = 0;

   /* Inizialize the maze */
   for(row = 0; row < SIZE; row++)
      for(col = 0; col < SIZE; col++)
	 maze[row][col] = '#';


   row = rand() % SIZE; 
   col = !row || row == SIZE-1 ? 1 + rand()%(SIZE-2) : rand()%2 ? SIZE-1 : 0;

   ret[0] = row;
   ret[1] = col;

   if(!ret[1] || ret[1] == SIZE - 1) {
      ret[2] = rand() % 2 ? 0 : SIZE - 1;
      ret[3] = 1 + rand() % 10;
   }
   else {
      ret[2] = 1 + rand() % 10;
      ret[3] = rand() % 2 ? 0 : SIZE - 1;
   }

   maze[ret[0]][ret[1]] = '.'; /* Start point */
   maze[ret[2]][ret[3]] = 'E'; /* End point */

   /* Create the path */ 
   while(i++ < LOOPS) {
      row = 1 + rand() % 10;
      col = 1 + rand() % 10;

      maze[row][col] = '.';
   }

} /* eof mazeGenerator() */

/* Traverse a maze founding the exit, if exists */
void mazeTraverse(char maze[][SIZE], int r, int c, int ret[], int route)
{
   maze[r][c] = (maze[r][c] != 'x' && maze[r][c] != 'X') ? 'x' : 'X';
   printf("\n");

   pmaze(maze);


   if(ahead(maze, &r, &c, route, 1)) {
      if(toright(maze, r, c, route)) {

	 /* A little fix */
	 maze[r][c] = maze[r][c] == 'x' ? '.' : 'X';

	 route = chroute(route, LEFT);
      }
   }
   else {
      if(!toright(maze, r, c, route)) {
	 route = chroute(route, RIGHT);
      }
   }

   if(r == ret[0] && c == ret[1]) {
      printf("Closed maze!\n");
      return;
   }

   if(r == ret[2] && c == ret[3]) {
      printf("Exit found!\n");
      return;
   }
   else
      mazeTraverse(maze,r, c, ret, route);


} /* eof mazeTraverse() */

/* Print a maze */
void pmaze(char maze[][SIZE])
{
   int i, j;

   for(i = 0; i < SIZE; i++) {
      for(j = 0; j < SIZE; j++) {
	 printf("%c ", maze[i][j]);
      }
      printf("\n");
   }

} /* eof pmaze() */

/* Ehm.. go ahead :-) */
int ahead(char maze[][SIZE], int *r, int *c, int route, int check)
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
int toright(char maze[][SIZE], int r, int c, int route)
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

