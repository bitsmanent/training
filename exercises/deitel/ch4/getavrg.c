/* Esercizio 4.10 */

#include <stdio.h>

int main()
{
   int i, value;
   float average = 0; /* media */

   printf("Intero: ");
   scanf("%d", &value);

   for (i = 0; value != 9999; ++i) {
      average += (float) value;

      printf("Intero: ");
      scanf("%d", &value);
   }

   printf("La media è %.2f\n", average / i);

   return 0;
} /* E0F main */

