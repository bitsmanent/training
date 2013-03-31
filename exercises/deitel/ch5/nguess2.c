/* Exercise 5.36 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num, gnum;
   int tests;

   while(gnum = 1 + rand() % 1000) {
      printf("\nI have a number between 1 and 1000.\n");
      printf("Can you guess my number?\n");
      printf("Please type your first guess.\n");
      scanf("%d", &num);

      tests = 1;
      while(num != gnum) {
	 ++tests;
         if(num < gnum)
            printf("Too low. Try again.\n");
         else
            printf("Too high. Try again.\n");

         scanf("%d", &num); /* try again */
      } /* end while */

      if(tests == 10)
	 printf("Ahah! You know the secret!\n");
      else if(tests < 10)
	 printf("Either you know the secret or you go lucky!\n");
      else
	 printf("You should be able to do better!\n");

      printf("Would you like to play again (y or n)?\n");

      getchar(); /* take newline and, of course, ignore it */

      if(getchar() == 'n') /* not so strict :-) */
	 break;

   } /* end while */

   return 0;
} /* E0F main */

