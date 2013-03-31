/* Exercise 5.41 */

#include <stdio.h>

long factorial(long number);

int main()
{
   int i;

   for(i = 0; i <= 10; i++) {
      printf("%2d! = %ld\n\n", i, factorial(i));
   }

   return 0;
} /* E0F main */

/* Recursive definition of factorial() function */
long factorial(long number) {

   if(number) printf("=> %d * factorial(%d)\n", number, number - 1);

   if(number <= 1) {
      printf("===>  ", " ");
      return 1;
   }
   else
      return number * factorial(number - 1);

} /* eof factorial() */

