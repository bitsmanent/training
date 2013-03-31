/* Esercizio 4.31 */ 

#include <stdio.h>

int main()
{
   int i, j, k, x;

   for(i = 1, x = 4; i <= 9; i += 2, --x) {
      for(j = x; j >= 1; --j) /* stampa 'x' spazi */ 
	 printf(" ");

      for(k = i; k >= 1; --k) /* stampa 'i' asterischi */
         printf("*");

      printf("\n");
   }

   for(i = 7, x = 1; i >= 1; i -= 2, ++x) { 
      for(j = x; j >= 1; --j) /* stampa 'x' spazi */
	 printf(" ");

      for(k = i; k >= 1; --k) /* stampa 'i' asterischi */
	 printf("*");
      printf("\n");
   }

   return 0;
} /* E0F main */

