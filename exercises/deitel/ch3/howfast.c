/*
 * Esercizio 3.37
 * Calcola la velocità del PC
*/

#include <stdio.h>

int main()
{
   int i = 1;

   while(i < 3000000) {
      if (i % 1000000 == 0)
	 printf("%d\n", i);
      ++i;
   }

   return 0;
} /* E0F main */

