/* Esercizio 2.30 (Cap. 2)
   Dato un intero di 5 cifre stampare una cifra alla volta
   ognuna separata da 3 spazi: 42339 = 4   2   3   3   9. */

#include <stdio.h>

int main()
{
   int n;
   int n1, n2, n3, n4, n5;

   printf("Dammi un intero di 5 cifre: ");
   scanf("%d", &n);

   /* Spezzetto l'intero nelle sue singole cifre */
   n1 = n / 10000;
   n2 = (n / 1000) % 10;
   n3 = (n / 100) % 10;
   n4 = (n / 10) % 10;
   n5 = n % 10;
  
   /* Stampo le cifre */
   printf("%d   %d   %d   %d   %d\n",n1, n2, n3, n4, n5);

   return 0;
} /* E0F main */

