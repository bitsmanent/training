/* 
 * Esercizio 3.40
 * Visualizzo una scacchiera con 3 printf(1);
*/

#include <stdio.h>

int main()
{
   int x = 1, y; /* contatori */

   while(x <= 8) {
      y = 0;
      while(y < 8) {
         printf("* ");
	 ++y;
      }
      printf("\n");
      if (x % 2)
	 printf(" ");
      ++x; 
   }

   return 0;
} /* E0F main */

