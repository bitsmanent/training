/* Esercizio 3.5 (Cap 3)
   Calcola la somma degli interi da 1 a 10 */

#include <stdio.h>

int main()
{
   int sum = 0, x = 1; /* Inizializzo le variabili */

   while(x <= 10) {
      sum += x;
      x++;
   }

   /* Stampo i risultati */
   printf("The sum is: %d\n", sum);

   return 0;
} /* E0F main */

