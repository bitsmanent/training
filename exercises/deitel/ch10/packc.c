/* Exercise 10.13/14 */

#include <stdio.h>

typedef unsigned u_int;

void pbits(u_int n);
u_int packC(char a, char b);
void UnpackC(u_int pack, char *a, char *b);

int main(void)
{
   char a, b;
   u_int result;

   /* Take the chars */
   printf("two chars: ");
   scanf("%c%*c%c", &a, &b);

   /* Print the values in bits */
   printf("pbits(%d):\t", a);
   pbits(a);

   putchar('\n');

   printf("pbits(%d):\t", b);
   pbits(b);

   putchar('\n');

   /* Pack the chars and print the values */
   result = packC(a, b);

   printf("pbits(%u):\t", result);
   pbits(result);

   putchar('\n');

   a = b = '\0'; /* Clean the variables */

   /* UnPack the chars and print the values */
   UnpackC(result, &a, &b);
   printf("Uncompressed: a[%c] b[%c]\n", a, b);

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

/* Compress two char to an unsigned */
u_int packC(char a, char b)
{
   return (a << 8) | b;
} /* eof packC() */

/* UnCompress and unsigned to two chars */
void UnpackC(u_int pack, char *a, char *b)
{
   u_int num = pack;

   num &= 65280;
   *a = num >>= 8;

   num = pack;
   num &= 255;
   *b = pack;

} /* eof UnpackC() */

