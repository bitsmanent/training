/* Esercizio 3.34 
 *
 * Dato il lato disegna un quadrato di asterischi, vuoto.
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
	 if (x == 0)
	    printf("*");
	 else if (x == lato - 1)
	    printf("*");
	 else {
	    if (y == 0) /* se è il primo asterisco.. */
	       printf("*"); /* ..mostralo */
	    else if ( y == lato - 1) /* se è l'ultimo.. */
	       printf("*"); /* ..pure */ 
	    else printf(" "); /* altrimenti mostra uno spazio */
         }
	 ++y;
      }
      printf("\n");
      ++x;
   }

   return 0;
} /* E0F main */
