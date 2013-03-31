/* Esercizio 4.18 */

#include <stdio.h>

int main()
{
   int num, i, x;

   for(i = 1; i <= 5; ++i) {
      printf("Inserisci un numero [-%d]: ", 6-i);
      scanf("%d", &num);

      /* se è compreso tra 1 e 30 */
      if (num >= 1 && num <= 30) {
	 for(x = num; x >= 1; --x) /* stampo num asterischi */
	    printf("*");
      }
      else {
	 printf("Usare i numeri da 1 a 30");
	 --i;
      }
      printf("\n");
   }

   return 0;
} /* E0F main */

