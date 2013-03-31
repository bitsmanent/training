/* Esercizio 2.24 (Cap. 2)
   Dato un intero calcola se e' pari o dispari. */

#include <stdio.h>

int main()
{
   int n;

   printf("Inserisci un intero: ");
   scanf("%d", &n);

   if (n%2 == 0)
      printf("%d e' pari\n", n);

   if (n%2 != 0)
      printf("%d e' dispari\n", n);

   return 0;
} /* E0F main */

