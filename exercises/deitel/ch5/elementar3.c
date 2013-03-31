/* Exercise 5.34 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int n1, n2;
   int num, i = 0;

   int correct = 0;

   for(i = 1; i <= 10; i++) {
      srand( time(NULL) );

      n1 = 1 + rand() % 9;
      n2 = 1 + rand() % 9;

      printf("How much is %d times %d?\n", n1, n2);
      printf("Answer: ");
      scanf("%d", &num);

      printf("\n");
      if(num == n1 * n2) {
	 switch(1 + rand() % 4) {
	    case 1:
	       printf("Very good!");
	       break;
	    case 2:
	       printf("Excellent!");
	       break;
	    case 3:
	       printf("Nice work!");
	       break;
	    case 4:
	       printf("Keep up the good work!");
	 }
	 ++correct;
      }
      else
	 switch(1 + rand() % 4) {
	    case 1:
	       printf("No. Please try again.");
	       break;
	    case 2:
	       printf("Wrong. Try one more.");
	       break;
	    case 3:
	       printf("Don't give up!");
	       break;
	    case 4:
	       printf("No. Keep trying.");
	 } /* end switch */

      printf("\n\n");
   } /* end for (i) */


   if( (100 * correct) / 10 < 75)
      printf("Please ask your instructor for extra help\n");

   printf("Game over!\n");

   return 0;
} /* E0F main */

