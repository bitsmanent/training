/*
 * Esercizio 3.36
 * Convertitore di numeri: da binario a decimale.
*/

#include <stdio.h>

int main()
{
   int num, i = 1;

   printf("Numero binario: ");
   scanf("%d", &num);

   if (num > 9999)
      printf("Sono ammessi solo valori a 4 cifre!\n");
   else {
      while(i <= 1000) {
         if (num / i % 10 != 1)
            if (num / i % 10 != 0) { 
	       printf("Sono ammessi solo numeri binari!\n");
	       break;
	    }

         i *= 10;
      }
   }

   if (i > 1000) {
      printf("Numero decimale: %d\n",
         (num % 10) + (num / 10 % 10) * 2
         + (num / 100 % 10) * 4 + (num / 1000 % 10) * 8);
   }

   return 0;
} /* E0F main */

