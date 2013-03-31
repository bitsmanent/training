/* Exercise 6.29 */

#include <stdio.h>

#define BSIZE 8 /* board size */

int cyclical(int r, int c, int row, int col, int hor[], int ver[], int size);

int main(void)
{
   int board[BSIZE][BSIZE] = { { 0 } };
			   /* 0   1   2   3   4   5  6  7 */
   int horizontal[BSIZE] = {  2,  1, -1, -2, -2, -1, 1, 2 };
   int vertical[BSIZE]   = { -1, -2, -2, -1,  1,  2, 2, 1 };

   /* Method "heuristic of accessibility" */
   int accessibility[BSIZE+1][BSIZE] = {
      { 2, 3, 4, 4, 4, 4, 3, 2 },
      { 3, 4, 6, 6, 6, 6, 4, 3 },
      { 4, 6, 8, 8, 8, 8, 6, 4 },
      { 4, 6, 8, 8, 8, 8, 6, 4 },
      { 4, 6, 8, 8, 8, 8, 6, 4 },
      { 4, 6, 8, 8, 8, 8, 6, 4 },
      { 3, 4, 6, 6, 6, 6, 4, 3 },
      { 2, 3, 4, 4, 4, 4, 3, 2 },
      { BSIZE } /* extra value */
   };

   int nr, nc; /* next position according with the "accessibility" matrix */
   int pass = 0; /* write permission checker :-) */
   int v1, v2, mn;

   int moveNumber = 0, i, r, c;
   int currentRow = 0, currentColumn = 0;
   int sr = currentRow;
   int sc = currentColumn;
   board[currentRow][currentColumn] = -1; /* current position */
   /* current accessibility position */
   --accessibility[currentRow][currentColumn];


   for(i = 1; i <= BSIZE*BSIZE; i++) {
      nr = BSIZE;
      nc = 0;
      for(moveNumber = 0; moveNumber < BSIZE; moveNumber++) {

         /* read next potential position */
         r = currentRow + vertical[moveNumber];
         c = currentColumn + horizontal[moveNumber];

         /* it's not out of chessboard */
         if( (r >= 0 && r < BSIZE) && (c >= 0 && c < BSIZE) && !board[r][c] ) {
	    pass = 1; /* write access granted :-) */

	    /* check accessibility level */
	    if(accessibility[r][c] < accessibility[nr][nc]) {
	       nr = r;
	       nc = c;
	    }  
	    else if(accessibility[r][c] == accessibility[nr][nc]) {
	       /* check *one* sublevel (r, c) */
	       for(mn = 0, v1 = BSIZE; mn < BSIZE; mn++) {
		  if((accessibility[r+vertical[mn]][c+horizontal[mn]]<v1) &&
                  (r >= 0 && r < BSIZE) && (c >= 0 && c < BSIZE) &&
		  !board[r][c])
		     v1 = accessibility[r + vertical[mn]][c + horizontal[mn]];
	       }

	       /* check *one* sublevel (nr, nc) */
	       for(mn = 0, v2 = BSIZE; mn < BSIZE; mn++) {
		  if((accessibility[nr+vertical[mn]][nc+horizontal[mn]]<v2) &&
		  (nr >= 0 && r < BSIZE) && (nc >= 0 && c < BSIZE) &&
		  !board[nr][nc])
		     v2 = accessibility[nr + vertical[mn]][nc + horizontal[mn]];
	       }

	       /* check'n set */
	       if(v1 < v2) {
		  nr = r;
		  nc = c;
	       }
	    }
	 } /* end if */
      } /* end for (moveNumber) */

      if(pass) {
	 currentRow = nr;
	 currentColumn = nc;
	 --accessibility[nr][nc];
         board[currentRow][currentColumn] = i;
	 pass = 0;
      }
      else /* stalled */
	 break;
   } /* end for (i) */

   mn = 0;
   for(r = 0; r < BSIZE; r++) {
      for(c = 0; c < BSIZE; c++) {
	 if(board[r][c]) {
	    printf(" + ");
	    ++mn;
	 }
	 else
	    printf(" - ");
      }
      printf("\n");
   }
   printf("Moves: %d\n", mn);

   /* check if the turn is cyclical */
   if(cyclical(sr, sc, currentRow, currentColumn, horizontal, vertical, BSIZE))
      printf("The turn is cyclical!\n");
   else
      printf("The turn is *not* cyclical!\n");

   return 0;
} /* E0F main */

/* check if a turn is cyclical */
int cyclical(int r, int c, int row, int col, int hor[], int ver[], int size)
{
   int x, y;

   for(x = 0; x < size; x++) {
      if(r + ver[x] == row) {
	 for(y = 0; y < BSIZE; y++) {
	    if(c + hor[y] == col)
	       return 1;
	 } /* end for */
      } /* end if */
   } /* end for (x) */

   return 0; /* is not cyclical */
} /* eof cyclical() */

