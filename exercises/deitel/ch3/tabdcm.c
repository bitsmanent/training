/* Esercizio 3.25 (Cap. 3)
 *
 * Stampa una tabella con i numeri da 1
 * a 10 moltiplicati per 10, 100 e 100.
*/

#include <stdio.h>

int main()
{
   int i=1;

   printf("N\t10*N\t100*N\t1000*N\n\n");
   while(i <= 10) {
      printf("%d\t%d\t%d\t%d\n", i, 10*i, 100*i, 1000*i);
      ++i;
   }

   return 0;
} /* E0F main */

