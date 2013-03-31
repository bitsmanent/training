/* Exercise 5.42 */

#include <stdio.h>

int gcd(int, int);

int main()
{
   int num1, num2;

   printf("Give me two numbers: ");
   scanf("%d%d", &num1, &num2);
   printf("GCD between %d and %d is %d.\n", num1, num2, gcd(num1, num2));

   return 0;
} /* E0F main */

/* Calculate the GCD recursively */
int gcd(int x, int y)
{
   if(y == 0)
      return x;

   return gcd(y, x % y);
} /* eof gcd() */

