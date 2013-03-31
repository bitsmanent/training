/* Exercise 8.8 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   char s[8] = { 0 };
   int i;
   float total = 0;

   for(i = 0; i < 4; i++) {
      printf("Give me a string (int?): ");
      gets(s);
      total += atof(s);
   }

   printf("The total is: %.2f\n", total);

   return 0;
} /* E0F main */

