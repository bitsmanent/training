/* Esercizio 5.16 */

#include <stdio.h>

int integerPower(int, int);

int main()
{
   int b, e;

   printf("Insert base: ");
   scanf("%d", &b);
   while(b != EOF) {
      printf("Insert exponent: ");
      scanf("%d", &e);

      printf("\n%d^%d = %d\n", b, e, integerPower(b, e));

      printf("\nInsert base: ");
      scanf("%d", &b);
   }

   return 0;
} /* E0F main */

/* Return value of base^exponent */
int integerPower(int base, int exponent)
{
   int i, x = base;

   for(i = 1; i < exponent; i++) {
      x *= base;
   } /* end for (i) */

   return x;
} /* eof integerPower() */

