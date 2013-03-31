/* Exercise 10.15/16 */

#include <stdio.h>
#include <string.h>

typedef unsigned u_int;

void pbits(u_int n);
u_int packC(char *s);
void UnpackC(u_int pack, char *s);

int main(void)
{
   int i;
   char string[5] = { 0 };
   u_int result;

   /* Take the chars */
   printf("4 chars: ");
   scanf("%s", string);

   /* Print the values in bits */
   for(i = 0; i < 4; i++) {
      printf("pbits(%d):\t\t", (int)string[i]);
      pbits(string[i]);
      putchar('\n');
   }

   /* Pack the chars and print the values */
   result = packC(string);

   printf("\npbits(%u):\t", result);
   pbits(result);

   putchar('\n');

   printf("string: %s\n", string);

   /* UnPack the chars and print the values */
   UnpackC(result, string);
   printf("\nUncompressed: %s\n", string);

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

/* Compress [1,4] char to an unsigned */
u_int packC(char *s)
{
   int i;
   u_int ret = s[0];

   for(i = 1; i < 4; i++) {
      ret <<= 8;
      ret |= s[i];
   }

   return ret;
} /* eof packC() */

/* UnCompress and unsigned to [1,4] chars */
void UnpackC(u_int pack, char *s)
{
   int i;
   u_int mask = 255 << 24;

   s[0] = (mask & pack) >> 24;

   for(i = 0; i < 3; i++) {
      s[i] = (mask & pack) >> (24 - i * 8);
      mask >>= 8;
   }
   s[i] = (mask & pack) >> (24 - i * 8);

} /* eof UnpackC() */

