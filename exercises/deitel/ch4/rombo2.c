/* Esercizio 4.32 */ 

#include <stdio.h>

int main()
{
   int i, j, k, x;
   int lines;

   printf("Numero di linee: ");
   scanf("%d", &lines);

 if (lines % 2 && lines >= 1 && lines <= 19) {

   for(i = 1, x = lines / 2; i <= lines; i += 2, --x) {
      for(j = x; j >= 1; --j) /* stampa 'x' spazi */ 
	 printf(" ");

      for(k = i; k >= 1; --k) /* stampa 'i' asterischi */
         printf("*");

      printf("\n");
   }

   for(i = lines - 2, x = 1; i >= 1; i -= 2, ++x) { 
      for(j = x; j >= 1; --j) /* stampa 'x' spazi */
	 printf(" ");

      for(k = i; k >= 1; --k) /* stampa 'i' asterischi */
	 printf("*");
      printf("\n");
   } /* end of for */

 } /* End IF */
 else
    printf("Usare interi dispari da 1 a 19\n");


   return 0;
} /* E0F main */

