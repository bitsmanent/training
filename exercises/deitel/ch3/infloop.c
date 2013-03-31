/*
 * Esercizio 3.41
 * Stampa i multipli di 2 all'infinito
*/

#include <stdio.h>

int main()
{
   int i = 2;

   while(1)
      printf("%d\n", i *= 2); 

   return 0;
} /* E0F main */

