/*
 * Esercizio 3.38
 * Visualizza 100 asterischi uno per volta.
*/

#include <stdio.h>

int main()
{
   int i = 1;

   while(i <= 100) {
      printf("*");
      if (i % 10 == 0)
	 printf("\n");
      ++i;
   }

   return 0;
} /* E0F main */

