/* Esercizio 2.16 (Cap. 2)
 * Calcola la somma, prodotto, differenza
 * quoziente e resto di due interi */

#include <stdio.h>

int main()
{
   int x, y;

   printf("\nDammi i 2 interi per il calcolo: ");
   scanf("%d%d", &x, &y);

   printf("\nSomma: %d\n", x + y);
   printf("Prodotto: %d\n", x * y);

   if (x > y)
      printf("Differenza: %d\n", x - y);

   if (x < y)
      printf("Differenza: %d\n", y - x);

   printf("Quoziente: %d\n", x / y);
   printf("Resto: %d\n", x % y); 

   return 0;

} /* E0F main **/

