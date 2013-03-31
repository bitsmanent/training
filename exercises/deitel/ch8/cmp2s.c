/* Exercise 8.9 */

#include <stdio.h>
#include <string.h>

int main(void)
{
   char s1[10];
   char s2[10];
   int val;

   printf("Give me a string (s1): ");
   gets(s1);
   printf("Give me another string (s2): ");
   gets(s2);

   val = strcmp(s1, s2);
   printf("s1 is ");

   if(!val)
      printf("equal to");
   else if(val < 0)
      printf("less then");
   else
      printf("greater then");

   printf(" s2\n");

   return 0;
} /* E0F main */

