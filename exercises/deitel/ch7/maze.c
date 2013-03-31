/* Exercise 7.25 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 12

#define RIGHT 1
#define DOWN  2
#define LEFT  3
#define UP    4

void mazeTraverse(char maze[][SIZE], int r, int c, int route);

void pmaze(char maze[][SIZE]);

int ahead(char maze[][SIZE], int *r, int *c, int route);
int toright(char maze[][SIZE], int r, int c, int route);
int chroute(int route, int nroute);

int main(void)
{
   char maze[SIZE][SIZE] = { 
      { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
      { '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#' },
      { '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#' },
      { '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#' },
      { '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.' },
      { '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#' }, 
      { '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' }, 
      { '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
      { '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#' },
      { '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#' },
      { '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#' },
      { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' }
   };

   mazeTraverse(maze, 2, 0, RIGHT);

   return 0;
} /* E0F main */

/* Traverse a maze founding the exit, if exists */
void mazeTraverse(char maze[][SIZE], int r, int c, int route)
{
   maze[r][c] = (maze[r][c] != 'x' && maze[r][c] != 'X') ? 'x' : 'X';
   printf("\n");
   pmaze(maze);

   if(c == SIZE - 1) {
      return;
   }

   if(ahead(maze, &r, &c, route)) {
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

   if(!c) return;

   mazeTraverse(maze, r, c, route);


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
int ahead(char maze[][SIZE], int *r, int *c, int route)
{
   switch(route)
   {
      case RIGHT:
         if(maze[*r][*c + 1] == '#')
	    return 1;
	 else
	    ++*c;
	 break;
      case DOWN:
	 if(maze[*r + 1][*c] == '#')
	    return 1;
	 else
	    ++*r;
	 break;
      case LEFT:
	 if(maze[*r][*c - 1] == '#')
	    return 1;
	 else
	    --*c;
	 break;
      case UP:
	 if(maze[*r - 1][*c] == '#')
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

