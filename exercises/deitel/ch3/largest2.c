/* Esercizio 3.27 
 *
 * Trova i 2 numeri maggiori tra 10 numeri
*/

#include <stdio.h>

int main()
{
   int largest = 0, largest2 = 0, counter = 1, number;

   while(counter <= 10) {
      printf("Dammi un numero [%d di 10]: ", counter);
      scanf("%d", &number);

      if (number > largest2) {
	 if (number > largest) {
	    largest2 = largest;
	    largest = number;
	 }
	 else largest2 = number;
      }

      ++counter;
   }

   printf("I 2 presunti largest sono %d e %d\n", largest2, largest);

   return 0;
} /* E0F main */

