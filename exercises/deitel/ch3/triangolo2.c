/*
 * Esercizio 3.45
 * Dati 3 interi diversi da 0 determino se questi possono
 * rappresentare i lati di un triangolo rettangolo.
*/

#include <stdio.h>

int main()
{
   int cat1, cat2, cat3;
   int valid = 0;

   printf("Inserire il valori [n n n]: ");
   scanf("%d%d%d", &cat1, &cat2, &cat3);

   /* Riassunto (non usare)
    * if (a*a == c*c - b*b && b*b == c*c - a*a && c*c == a*a + b*b)
   */

   /* Controllo il cateto 1 */
   if (cat1 != 0) {
      if (cat1 * cat1 == cat3 * cat3 - cat2 * cat2)
         ++valid; 
   }

   /* Controllo il cateto 2 */
   if (cat2 != 0) {
      if (cat2 * cat2 == cat3 * cat3 - cat1 * cat1)
	 ++valid;
   }

   if (cat3 != 0) {
      if (cat3 * cat3 == cat1*cat1 + cat2*cat2)
	 ++valid;
   }

   if (valid == 3)
      printf("Valori validi: %d, %d e %d\n", cat1, cat2, cat3);
   else
      printf("Valori NON validi: %d, %d e %d\n", cat1, cat2, cat3);

   return 0;
} /* E0F main */

