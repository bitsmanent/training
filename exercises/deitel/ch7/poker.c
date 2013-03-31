/* Exercise 7.14 */

/* Fig. 7.24: fig07_24.c
   Card shuffling dealing program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 5
#define DECK 26
#define PLAYERS 2

/* Points setting *
 * NOTE: the points *must* have an offset >= 15 and P_PAIR
 *       must should be >= 15 too to works properly. Else,
 *       Else, the game will sh0w only INVALID results and
 *       wrong winners.
 */
#define OFFSET 15 

/* I'll tweak these, maybe.. a day :-) */
#define P_PAIR 		OFFSET
#define P_DOUBLE	P_PAIR + OFFSET
#define P_TRIS		P_DOUBLE + OFFSET
#define P_SCALE		P_TRIS + OFFSET
#define P_FULL		P_SCALE + OFFSET
#define P_POKER		P_FULL + OFFSET
#define P_COLOR		P_POKER + OFFSET
#define P_SFLUSH	P_COLOR + OFFSET
#define P_RFLUSH	P_SFLUSH + OFFSET

/* prototypes */
void shuffle( int wDeck[][ 13 ] );

void deal( int wDeck[][ 13 ], const char *wFace[], const char *wSuit[],
           int cards[][CARDS][2], int player, int wCards, int show);

int getp(int cards[][CARDS][2], int player, const char *wFace[],
         const char *wSuit[], int n_cards, int *r_suit, int type[]);

void order(int a[][CARDS][2], int p, int size);
void rswap(int *a, int *b);

int chcs(int cards[][CARDS][2], int player, int type[], const char *wFace[], 
         const char *wSuit[], int wDeck[][13], int n_cards); 

int main(void)
{
   int i, type[1 + PLAYERS], winner[3] = { 0 }, points[1 + PLAYERS] = { 0 };
   int p[1 + PLAYERS][2] = { { 0 } };
   int cards[1 + PLAYERS][CARDS][2] = { { { 0 } } };

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

   shuffle( deck );

   /* S t a r t */
   printf("GaMe STaRTeD!\n\n");
   printf("Deck: %d\nCards for player: %d\nNumber of players: %d\n\n\n",
      DECK, CARDS, PLAYERS);

   for(i = 0; i < PLAYERS + 1; i++) {
      if(!i)
         printf("*** Computer is playing..\n");
      else
         printf("*** Player %d is playing..\n", i);

      printf("-----------------------------------------\n");
      deal( deck, face, suit, cards, i, CARDS, !i ? i : 1);

      printf("\n\n");

      /* p[i][0] == points
       * p[i][1] == suit of highest card (whitin the highest kind)
       * i == the player
       * p[0][?] == the computer 
       */
      p[i][0] = getp(cards, i, face, suit, CARDS, &p[i][1], type);

      printf("\nScore: %d ", p[i][0]);
      if(i) printf("(suit points reserved: %d)", 4 - p[i][1]);

      printf("\n");
      printf("-----------------------------------------\n");

      /* so */
      points[i] = p[i][0] - p[i][1]; /* points - seed(0 highest, 3 lowest) */
      printf("\n\n");
   }

   /* Changes */

   /* Change the cards, if needed */
   if( chcs(cards, 0, type, face, suit, deck, CARDS) ) {
      /* If cards are changed */
      p[0][0] = getp(cards, 0, face, suit, CARDS, &p[0][1], type);
      printf("\n");
   }

   /* F i n i s h */

   /* Check the winner and print the classifies */
   for(i = 0; i < PLAYERS + 1; i++) {
      if(p[i][0] > winner[0]) {
	 winner[0] = p[i][0];
	 winner[1] = p[i][1];
	 winner[3] = i;
      }
      else if(p[i][0] == winner[0]) { /* Pair: check the suit */ 
	 if(p[i][1] < winner[1]) {
	    winner[0] = p[i][0];
	    winner[1] = p[i][1];
	    winner[3] = i;
	 }
      }
   } /* end for (i) */

   printf("\n\tC l a s s i f i e s\n\n");
   printf("%16s%9s\n", "Player", "Points");
   printf("%16s%9d\n", "PC", p[0][0]);
   for(i = 1; i < PLAYERS + 1; i++) {
      printf("%16d%9d\n", i, p[i][0]);
   }
   printf("\n");
   
   if(!winner[3])
      printf("* Computer won with %d points.\n", winner[0]);
   else
      printf("* Player %d won with %d points.\n", winner[3], winner[0]);

   printf("\n");
   return 0; /* indicates successful termination */

} /* end main */

