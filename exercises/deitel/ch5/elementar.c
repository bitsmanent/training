/* Exercise 5.32 */

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
	 printf("Very good!");
	 n1 = 1 + rand() % 9;
	 n2 = 1 + rand() % 9;
      }
      else
	 printf("No. Please try again.");
      printf("\n\n");
   } /* end while (num) */

   return 0;
} /* E0F main */

