/* Esercizio 4.15 */

#include <stdio.h>
#include <math.h>

int main()
{
   double amount;
   double principal = 1000.0;
   double rate = 0.5;
   int year, r;

   for (r = 5; r <= 10 ; rate += 0.1, ++r) {
      
      printf("\n%4s%21s [%d%%]\n", "Year", "Amount of deposit", r);
      for (year = 1; year <= 10; year++) {

         amount = principal * pow(1.0 + rate, year);

         printf("%4d%21.2f\n", year, amount);
      }
   }

   return 0;
} /* E0F main */