/* shuffle cards in deck */
void shuffle( int wDeck[][ 13 ] )
{
   int row;    /* row number */
   int column; /* column number */
   int card;   /* counter */

   /* for each of the 52 cards, choose slot of deck randomly */
   for ( card = 1; card <= DECK; card++ ) {

      /* choose new random location until unoccupied slot found */
      do {
         row = rand() % 4;
         column = rand() % 13;
      } while( wDeck[ row ][ column ] != 0 ); /* end do...while */

      /* place card number in chosen slot of deck */
      wDeck[ row ][ column ] = card;
   } /* end for */

} /* end function shuffle */

/* deal cards in deck */
void deal( int wDeck[][ 13 ], const char *wFace[], const char *wSuit[],
           int cards[][CARDS][2], int player, int wCards, int show)
{
   int card;   /* card counter */
   int row;    /* row counter */
   int column; /* column counter */
   int i = 0;

   if(show == 2)
      printf("==> Computer is changing cards..\n\n");

   /* deal each of the 52 cards */
   for ( card = 1; card <= DECK; card++ ) {
      /* loop through rows of wDeck */
      for ( row = 0; row <= 3; row++ ) {

         /* loop through columns of wDeck for current row */
         for ( column = 0; column <= 12; column++ ) {
            /* if slot contains current card, display card */
            if ( wDeck[ row ][ column ] == card ) {

	       if(show == 2)
		  printf( "%5s of %-8s => ", wFace[cards[player][i][0]],
	             wSuit[cards[player][i][1]]);

               cards[player][i][0] = column;
	       cards[player][i][1] = row;

	       if(!show)
	          printf("%15s", " HIDDEN ");
	       else
		  printf( "%5s of %-8s", wFace[ column ], wSuit[ row ]);

	       ++i;

	       if(show != 2) printf("%c", !(card % 2) ? '\n' : '\t');
	       else printf("\n");

	       wDeck[row][column] = 0;

               /* dealing only "wCards" cards */
	       if(i == wCards) {
		  printf("\n");
		  return;
	       }

            } /* end if */

         } /* end for */

      } /* end for */

   } /* end for */

} /* end function deal */

