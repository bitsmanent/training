/* Esercizio 2.26 (Cap. 2)
   Dati due interi determino e visualizzo
   se il primo e' multiplo del secondo. */

#include <stdio.h>

int main()
{
   int a, b;

   printf("Dammi 2 interi: ");
   scanf("%d%d", &a, &b);

   if (a%b == 0)
      printf("%d e' multiplo di %d\n", a, b);
   if (a%b != 0)
      printf("%d non e' multiplo di %d\n", a, b);

   return 0;
} /* E0F main */

