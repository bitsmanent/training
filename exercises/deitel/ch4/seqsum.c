/* Esercizio 4.9 */

#include <stdio.h>

int main()
{
   int counter, value;
   int total = 0; /* volutamente NON inizializzato */
		  /* nell'intestazione del for() */

   printf("Intero: ");
   scanf("%d", &value);

   for (counter = value; counter >= 1; --counter) {
      printf("Intero [-%d]: ", counter);
      scanf("%d", &value);

      total += value;
   }

   printf("La domma dei valori è %d\n", total);

   return 0;
} /* E0F */

