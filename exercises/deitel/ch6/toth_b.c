/* Exercise 6.24 (b) */

#include <stdio.h>

#define BSIZE 8 /* board size */

int main(void)
{
   int board[BSIZE][BSIZE] = { { 0 } };
			   /* 0   1   2   3   4   5  6  7 */
   int horizontal[BSIZE] = {  2,  1, -1, -2, -2, -1, 1, 2 };
   int vertical[BSIZE]   = { -1, -2, -2, -1,  1,  2, 2, 1 };

   int moveNumber, i, r, c;
   int currentRow = 0, currentColumn = 0;
   board[currentRow][currentColumn] = -1; /* current position */

   for(i = 1; i <= BSIZE*BSIZE; i++) {
      for(moveNumber = 0; moveNumber < BSIZE; moveNumber++) {

         r = currentRow + vertical[moveNumber];
         c = currentColumn + horizontal[moveNumber];

         if( (r >= 0 && r < BSIZE) && (c >= 0 && c < BSIZE) && !board[r][c] ) {
	    currentRow += vertical[moveNumber];
	    currentColumn += horizontal[moveNumber];
            board[r][c] = i;
	    break;
	 }
      } /* end for (moveNumber) */
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

