/* Exercise 4.48 */

#include <stdio.h>

int mystery(int, int);

int main()
{
   int x, y;

   printf("Enter two integers: ");
   scanf("%d%d", &x, &y);

   printf("The result is %d\n", mystery(x, y));

   return 0;
} /* E0F main */

/* multiplies a for b times recursively */
int mystery(int a, int b)
{
   if(b == -1)
      return -a;
   else if(b == 1)
      return a;
   else {
      if(b > 1)
         return a + mystery(a, b - 1);
      else
	 return -a + mystery(a, b + 1);
   }
} /* eof mystery() */

