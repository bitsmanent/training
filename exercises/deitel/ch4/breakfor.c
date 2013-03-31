/* Esercizio 4.37 */

#include <stdio.h>

int main()
{
   int x, i;

   for(x = 1; x <= 10; x++) {

      if (x == 5) {
	 i = x;
	 x = 11;
      }
      else
         printf("%d ", x);

   } /* end for (x) */

   printf("\nBroke out of loop at x == %d\n", i);

   return 0;
} /* E0F main */

