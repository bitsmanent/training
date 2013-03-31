/* Exercise 10.12 */

#include <stdio.h>

typedef unsigned u_int;

void pbits(u_int n);
u_int power2(u_int n, int pow);

int main(void)
{
   u_int num;
   int pow;

   printf("Num and pow: ");
   scanf("%u%d", &num, &pow);

   num = power2(num, pow);

   printf("pbits(%u): ", num);
   pbits(num);

   printf("\n");

   return 0;
} /* E0F main */

/* Print a number in bits */
void pbits(u_int n)
{
   u_int mask = 1 << 31;
   int i;

   for(i = 1; i <= 32; i++) {
      printf("%u", n & mask ? 1 : 0);

      if( !(i % 8) )
	 putchar(' ');

      n <<= 1;
   }

} /* eof pbits() */

u_int power2(u_int n, int pow)
{
   return n <<= pow;
}

