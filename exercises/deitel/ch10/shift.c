/* Exercise 10.10 */

#include <stdio.h>

void tobits(int n);

int main(void)
{
   int num = 9;

   printf("tobits(%d):\t", num);
   tobits(num);

   num >>= 4;
   printf("\n");

   printf("tobits(%d):\t", num);
   tobits(num);

   printf("\n");

   return 0;
} /* E0F main */

/* Print a number in bits */
void tobits(int n)
{
   int i;
   unsigned mask = 1 << 31;

   for(i = 1; i <= 32; i++) {
      printf("%d", n & mask ? 1 : 0);

      if( !(i % 8) )
	 putchar(' ');

      n <<= 1;
   }

} /* eof tobits() */

