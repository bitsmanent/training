/* Esercizio 4.16 */

#include <stdio.h>

int main()
{
   int i, x;

   /* stampo il primo triangolo */
   printf("(A)\n");
   for (i = 1; i <= 10; ++i) {
      for (x = i; x >= 1; --x)
	 printf("*");

      printf("\n");
   }

   /* stampo il secondo triangolo */
   printf("(B)\n");
   for (i = 10 ; i >= 1; --i) {
      for (x = i; x >= 1; --x)
	 printf("*");

      printf("\n");
   }

   /* stampo il terzo triangolo */
   printf("(C)\n");
   for (i = 1; i <= 10; ++i) {
      for (x = i - 1; x >= 1; --x)
	 printf(" ");
      for (x = 11 - i; x >= 1; --x)
	 printf("*");

      printf("\n");
   }

   /* stampo il quarto triangolo */ 
   printf("(D)\n");
   for (i = 10; i >= 1; --i) {
      for (x = i - 1; x >= 1; --x)
	 printf(" ");
      for (x = 11 - i; x >= 1; --x) 
	 printf("*");

      printf("\n");
   }

   return 0;
} /* E0F main */

