/* Esercizio 4.12 */

#include <stdio.h>

int main()
{
   int i;
   int sum = 0;

   for (i = 2; i <= 30; i += 2) {
      if (! (i % 2))
         printf("%d ", i);
   }

   printf("\n");
   return 0;
} /* E0F main */

