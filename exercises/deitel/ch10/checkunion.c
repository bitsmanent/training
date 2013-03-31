/* Exercise 10.8 */

#include <stdio.h>

typedef union values {
   char c;
   short s;
   int i;
   long b;
} List;

int main(void)
{
   List lval;

   printf("Char short int long: ");
   scanf("%c%hi%d%ld", &lval.c, &lval.s, &lval.i, &lval.b);

   printf("Char: %c\nShort: %hi\nInt: %d\nLong: %ld\n",
      lval.c, lval.s, lval.i, lval.b);

   return 0;
} /* E0F main */

