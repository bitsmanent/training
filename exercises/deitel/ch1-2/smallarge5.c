/* Esercizio 2.23 (Cap. 2)
   Determina il maggiore e il minore
   nell'insieme di 5 interi. */

#include <stdio.h>

int main()
{
   int a, b, c, d, e;
   int small, large;

   printf("Dammi 5 interi: ");
   scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

   /* Trovo il maggiore */
   if (a > b)
      large = a;
   if (b > a)
      large = b;
   if (c > large)
      large = c;
   if (d > large)
      large = d;
   if (e > large)
      large = e;

   /* Trovo il minore */
   if (a > b)
      small = b;
   if (a < b)
      small = a;
   if (c < small)
      small = c;
   if (d < small)
      small = d;
   if (e < small)
      small = e;

   /* Stampo i risultati */
   printf("Maggiore: %d\n", large);
   printf("Minore: %d\n", small);

   return 0;
} /* E0F main */

