/*
 * Esercizio 3.47 (b)
 * 
*/

#include <stdio.h>

int main()
{
   float e = 1.0; /* e = 1 + ... */

   int ncp; /*  e "copia di intero" */
   int n = 1; /* fattoriale di intero */
   int i, c = 1; /* contatori */

   while(c < 34) {
      n = c; /* n + 1 */
     
      ncp = n; /* creo una copia di n per poterla decrementare */
      i = n; /* imposto il contatore */
      while(--i > 0)
         n *= --ncp;

      /* n = c! */

      e += (float) c / n;
      ++c;
   }

   printf("e = %.2f\n", e);

   return 0;
} /* E0F main */

