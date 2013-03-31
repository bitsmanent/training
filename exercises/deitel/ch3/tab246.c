/* Esercizio 3.26
 * 
 * Stampa una tabella di multipli di 2, 4 e 5
*/

#include <stdio.h>

int main()
{
   int i=3;

   printf("A  A+2A+4A+6\n\n");
   while(i <= 15) {
      if (i == 3)
        printf("%d  %d  %d  %d\n", i, i+2, i+4, i+6);
      else if (i == 6)
        printf("%d  %d  %d %d\n", i, i+2, i+4, i+6);
      else if (i == 9)
         printf("%d  %d %d %d\n", i, i+2, i+4, i+6);
      else
         printf("%d %d %d %d\n", i, i+2, i+4, i+6);
      i += 3;
   }

   return 0;
} /* E0F main */
