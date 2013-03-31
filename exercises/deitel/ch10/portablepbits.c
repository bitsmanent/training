/* Exercise 10.18 */

#include <stdio.h>

typedef unsigned u_int;

void pbits(u_int n);


int main(void)
{
   u_int num;

   num = 12345;

   pbits(num);
   putchar('\n');

   return 0;
} /* E0F main */

/* Print a number in bits */
void pbits(u_int n)
{
   u_int mask = 1 << 31;
   int i;

   for(i = 1; i <= 32; i++) {
      if( sizeof(int) == 4 )
         printf("%u", n & mask ? 1 : 0);
      else
	 printf("%ul", n & mask ? 1 : 0);

      if( !(i % 8) )
         putchar(' ');

      n <<= 1;
   }

} /* eof pbits() */


