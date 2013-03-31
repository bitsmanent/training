/* Exercise 6.25

 * Command list: 
 *    1: Pen is up
 *    2: Pen is down
 *    3: Right
 *    4: Left
 *    5.n: Go ahead of n steps
 *    6: print the floor
 *    9: end of data (quit)
*/

#include <stdio.h>
#define SIZE 50 
#define CMD 11

int getroute(int, int);
void pmatrix(double [][SIZE], int);

int main(void)
{
   double floor[SIZE][SIZE] = { {0} };

   /* NOTE: don't use (for example) "5.9" but "5.09" and the 
    * 5.01 command do nothing: it write in the current position
    * which has been already written bye the previous command. */

   /* Don't forget '2' to write and '1', '6' and '9' to end */

   double cmds[CMD] = { 2, 5.25, 3, 5.12, 3, 5.25, 3, 5.12, 1, 6, 9 };

   /* Square (CMD = 11)
   double cmds[CMD] = { 2, 5.12, 3, 5.12, 3, 5.12, 3, 5.12, 1, 6, 9 };
   */

   /* C (CMD = 11)
   double cmds[CMD] = { 3, 3, 2, 5.09, 4, 5.06, 4, 5.09, 1, 6, 9 };
   */
   /* H (CMD = 16)
   double cmds[CMD] = {
      3, 2, 5.09, 4, 4, 5.05, 3, 5.08, 4, 5.05, 3, 3, 5.09, 1, 6, 9
   };
   */

   int pen = 0; /* 0 don't write */
   int route = 4, i, j;

   int r = 0, c = 0; /* rows and cols */
   r = c = SIZE/2-1; /* Logo start from middle of floor */

   /* loop all commands (cmds[]) */
   for(i = 0; i < CMD; i++) {
      /* check the command */
      switch( (int)cmds[i] ) {
	 case 1:
	    pen = 0;
	    break;
	 case 2:
	    pen = 1;
	    break;
	 case 3:
	 case 4:
	    route = getroute(route, (int)cmds[i]);
	    break;
         case 5:
	    j = (int)(cmds[i] * 100) % 100;

	    if(cmds[i] == 5.02 || cmds[i] == 5.06) /* fix 5.02 and 5.06 */
	       ++j;

	    /* Overflow check */
	    if( (route == 1 && r + j > SIZE) || (route == 2 && r - j < 0) ||
		(route == 3 && c - j < 0) || (route == 4 && c + j > SIZE)
  	    ) {
		printf("You can't go out of floor (%dx%d): 5.%d\n",
		SIZE, SIZE, j);
		return -1;
            }

	    for( ; j ; j--) {
               /* UP[1], DOWN[2], LEFT[3], RIGHT[4] */

               if(route > 2)
	          floor[r][route == 4 ? c++ : c--] = pen;
	       else
	          floor[route == 2 ? r-- : r++][c] = pen;

	    } /* end for (j) */

	    /* cursor in the current position */
	    if(route == 4) c--;
	    else if(route == 3) ++c;
	    else if(route == 2) ++r;
	    else --r;

	    break;
         case 6:
	    /* print the matrix */
	    pmatrix(floor, SIZE);
	    break; /* not required */
      } /* end switch (cmds[i]) */

   } /* end for (i) */
   printf("\n");

   return 0;
} /* E0F main */

/* find the route "d" starting from "cr" */
int getroute(int cr, int d)
{
   switch(cr) {
      case 1: /* Up */
	 return d;
	 break;
      case 2: /* Down */
	 return d == 4 ? 3 : 4;
	 break;
      case 3: /* Left */
	 return d == 3 ? 2 : 1;
	 break;
      case 4: /* Right */
	 return d == 4 ? 2 : 1;
	 break;
      default: /* Uhm? */
	 printf("Maybe you need a compass? :-)\n");
	 return 0;
   }
} /* end of getroute() */

/* Print the matrix */
void pmatrix(double m[][SIZE], int s)
{
   int r, c;

   for(r = 0; r < s; r++) {
      for(c = 0; c < s; c++) {
	 if(m[r][c])
	    printf("+");
	 else {
	    if(c == s - 1 || c == 0) printf("."); /* wall */
	    printf(" ");
	 }
      }
      printf("\n");
   }

} /* eof pmatrix() */

