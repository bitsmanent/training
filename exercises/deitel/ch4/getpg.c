/*
 * Esercizio 4.26
 * pi = 4 - (4 / 3) + (4 / 5) - (4 / 7) + (4 / 9) - (4 / 11) + ...
*/

#include <stdio.h>

int main()
{
   double pi = 4.0;
   int i, t = 1;

   printf("PI VALUE\t(+/-) 4 / X\tTERMS\n");
   for (i = 3; pi > 3.141593; ++t, i += 2) {
      pi -= 4.0 / i;
      i += 2;
      pi += 4.0 / i;
   }

   printf("%f\t4 / %d\t%d\n", pi, i, t);

   return 0;
} /* E0F main */

