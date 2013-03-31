/* Exercise 5.28 */

#include <stdio.h>
#include <math.h>

void revint(int);

int main()
{
   int number;

   printf("Give me a number: ");
   scanf("%d", &number);

   revint(number);
   printf("\n");

   return 0;
} /* E0F main */

/* print a int to reverse */
void revint(int num)
{
   int i;

   if(num > pow(10, 9)) {
      printf("Number is too large!");
      return;
   }
   for(i = 1; i <= pow(10, 8); i *= 10) {
      if(num / i % 10)
         printf("%d", num  / i % 10);
   } /* end for (i) */

} /* eof revint() */

