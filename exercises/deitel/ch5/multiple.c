/* Esercizio 5.17 */

#include <stdio.h>

int multiple(int, int);

int main()
{
   int num1, num2;

   while(1) {
      printf("Give me two numbers (^C to end): ");
      scanf("%d%d", &num1, &num2);

      if(multiple(num1, num2))
	 printf("%d is multiple of %d\n", num1, num2);
      else
	 printf("%d is NOT multiple of %d\n", num1, num2);

   } /* end while(1) */

   return 0;
} /* E0F main */

/* Check if x is multiple of y */
int multiple(int x, int y)
{
   if(!y)
      return 0;
   else if(x > y && !(x % y) || y < 0 && x < y && !(x % y))
      return 1;
   else
      return 0;

} /* eof multiple() */

