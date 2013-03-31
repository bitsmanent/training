/* Exercise 5. 37 */

#include <stdio.h>

int power(int, int);

int main()
{
   int base, exponent;

   printf("Give me a base and exponent: ");
   scanf("%d%d", &base, &exponent);

   printf("Result: %d\n", power(base, exponent));

   return 0;
} /* E0F main */

/* calculate power of an integer (recursively) */
int power(int b, int e)
{
   if(e == 1)
      return b * e;

   return b * power(b, e - 1);

} /* eof power() */

