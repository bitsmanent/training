/* Esercizio 4.11 */

#include <stdio.h>

int main()
{
   int i, small;
   int c_val;

   printf("Intero: ");
   scanf("%d", &c_val);

   for (i = c_val; i >= 1; --i) {
      printf("Intero: ");
      scanf("%d", &c_val);

      if (small > c_val)
	 small = c_val;
   }

   printf("Smallest: %d\n", small);

   return 0;
} /* E0F main */

