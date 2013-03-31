/* Fig. 7.24: fig07_24.c
   Card shuffling dealing program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* prototypes */
void shuffleAndDeal( int wDeck[][ 13 ], int n_cards,
              const char *wFace[], const char *wSuit[] );

int main(void)
{
   /* initialize suit array */
   const char *suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades" };
   
   /* initialize face array */
   const char *face[ 13 ] = 
      { "Ace", "Deuce", "Three", "Four", 
        "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" };

   /* initialize deck array */
   int deck[ 4 ][ 13 ] = { { 0 } };

   srand( time( 0 ) ); /* seed random-number generator */

   shuffleAndDeal( deck, 5, face, suit );

   return 0; /* indicates successful termination */

} /* end main */



/* shuffle and deal cards in deck */
void shuffleAndDeal( int wDeck[][ 13 ], int n_cards,
              const char *wFace[], const char *wSuit[] )
{
   int row;    /* row number */
   int column; /* column number */
   int card;   /* counter */

   /* for each of the 52 cards, choose slot of deck randomly */
   for ( card = 1; card <= 26; card++ ) {

      /* choose new random location until unoccupied slot found */
      do {
         row = rand() % 4;
         column = rand() % 13;
      } while( wDeck[ row ][ column ] != 0 ); /* end do...while */

      /* place card number in chosen slot of deck */
      wDeck[ row ][ column ] = card;

      if(n_cards) {
         printf( "%5s of %-8s%c", wFace[ column ], wSuit[ row ],
            card % 2 == 0 ? '\n' : '\t' );
	 --n_cards;
      }

   } /* end for */
   printf("\n");

} /* end function shuffleAndDeal */

