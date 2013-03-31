/* Esercizio 4.39 */

#include <stdio.h>

int main()
{
   int x;

   for(x = 1; x <= 10; x++) {

      if ( !(x == 5) )
         printf("%d ", x);

   } /* end for (x) */

   printf("\nNOT used continue to skip printing the value 5\n");

   return 0;
} /* E0F main */

