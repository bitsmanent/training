/*
 * Esercizio 3.44
 * Dati 3 float diversi da 0 determino se questi
 * possono rappresentare i lati di un triangolo.
*/

#include <stdio.h>

int main()
{
   float cat1, cat2, cat3;
   int valid = 0;

   printf("Inserire il valori [n n n]: ");
   scanf("%f%f%f", &cat1, &cat2, &cat3);

   /* Controllo il cateto 1 */
   if (cat1 != 0) {
      if (cat1 < cat2 + cat3) {
         if (cat2 > cat3) {
	    if (cat1 > cat2 - cat3)
	       ++valid;
         }
         else if (cat1 > cat3 - cat2)
	    ++valid;
      }
   }

   /* Controllo il cateto 2 */
   if (cat2 != 0) {
      if (cat2 < cat1 + cat3) {
         if (cat1 > cat3) {
	    if (cat2 > cat1 - cat3)
	       ++valid;
         }
         else if (cat1 > cat3 - cat1)
	    ++valid;
      }
   }

   /* Controllo il cateto 3 */
   if (cat3 != 0) {
      if (cat3 < cat1 + cat2) {
         if (cat1 > cat2) {
	    if (cat3 > cat1 - cat2)
	       ++valid;
         }
         else if (cat3 > cat2 - cat1)
	    ++valid;
      }
   }

   if (valid == 3)
      printf("Valori validi: %.2f, %.2f e %.2f\n", cat1, cat2, cat3);
   else
      printf("Valori NON validi: %.2f, %.2f e %.2f\n", cat1, cat2, cat3);

   return 0;
} /* E0F main */

