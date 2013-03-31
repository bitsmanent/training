/* Esercizio 3.24 (Cap. 3)
 *
 * Trovo il più grande tra una serie di numeri
*/

#include <stdio.h>

int main()
{
   int counter = 1, largest = 0, number;

   while(counter <= 10) {
      printf("Inserisci un numero [%d di 10]: ", counter);
      scanf("%d", &number);

      if (number > largest)
	 largest = number;

      ++counter;
   }

   printf("Il numero più grande è %d\n", largest);

   return 0;
} /* E0F main */
