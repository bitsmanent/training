/* Exercise 8.7 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   char s[8] = { 0 };
   int i, total = 0;

   for(i = 0; i < 4; i++) {
      printf("Give me a string (int?): ");
      gets(s);
      total += atoi(s);
   }

   printf("The total is: %d\n", total);

   return 0;
} /* E0F main */

