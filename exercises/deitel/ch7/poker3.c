/* Exercise 7.16 */

/* Fig. 7.24: fig07_24.c
   Card shuffling dealing program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 5

/* Points setting *
 * NOTE: the points *must* have an offset >= 15 and P_PAIR
 *       must should be >= 15 too to works properly. Else,
 *	 the game will sh0w only INVALID results and wrong
 *	 winners.
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
         const char *wSuit[], int n_cards, int *r_suit, int *r_face,
	 int type[], int show);

void order(int a[][CARDS][2], int p, int size);
void rswap(int *a, int *b);

int chcs(int cards[][CARDS][2], int player, int type[], const char *wFace[], 
         const char *wSuit[], int wDeck[][13], int n_cards);

int chch(int cards[][CARDS][2], int n_cards, int player, int wDeck[][13],
         const char *wFace[], const char *wSuit[], int kind, 
	 int r_face, int r_suit, int show);

void p_points(int kind, int face, int suit,
              const char *wFace[], const char *wSuit[], int show);

int main(void)
{
   int i, type[2], winner[3] = { 0 }, points[2] = { 0 };
   int p[2][2] = { { 0 } };
   int cards[2][CARDS][2] = { { { 0 } } };
   int c; /* change tracer */
   int theface[2], thesuit;

   /* initialize suit array */
   const char *suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades" };
   
   /* initialize face array */
   const char *face[ 13 ] = 
      { "Ace", "Deuce", "Three", "Four", 
        "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" };

   /* initialize deck array */
   int deck[ 4 ][ 13 ] = {
      { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 },
      { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 },
      { 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39 },
      { 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52 }
   };


   if(CARDS > 52 / 2) {
      printf("Too many cards: redefine the CARDS constant.\n");
      exit(-1);
   }

   srand( time( 0 ) ); /* seed random-number generator */

   shuffle( deck );

   /* S t a r t */
   printf("GaMe STaRTeD! (%d cards for player)\n\n", CARDS);

   for(i = 0; i < 2; i++) {
      printf("*** ");
      if(!i)
	 printf("Computer");
      else
	 printf("Player %d", i);

      printf("'s cards..\n");

      printf("-----------------------------------------\n\n");

      deal( deck, face, suit, cards, i, CARDS, !i ? 0 : 1 );

      /* p[i][0] == points
       * p[i][1] == suit of highest card (whitin the highest kind)
       * i == the player
       * p[0][?] == the computer 
       */
      if(i) printf("\n");
      p[i][0] = getp(cards, i, face, suit, CARDS, &p[i][1],
		     &theface[i], &type[i], i);

      if(i) {
         thesuit = p[1][1]; /* take the user's suit */

         printf("\n: Score: %d ", p[i][0]);
	 printf("(suit points reserved: %d)", 4 - p[i][1]);
      }

      printf("\n-----------------------------------------\n");

      /* so */
      points[i] = p[i][0] - p[i][1]; /* points - seed(0 highest, 3 lowest) */
      printf("\n\n");
   }

   printf("Now is time to change the cards..\n");
   printf("Press a key to continue.\n");
   getchar(); 

   /* Player change the cards */
   c = chch(cards, CARDS, 1, deck, face, suit, type[1],
	    theface[1], thesuit, 1);
   if(c) {
      printf("Player 1 has changed %d %s.\n\n", c, c > 1 ? "cards" : "card" );

      p[1][0] = getp(cards, 1, face, suit, CARDS, &p[1][1],
		     &theface[1], &type[1], 1);
   }

   /* Computer change the cards */
   c = chcs(cards, 0, &type[0], face, suit, deck, CARDS);
   if(c) {
      printf("Computer has changed %d %s.\n\n", c, c > 1 ? "cards" : "card" );

      p[0][0] = getp(cards, 0, face, suit, CARDS,
		     &p[0][1], &theface[0], &type[0], 0);
   }

   printf("\n\n");


   /* F i n i s h */

   /* Check the winner and print the classifies */
   for(i = 0; i < 2; i++) {
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

   printf("Press a key to know the winner\n"
	  "or type ^C if you have fear :-)\n");

   getchar(); getchar();
   printf("\n");

   /* Show the cards */
   for(i = 1; i >= 0; i--) {
      if(!i)
	 printf("Computer");
      else
	 printf("Player 1");
      printf("'s cards:\n");

      printf("-------------------------------");
      printf("-----------------------------\n");

      for(c = 0; c < CARDS; c++) {
         printf("%15s of %-8s", face[cards[i][c][0]], suit[cards[i][c][1]]);
         printf("%c", !(c % 2) ? '\n' : '\t');
      }

      printf("\n\n");
      p_points(type[i], theface[i], p[i][1], face, suit, 1);

      printf("\n\tTotal points: %d (suit %d)\n", p[i][0], p[i][1]);
      printf("-------------------------------");
      printf("-----------------------------\n");
      printf("\n\n");
   }


   printf("\n\tC l a s s i f i e s\n\n");

   printf("%16s%9s\n", "Player", "Points");
   printf("%16s%9d\n", "PC", p[0][0]);
   printf("%16d%9d\n", 1, p[1][0]);

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
   int row;
   int column;

   for(row = 0; row < 4; row++) {
      for(column = 0; column < 13; column++) {
	 rswap(&wDeck[row][column], &wDeck[rand() % 4][rand() % 13]); 
      }
   }

} /* end function shuffle */

