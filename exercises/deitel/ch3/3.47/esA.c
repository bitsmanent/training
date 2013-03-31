/*
 * Esercizio 3.47 (a)
 * 
*/

#include <stdio.h>

int main()
{
   int n, ncp, norig; /* intero e "copia di intero" */
   int i; /* contatore */

   printf("Inserisci un numero: ");
   scanf("%d", &n);

   if (n >= 1) {
      norig = ncp = n; /* creo una copia di n per poterla decrementare */
      i = n; /* imposto il contatore */
      while(--i > 0)
         n *= --ncp;
      printf("%d! = %d\n", norig, n);
   }
   else printf("Non sono ammessi numeri negativi!\n");

   return 0;
} /* E0F main */

