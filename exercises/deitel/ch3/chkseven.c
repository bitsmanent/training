/*
 * Esercizio 3.39
 * Conta le occorrenze dei numeri '7' di un intero
*/

#include <stdio.h>

int main()
{
   int num, tot = 0; /* Numero inserito e totale */
   int i = 1;

   printf("Dammi un intero: ");
   scanf("%d", &num);

   while(i <= 10000) {
      if (num / i % 10 == 7)
         ++tot;
      i *= 10;
   }

   printf("Sono state trovate %d occorrenze\n", tot);

   return 0;
} /* E0F main */

