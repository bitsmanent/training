/* Esercizio 3.33 
 *
 * Dato il lato disegna un quadrato di asterischi
*/

#include <stdio.h>

int main()
{
   int lato, y, x = 0;

   printf("Dammi un lato del quadrato: ");
   scanf("%d", &lato);

   if (lato < 1) {
      printf("Usare i numeri da 1 a 20\n");
   }

   while(x < lato) {
      if (lato > 20) {
	 printf("Usare i numeri da 1 a 20\n");
	 break;
      }

      y = 0;
      while(y < lato) {
	 printf("*");
	 ++y;
      }
      printf("\n");
      ++x;
   }

   return 0;
} /* E0F main */
