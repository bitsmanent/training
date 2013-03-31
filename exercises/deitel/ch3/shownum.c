/* Esercizio 3.23 (Cap. 3);
 *
 * Stampa i numeri da 1 a 10 uno a fianco
 * all'altro con 3 spazi tra ognuno.
*/

#include <stdio.h>

int main()
{
   int i = 1;
   while(i <= 10) {
      printf("%d   ", i);
      ++i;
   }
   printf("\n");

   return 0;
} /* E0F main */

