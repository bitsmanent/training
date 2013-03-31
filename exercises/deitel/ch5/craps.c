/* Exercise 5.51 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { CONTINUE, WON, LOST };

int rollDice(void);
int play(void);

int main()
{
   int bankBalance = 1000, wager;

   while(bankBalance) {

      do {
         printf("Bank balance: $%d\n", bankBalance);
         printf("Enter your wager: ");
         scanf("%d", &wager);
      } while(wager > bankBalance || wager <= 0);

      if(play() == WON)
         bankBalance += wager;
      else
         bankBalance -= wager;
   }

   printf("Bank balance: $0\n");

   return 0;
} /* E0F main */

/* play a time */
int play(void) {
   int sum, myPoint;

   enum Status gameStatus;

   srand( time(NULL) );

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
	 printf("Point is %d\n", myPoint);
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
      printf("Player wins\n");
      return WON;
   }
   else {
      printf("Player loses\n");
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

   printf("Player rolled %d + %d = %d\n", die1, die2, workSum);

   return workSum;
} /* end rollDice() */

