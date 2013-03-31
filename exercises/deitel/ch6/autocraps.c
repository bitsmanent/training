/* Exercise 6.20 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { CONTINUE, WON, LOST };

int rollDice(void);
int play(void);

int main()
{
   int i;
   int c[2] = { 0 };

   srand( time(NULL) );
   printf("Runs\tWIN\tLOST\n");
   for(i = 1; i <= 1000; i++) {
      ++c[play() - 1];
      printf("%d\t%d\t%d\n", i, c[0], c[1]);
   }

   printf("Total wins: %d\nTotal loses: %d\n", c[0], c[1]);

   return 0;
} /* E0F main */

/* play a time */
int play(void) {
   int sum, myPoint;

   enum Status gameStatus;

   //srand( time(NULL) );

   sum = rollDice();

   switch(sum) {
      case 7:
      case 11:
	 gameStatus = WON;
	 break;
      case 2:
      case 3:
      case 12:
	 gameStatus = LOST;
	 break;
      default:
	 gameStatus = CONTINUE;
	 myPoint = sum;
	 break; /* optional */
   } /* end switch (sum) */

   while(gameStatus == CONTINUE) {
      sum = rollDice();

      if(sum == myPoint)
	 gameStatus = WON;
      else
	 if(sum == 7)
	    gameStatus = LOST;

   } /* end while (gameStatus) */

   if(gameStatus == WON) {
      return WON;
   }
   else {
      return LOST;
   }

} /* eof play() */

/* launch the dice, calculate the sum and print results */
int rollDice(void) {
   int die1, die2;
   int workSum;

   die1 = 1 + rand() % 6;
   die2 = 1 + rand() % 6;
   workSum = die1 + die2;

   return workSum;
} /* end rollDice() */

