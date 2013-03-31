/* Esercizio 3.20 (Cap. 3)
 *
 * Calcola l'interesse semplice di un mutuo
*/

#include <stdio.h>

int main()
{
   float principal, rate;
   int days;

   printf("Inserire capitale: ");
   scanf("%f", &principal);

   while((int)principal != -1) {
      printf("Inserire tasso: ");
      scanf("%f", &rate);
      printf("Inserire i giorni: ");
      scanf("%d", &days);

      printf("Interesse semplice: %.2f\n\n", principal * rate * days / 365);
      printf("Inserire capitale: ");
      scanf("%f", &principal);
   }

   return 0;
} /* E0F main */

