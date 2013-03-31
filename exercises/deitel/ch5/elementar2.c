/* Exercise 5.33 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int n1 = 1 + rand() % 9;
   int n2 = 1 + rand() % 9;
   int num;


   while(1) {
      srand( time(NULL) );

      printf("How much is %d times %d?\n", n1, n2);
      printf("Answer (%d to end): ", EOF);
      scanf("%d", &num);

      if(num == EOF)
	 break;

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
	 n1 = 1 + rand() % 9;
	 n2 = 1 + rand() % 9;
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
   } /* end while (num) */

   return 0;
} /* E0F main */

