/* Exercise 5.35 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num, gnum;

   while(gnum = 1 + rand() % 1000) {
      printf("\nI have a number between 1 and 1000.\n");
      printf("Can you guess my number?\n");
      printf("Please type your first guess.\n");
      scanf("%d", &num);

      while(num != gnum) {
         if(num < gnum)
            printf("Too low. Try again.\n");
         else
            printf("Too high. Try again.\n");

         scanf("%d", &num); /* try again */
      } /* end while */

      printf("\nExcellent! you guessed the number!\n");
      printf("Would you like to play again (y or n)?\n");

      getchar(); /* take newline and, of course, ignore it */

      if(getchar() == 'n')
	 break;
   } /* end while */

   return 0;
} /* E0F main */