/* Get the points of a player */
int getp(int cards[][CARDS][2], int player, const char *wFace[],
         const char *wSuit[], int n_cards, int *r_suit, int type[])
{
   int i, points;
   int scale = 0, n;
   int o[13][2] = { { 0 } }; /* occurrences */


   int kind = 0, face, suit;
   /* 0 = nothing
    * 1 = Pair 
    * 2 = Double
    * 3 = Tris
    * 4 = scale
    * 5 = Full
    * 6 = Poker
    * 7 = Color
    * 8 = straight flush
    * 9 = royal flush
    */

   /* Inizitialize the o[0,12][1] to 4. Note that 4 is
    * a value (random) greather then highest suit (3). */
   for(i = 0; i < 13; i++)
      o[i][1] = 4;

   /* count the occurrences of each card's face and
    * save to the current index the highest suit */
   for(i = 0; i < n_cards; i++) {
      ++o[cards[player][i][0]][0];

      /* store the index of the highest suit */
      if(o[cards[player][i][0]][1] > cards[player][i][1])
         o[cards[player][i][0]][1] = cards[player][i][1];

   }

   /* Ok, now don't forget this:
    *
    * o[i][0] == the occurrences
    * o[i][1] == the suit 
    * i == the face
    */

   /* check if there is a pair/double/tris/full/poker */
   for(i = 0; i < 13; i++) {
      switch(o[i][0]) {
	 case 2:
	    /* if this is the 1st pair */
	    if(!kind) /* is a pair */
	       kind = 1; 

	    /* else could be a double */
	    else if(kind == 1)
	       kind = 2;

	    else /* else is full */
	       kind = 3;

	    break;
	 case 3:
	    /* If is the current game is a pair */
	    if(kind == 1)
	       kind = 5; /* then become "full" */

	    else /* else is tris */
	       kind = 3;

	    break;
	 case 4:
	    /* Oh, this is Poker! :-) */
	    kind = 6;
	    break;
	 default:
	    /* !o[i][0] */
	    ;

      } /* end switch (o[i]) */

      if( o[i][0] > 1 && (kind != 2 || (kind == 2 && face < i)) ) {
	 /* If is double and the current pair is not greather
	  * then previous, then i don't store its face/suit */

         face = i;
         suit = o[i][1];
      }

   } /* end for (i) */


   /* Here i've checked: pair, double, tris, full and poker.
    * "face" and "suit" contains the highest value of the current
    * "kind". The suit is required if there are an "equal" result
    * for change (increment or decrement) the current value of
    * each one basing on the suit. 
    * Missing: scale, color and "all cards are not equals". */


   /* if all cards are different store the highest of these */
   if(kind == 0 && !scale) {
      for(i = 0, face = -1; i < n_cards; i++) {

	 /* search the highest */
	 if((!face ? 13 : face) < (!cards[player][i][0] ? 13 :
	    cards[player][i][0]) ) {
	    face = cards[player][i][0];
	    suit = cards[player][i][1];
	 }

	 /* if are equal, store the suit */
	 else if(face == cards[player][i][0]) {
	    if(suit < cards[player][i][1]) {
	       suit = cards[player][i][1];
	    }
	 }
	       
      }
   }

   /* check the color */
   for(i = 0, n = 4; i < n_cards; i++) {
      if(! (n == 4) ) {
         if(cards[player][i][1] != n)
            n = - 1;
      }
      else
	 n = cards[player][i][1];
   }
   if(n != -1) /* live enjoy: life's colored :-) */
      kind = 7;

   /* check the scale / *_flush */
   order(cards, player, n_cards);

   for(i = n = 1; i < n_cards; i++) {
      if(cards[i - 1][0] + 1 != cards[i][0]) {
	 n = 0;
	 break;
      }
   }
   if(n) { /* This is scale / *_flush */

      if(kind == 7) { /* *_flush */
	 if(face == 0) { /* royal flush */
	    kind = 9;
	 }

	 else { /* straight flush */
            kind = 8;
	 }
      }
      else { /* just scale */
         kind = 4;
      }
   }

   *r_suit = suit;
   type[player] = kind;

   /* Print the kind of game and assign the points */
   switch(kind) {
      case 0: /* Nothing */
	 printf("All cards are differents!\n"
	        "You could win with the %s of %s\n",
	           wFace[face], wSuit[suit]);

	 points = face;
	 break;
      case 1: /* Pair */
	 printf("Oh, it is a pair of %ss!\n", wFace[face]);

	 points = P_PAIR + face;
	 break;
      case 2: /* Double */
	 printf("Double to %ss\n", wFace[face]);

	 points = P_DOUBLE + face;
	 break;
      case 3: /* Tris */
	 printf("This is tris of %ss!\n", wFace[face]);

	 points = P_TRIS + face;
	 break;
      case 4: /* Scale */
	 printf("Yeah, you have done a scale to %s\n", wFace[face]);

	 points = P_SCALE + face;
	 break;
      case 5: /* Full */
	 printf("*** FULL of %ss!\n", wFace[face]);

	 points = P_FULL + face;
	 break;
      case 6: /* Poker */
	 printf("Wow, it's Poker of %ss!\n", wFace[face]);

	 points = P_POKER + face;
	 break;
      case 7: /* Color */
	 printf("%d points of color (%s)\n", P_COLOR, wSuit[suit]);

	 points = P_COLOR + face;
	 break;
      case 8: /* Straight flush */
	 printf("* Straight flush to %s*\n", wFace[face]);

	 points = P_SFLUSH + face;
	 break;
      case 9: /* Royal flush */
	 printf("*| Royal Flush (%s) |*\n", wSuit[suit]);

	 points = P_RFLUSH + face;
	 break;
      default: /* (?) */
	 printf("### error in function getp()\n");
	 exit(-1);

   } /* end switch(kind) */

   if(!face) points += 13; /* add the Ace's points */

   return points + 1; /* + 1 == [1,13] rather then [0,12] */
} /* eof getp() */

