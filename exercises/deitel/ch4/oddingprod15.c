/* Esercizio 4.13 */

#include <stdio.h>

int main()
{
   int i, product = 1;

   for (i = 1; i <= 15; i += 2) {
      if (i % 2) /* never used */
	 product += i;
   }

   printf("Product of all integers from 1 to 15 is %d\n", product);

   return 0;
} /* E0F main */

