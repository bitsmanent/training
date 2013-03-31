/* Esercizio 5.10 */

#include <stdio.h>
#include <math.h>

int main()
{
   double num = 1;

   while(num * 100 / 100) {
      printf("%.2f is now %.0f\n", num, floor( num ));

      printf("Give me a number (0 to end): ");
      scanf("%lf", &num);
   } /* end while (num) */

   return 0;
} /* E0F main */