/* Order an array in descending mode */
void order(int a[][CARDS][2], int p, int size)
{
   int i, hold;

   for(i = 1; i < size; i++) {
      if(a[p][i - 1][0] > a[p][i][0]) {
	 /* swap the face */
	 hold = a[p][i][0];
	 a[p][i][0] = a[p][i - 1][0];
	 a[p][i - 1][0] = hold;

	 /* swap the suit */
	 hold = a[p][i][1];
	 a[p][i][1] = a[p][i - 1][1];
	 a[p][i - 1][1] = hold;
      }
   } /* end for (i) */

} /* eof order() */

/* Change the cards if needed, else return 0 */
int chcs(int cards[][CARDS][2], int player, int type[], const char *wFace[],
         const char *wSuit[], int wDeck[][13], int n_cards) 
{
   int i, ret;

   switch(type[player]) {
      case 9: /* Royal flush */
      case 8: /* Straight flush */

	 ret = 0;
	 break;
      case 7: /* Color */
	 /* Try to do a Royal flush */
	 ret = 0;

	 for(i = 0; i < n_cards; i++) {
	    if(cards[player][i][0] + 1 == cards[player][i + 1][0]) {
	       ++ret;
	    }
	 }

         /* if miss only a card to Royal Flush */
	 if(ret == 3) {
	    /* risk: change one card */

	    if(cards[player][0][0] + 1 == cards[player][1][0]) {
	       rswap(&cards[player][0][0], &cards[player][n_cards - 1][0]);
	       rswap(&cards[player][0][1], &cards[player][n_cards - 1][1]);
	    }

	    ret = 1;
	 }
	 else /* do nothing */
	    ret = 0;

         break;

      case 5: /* Full */
      case 4: /* Scale */

	 /* Stay */
	 ret = 0;

	 break;

      case 6: /* Poker */

         /* cards is ordered so the "intruder"
	  * have to be at begin or at end */

	 if(cards[n_cards - 1][0] != cards[2][0]) {

	    /* copy [0] to [n_cards - 1] */

	    /* the face */
	    rswap(&cards[player][n_cards - 1][0], &cards[player][0][0]);

	    /* the suit */
	    rswap(&cards[player][n_cards - 1][1], &cards[player][0][1]);
	 }

	 /* else cards[player][n_cards - 1][0] <=> cards[player][2][0] */
	  
	 /* and insert a new card on [0] */
	 deal( wDeck, wFace, wSuit, cards, player, 1, 2);

         ret = 1;
	 break;
      case 2: /* Double */
	 /* change 1 card */

         /* cards is ordered so the "intruder"
	  * have to be at begin or at end */

	  if(cards[player][n_cards - 1][0] != cards[player][5][1] &&
	     cards[player][n_cards - 1][0] != cards[player][3][0]) {

		/* the face */
		rswap(&cards[player][n_cards - 1][0], &cards[player][0][0]);

		/* the suit */
		rswap(&cards[player][n_cards - 1][1], &cards[player][0][1]);
	  }

	  /* else cards[0][0] is already free */
	 deal( wDeck, wFace, wSuit, cards, player, 1, 2);

	 ret = 1;
	 break;
      case 3: /* Tris */
         /* change 2 cards */

	 /* cards is ordered so the "intruderS"
	  * DON'T have to be at middle */

	 for(i = 0; i < n_cards / 2; i++) {
	    if(cards[i][0] == cards[2][0])
	    break;
	 }

	 if(!i) {
	    /* the face */
	    rswap(&cards[player][n_cards - 1][0], &cards[player][0][0]);
	    rswap(&cards[player][n_cards - 2][0], &cards[player][1][0]);

            /* the suit */
	    rswap(&cards[player][n_cards - 1][1], &cards[player][0][1]);
	    rswap(&cards[player][n_cards - 2][1], &cards[player][1][1]);
	 }
	 else if(i == 1) {
	    /* the face */
	    rswap(&cards[player][n_cards - 1][0], &cards[player][2][0]);

	    /* the suit */
	    rswap(&cards[player][n_cards - 1][1], &cards[player][2][1]);
	 }

         /* insert 2 cards on [0] and [1] */
	 deal( wDeck, wFace, wSuit, cards, player, 2, 2);

	 ret = 2;
	 break;
      case 1: /* Pair */
	 /* change 3 cards */

	 for(i = 0; i < n_cards; i++) {
	    if(cards[player][i][0] == cards[player][i + 1][0])
	       break;
	 }


	 /* The face */
	 rswap(&cards[player][n_cards - 1][0], &cards[player][i][0]);
	 rswap(&cards[player][n_cards - 2][0], &cards[player][i+1][0]);

         /* The suit */
         rswap(&cards[player][n_cards - 1][1], &cards[player][i][1]);
	 rswap(&cards[player][n_cards - 2][1], &cards[player][i+1][1]);

         deal( wDeck, wFace, wSuit, cards, player, 3, 2);

	 ret = 3;
	 break;
      case 0: /* Nothing */
	 /* Change all cards */
	 ret = 0;

	 /* If i have a Jack, a Queen, a King or an Ace, hold it */
	 for(i = 0; i < n_cards; i++) {
	    /* 9 == Ten */
	    if( (!cards[player][i][0] ? 13 : cards[player][i][0]) > 9 &&
		(!cards[player][i][0] ? 13 : cards[player][i][0]) > ret) {
		    ret = (!cards[player][i][0] ? 13 : cards[player][i][0]);

		    rswap(&cards[player][0][0], &cards[player][i][0]);
		    rswap(&cards[player][0][1], &cards[player][i][1]);
	    }
	 }
	 rswap(&cards[player][0][0], &cards[player][n_cards - 1][0]);
	 rswap(&cards[player][0][1], &cards[player][n_cards - 1][1]);

	 /* else change all cards */

         if(!ret) {
	    deal( wDeck, wFace, wSuit, cards, player, n_cards, 2);
	    ret = n_cards;
	 }
	 else {
	    deal( wDeck, wFace, wSuit, cards, player, n_cards - 1, 2);
	    ret = n_cards - 1;
	 }

	 break;
      default: /* (?) */
	 printf("### error in function chcs()\n");
	 exit(-1);

   } /* end switch (type[player]) */


   if(ret)
      printf("Computer has changed %d %s.\n\n",
	 ret, ret > 1 ? "cards" : "card" );

   return ret;
} /* eof chcs() */

/* Swap two variable for reference */
void rswap(int *a, int *b)
{
   int hold;

   hold = *a;
   *a = *b;
   *b = hold;
} /* eof rswap() */

