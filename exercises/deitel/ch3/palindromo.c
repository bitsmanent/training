/* Esercizio 3.35
 *
 * Dato un intero stabilisce se
 * questo è un palindromo o no.
*/

#include <stdio.h>

int main()
{
   int numero, yn = 0;
   
   printf("Inserisci un numero: ");
   scanf("%d", &numero);

   if (numero / 10000 % 10 == numero % 10)
      if (numero / 1000 % 10 == numero / 10 % 10)
	 yn = 1;

   if (yn)
      printf("%d è un numero palindromo.\n", numero); 
   else
      printf("%d NON è un numero palindromo.\n", numero); 

   return 0;
} /* E0F main */

