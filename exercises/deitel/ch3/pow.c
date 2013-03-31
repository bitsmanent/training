/* Esercizio 3.8 (Cap 3)
   Calcola la potenza di x elevato a y */

#include <stdio.h>

int main()
{
   int i = 1, power = 1;
   int x, y; /* Variabili per l'input */

   printf("Dammi 2 interi, x elevato a y: ");
   scanf("%d%d", &x, &y);

   while(i <= y) {
     power *= x;
     ++i;
   }

   printf("%d elevato a %d è uguale a %d\n", x, y, power); 

   return 0;
} /* E0F main */