/* deal cards in deck */
void deal( int wDeck[][ 13 ], const char *wFace[], const char *wSuit[],
           int cards[][CARDS][2], int player, int wCards, int show)
{
   int card;   /* card counter */
   int row;    /* row counter */
   int column; /* column counter */
   int i = 0, found;

   if(show == 2) {
      printf("\n\n===> ");
      if(!player)
	 printf("Computer");
      else
	 printf("Player %d", player);

      printf(" is changing cards..\n\n");
   }

   /* deal each of the 52 cards */
   for ( card = 1; card <= 52; card++ ) {
      found = 0; /* found the card? :-) */

      /* loop through rows of wDeck */
      for ( row = 0; row <= 3 && !found; row++ ) {

         /* loop through columns of wDeck for current row */
         for ( column = 0; column <= 12 && !found; column++ ) {
            /* if slot contains current card, display card */
            if ( wDeck[ row ][ column ] == card ) {

	       if(show == 2) {
		  if(!player) {
		     printf("\tHIDDEN => ");
		  }
		  else {
		     printf( "%5s of %-8s => ", wFace[cards[player][i][0]],
	                wSuit[cards[player][i][1]]);
		  }
	       }

               cards[player][i][0] = column;
	       cards[player][i][1] = row;

	       if(!show)
	          printf("\tHIDDEN");
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

	       found = 1;


            } /* end if */

         } /* end for */

      } /* end for */

   } /* end for */

} /* end function deal */

/* Get the points of a player */
int getp(int cards[][CARDS][2], int player, const char *wFace[],
         const char *wSuit[], int n_cards, int *r_suit, int *r_face,
         int *type, int show)
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

      if( o[i][0] > 1 && (kind != 2 || (kind == 2 &&
	  (!face ? 13 : face) < (!i ? 13 : i) )) ) {

	 /* If is double and the current pair is less
	  * then previous, i don't store its face/suit */

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
   *r_face = face;
   *type = kind;

   /* Assign the points */
   switch(kind) {
      case 0: /* Nothing */

	 points = face;
	 break;
      case 1: /* Pair */

	 points = P_PAIR + face;
	 break;
      case 2: /* Double */

	 points = P_DOUBLE + face;
	 break;
      case 3: /* Tris */

	 points = P_TRIS + face;
	 break;
      case 4: /* Scale */

	 points = P_SCALE + face;
	 break;
      case 5: /* Full */

	 points = P_FULL + face;
	 break;
      case 6: /* Poker */

	 points = P_POKER + face;
	 break;
      case 7: /* Color */

	 points = P_COLOR + face;
	 break;
      case 8: /* Straight flush */

	 points = P_SFLUSH + face;
	 break;
      case 9: /* Royal flush */

	 points = P_RFLUSH + face;
	 break;
      default: /* (?) */
	 printf("### error in function getp()\n");
	 exit(-1);

   } /* end switch(kind) */

   /* Notice the points to the user */
   p_points(kind, face, suit, wFace, wSuit, show);

   if(!face) points += 13; /* add the Ace's points */

   return points + 1; /* + 1 == [1,13] rather then [0,12] */
} /* eof getp() */

/* Order an array in descending mode */
void order(int a[][CARDS][2], int p, int size)
{
   int i;

   for(i = 1; i < size; i++) {
      if(a[p][i - 1][0] > a[p][i][0]) {
	 /* swap the face */
	 rswap(&a[p][i][0], &a[p][i - 1][0]);

	 /* swap the suit */
	 rswap(&a[p][i][1], &a[p][i - 1][1]);
      }
   } /* end for (i) */

} /* eof order() */

/* Change the card (without user interaction) */
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
	 /* Change a card */
         ret = 1;

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
	 deal( wDeck, wFace, wSuit, cards, player, ret, 2);

	 break;
      case 2: /* Double */
	 /* change 1 card */
	 ret = 1;

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
	 deal( wDeck, wFace, wSuit, cards, player, ret, 2);

	 break;
      case 3: /* Tris */
         /* change 2 cards */
	 ret = 2;

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
	 deal( wDeck, wFace, wSuit, cards, player, ret, 2);

	 break;
      case 1: /* Pair */
	 /* change 3 cards */
	 ret = 3;

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

         deal( wDeck, wFace, wSuit, cards, player, ret, 2);

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

         if(!ret)
	    ret = n_cards;
	 else
	    ret = n_cards - 1;

	 deal( wDeck, wFace, wSuit, cards, player, ret, 2);

	 break;
      default: /* (?) */
	 printf("### error in function chcs()\n");
	 exit(-1);

   } /* end switch (type[player]) */

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

