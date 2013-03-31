/* Exercise 6.25 (c) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BSIZE 8 /* board size */

int main(void)
{
   int board[BSIZE][BSIZE] = { { 0 } };
			   /* 0   1   2   3   4   5  6  7 */
   int horizontal[BSIZE] = {  2,  1, -1, -2, -2, -1, 1, 2 };
   int vertical[BSIZE]   = { -1, -2, -2, -1,  1,  2, 2, 1 };

   int moveNumber, i, r, c;
   int currentRow, currentColumn;

   int clen[20] = { 0 }; /* max integer size */
   long int test = 0; /* total tests */
   int n = 0; /* tests where x < y */

   srand( time(NULL) );

   while(moveNumber < 64) {
      ++test;

      currentRow = currentColumn = 0;
      board[currentRow][currentColumn] = -1; /* current position */
      for(i = 1; i <= BSIZE*BSIZE; ++i) {
	    moveNumber = rand() % 8;

            r = currentRow + vertical[moveNumber];
            c = currentColumn + horizontal[moveNumber];

            if( (r >= 0 && r < BSIZE) && (c >= 0 && c < BSIZE) &&
		 !board[r][c] ) {
	       currentRow += vertical[moveNumber];
	       currentColumn += horizontal[moveNumber];
               board[r][c] = i;
	    }
	    
      } /* end for (i) */

      moveNumber = 0;
      for(r = 0; r < BSIZE; r++) {
         for(c = 0; c < BSIZE; c++) {
	    if(board[r][c]) {
	       ++moveNumber;
               board[r][c] = 0;
	    }
	 }
      }

      if(moveNumber > clen[n-1])
	 clen[n++] = moveNumber;

      if(n == 20) {
	 printf("Out of limit!\n");
	 return -1;
      }
   } /* end while (moveNumber) */

   printf("Turns: %ld\n", test); /* total turns */

   /* print the table */
   for( ; n > 1; n--) {
      printf("%d=%d\t", n, clen[n]);
      if( !(n % 10) ) {
         printf("\n");
      }
   }

   return 0;
} /* E0F main */

