/* Exercise 6.24 (c) */

#include <stdio.h>

#define BSIZE 8 /* board size */

int main(void)
{
   int board[BSIZE][BSIZE] = { { 0 } };
			   /* 0   1   2   3   4   5  6  7 */
   int horizontal[BSIZE] = {  2,  1, -1, -2, -2, -1, 1, 2 };
   int vertical[BSIZE]   = { -1, -2, -2, -1,  1,  2, 2, 1 };

   /* Method "heuristic of accessibility" */
   int accessibility[BSIZE][BSIZE] = {
      { 2, 3, 4, 4, 4, 4, 3, 2 },
      { 3, 4, 6, 6, 6, 6, 4, 3 },
      { 4, 6, 8, 8, 8, 8, 6, 4 },
      { 4, 6, 8, 8, 8, 8, 6, 4 },
      { 4, 6, 8, 8, 8, 8, 6, 4 },
      { 4, 6, 8, 8, 8, 8, 6, 4 },
      { 3, 4, 6, 6, 6, 6, 4, 3 },
      { 2, 3, 4, 4, 4, 4, 3, 2 }
   };

   /* next position according with the "accessibility" matrix */
   int new_r, new_c;

   int cal; /* current accessibility level */
   int pass = 0; /* write permission checker :-) */

   int moveNumber = 0, i, r, c;
   int currentRow = 0, currentColumn = 0;
   board[currentRow][currentColumn] = -1; /* current position */

   for(i = 1; i <= BSIZE*BSIZE; i++) {
      cal = BSIZE;
      for(moveNumber = 0; moveNumber < BSIZE; moveNumber++) {

         /* read next potential position */
         r = currentRow + vertical[moveNumber];
         c = currentColumn + horizontal[moveNumber];

         /* it's not out of chessboard */
         if( (r >= 0 && r < BSIZE) && (c >= 0 && c < BSIZE) && !board[r][c] ) {
	    pass = 1; /* write access granted :-) */

	    /* check accessibility level */
	    if(accessibility[r][c] < cal) {
	       new_r = r;
	       new_c = c;
	       cal = accessibility[new_r][new_c];
	    }
	 }
      } /* end for (moveNumber) */

      if(pass) {
	 currentRow = new_r;
	 currentColumn = new_c;
	 --accessibility[new_r][new_c];
         board[currentRow][currentColumn] = i;
	 pass = 0;
      }
      else /* stalled */
	 break;
   } /* end for (i) */

   moveNumber = 0;
   for(r = 0; r < BSIZE; r++) {
      for(c = 0; c < BSIZE; c++) {
	 if(board[r][c]) {
	    printf("+");
	    ++moveNumber;
	 }
	 else
	    printf("-");
      }
      printf("\n");
   }
   printf("Moves: %d\n", moveNumber);

   return 0;
} /* E0F main */