/* Change the cards (with user interaction) */
int chch(int cards[][CARDS][2], int n_cards, int player, int wDeck[][13],
         const char *wFace[], const char *wSuit[], int kind, 
	 int r_face, int r_suit, int show)
{
   int i, j, ret = 0;
   int changes[CARDS] = { 0 };

   while(ret != EOF) {

      printf("\n\n\t\t..:: CHANGING THE CARDS ::..\n");

      /* Check if something is changed.. */
      for(i = 0, ret = 0; i < n_cards; i++) {
	 if(changes[i]) {
	    ++ret;
	 }
      }

      if(ret) { /* ..if yes show it.. */

         printf("\nHeld cards:\n\n");
         for(i = 0, ret = 0; i < n_cards; i++) {
	    if(changes[i]) {

               printf( "\t[%d] %5s of %-8s", i, 
	          wFace[cards[player][i][0]], wSuit[cards[player][i][1]]);
               printf("%c", !(++ret % 2) ? '\n' : '\t');

	    }
         }
         printf("\n\n");

      }
      else {
         /* ..else do nothing. */
	 printf("\n\n===> No held cards!\n\n");
      }

      if(ret == n_cards) {
	 printf("You are holding all cards!\n\n\n");
      }
      else {
         printf("\nYour current cards are:\n\n");
         for(i = 0, ret = 0; i < n_cards; i++) {
	    if(!changes[i]) {
               printf( "\t[%d] %5s of %-8s", i, 
	          wFace[cards[player][i][0]], wSuit[cards[player][i][1]]);
               printf("%c", !(++ret % 2) ? '\t' : '\n');
	    }

         }
	 printf("\n\n");
      }

      p_points(kind, r_face, r_suit, wFace, wSuit, show);

      while(ret != EOF) {

         printf("\n\n");
         printf("What card(s) you would to hold? (%d to confirm)\n"
		"Selection: ", EOF);

         scanf("%d", &ret);

	 if( (ret >= 0 && ret < n_cards) || ret == EOF)
	    break;

	 else {
	    printf("\nInvalid selection.");
	    continue;
	 }
      }

      if(ret != EOF) {
         /* If is selected, then unselect else select */
         changes[ret] = !changes[ret] ? 1 : 0;
      }

   } /* end while (ret) */

   /* count the cards that will be changed (ret) */
   for(i = 0, ret = 0; i < n_cards; i++) {
      if(!changes[i])
	 ++ret;
   }

   /* put the card to change at begin of the array */
   for(i = 0; i < n_cards; i++) {
      if(changes[i]) {
	 for(j = n_cards - 1; j > i; j--) {
	    if(!changes[j]) {
	       rswap(&cards[player][i][0], &cards[player][j][0]);
	       rswap(&cards[player][i][1], &cards[player][j][1]);
	    }
	 }
      }
   } /* end for (i) */

   if(ret) deal( wDeck, wFace, wSuit, cards, player, ret, 2);

   return ret;
} /* eof chch() */

/* Print a message(s) (the points) basing on the "kind" */
void p_points(int kind, int face, int suit,
              const char *wFace[], const char *wSuit[], int show)
{
   if(show) printf(": ");

   switch(kind) {
      case 0: /* Nothing */
         if(show)
            printf("All cards are differents!\n"
                   ": You could win with the %s of %s\n",
                      wFace[face], wSuit[suit]);

         break;
      case 1: /* Pair */
         if(show)
            printf("Oh, it is a pair of %ss!\n", wFace[face]);

         break;
      case 2: /* Double */
         if(show)
            printf("Double to %ss\n", wFace[face]);

         break;
      case 3: /* Tris */
         if(show)
            printf("This is tris of %ss!\n", wFace[face]);

         break;
      case 4: /* Scale */
         if(show)
            printf("Yeah, you have done a scale to %s\n", wFace[face]);

         break;
      case 5: /* Full */
         if(show)
            printf("*** FULL of %ss!\n", wFace[face]);

         break;
      case 6: /* Poker */
         if(show)
            printf("Wow, it's Poker of %ss!\n", wFace[face]);

         break;
      case 7: /* Color */
         if(show)
            printf("%d points of color (%s)\n", P_COLOR, wSuit[suit]);

         break;
      case 8: /* Straight flush */
         if(show)
            printf("* Straight flush to %s*\n", wFace[face]);

         break;
      case 9: /* Royal flush */
         if(show)
            printf("*| Royal Flush (%s) |*\n", wSuit[suit]);

         break;
      default: /* (?) */
         printf("### error in function p_points()\n");
         exit(-1);

   } /* end switch(kind) */

} /* eof p_points() */

