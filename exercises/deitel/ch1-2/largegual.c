/* Esercizio 2.18 (Cap. 2)
 * Chiedo due interi e mostro quello maggiore seguito
 * dal letterale "is larger". Se i numeri sono uguali
 * stampo il messaggio corrispondente. */

#include <stdio.h>

int main()
{
   int a, b;

   printf("Inserisci 2 interi: ");
   scanf("%d%d", &a, &b);

   if (a > b)
      printf("%d is larger\n", a);
   if (a < b)
      printf("%d is larger\n", b);
   if (a == b)
      printf("These numbers are equal.\n");

   return 0;

} /* E0F main */

