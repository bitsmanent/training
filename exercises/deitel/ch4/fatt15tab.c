/* Esercizio 4.14 */

#include <stdio.h>

int main()
{
   int c_val, i; /* contatori */
   int fatt = 1; /* Fattoriale */

   for (i = 1; i <= 5; ++i) {
     for (c_val = i; c_val >= 1; --c_val) {
         fatt *= c_val;
      }
      printf("%d! = %d\n", i, fatt); 
      fatt = 1;
   }

   return 0;
} /* E0F main */

