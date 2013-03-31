/* Esercizio 4.15 */

#include <stdio.h>
#include <math.h>

int main()
{
   int amount;
   int principal = 1000;
   double rate = 0.5;
   int year, rest, rest2;

   printf("%4s%21s\n", "Year", "Amount of deposit");
   for (year = 1; year <= 10; year++) {

      amount = principal * pow(1 + rate, year); 
      rest = rest2 = principal * pow(1 + rate, year) * 100;
      rest = (int) rest / 10 % 10; 
      rest2 = (int) rest2 % 10; 

      printf("%4d%18d.%d%d\n", year, amount, rest, rest2);
   }

   return 0;
} /* E0F main */

