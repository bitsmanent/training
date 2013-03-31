/* Esercizio 2.31 (Cap. 2)
   Mostra una tabella con il calcolo dei
   quadrati e cubi dei numeri da 0 a 10. */

#include <stdio.h>

int main()
{
   printf("numero\tquadrato\tcubo\n");
   printf("0\t0\t\t0\n");
   printf("1\t1\t\t1\n");
   printf("2\t%d\t\t%d\n", 2*2, 2*2*2);
   printf("3\t%d\t\t%d\n", 3*3, 3*3*3);
   printf("4\t%d\t\t%d\n", 4*4, 4*4*4);
   printf("5\t%d\t\t%d\n", 5*5, 5*5*5);
   printf("6\t%d\t\t%d\n", 6*6, 6*6*6);
   printf("7\t%d\t\t%d\n", 7*7, 7*7*7);
   printf("8\t%d\t\t%d\n", 8*8, 8*8*8);
   printf("9\t%d\t\t%d\n", 9*9, 9*9*9);
   printf("10\t%d\t\t%d\n", 10*10, 10*10*10);

   return 0;
} /* E0F main */

