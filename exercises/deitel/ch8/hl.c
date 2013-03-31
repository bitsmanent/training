/* Exercise 8.6 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
   int i;
   char s[100];

   printf("Give me a string: ");
   gets(s);

   printf("Upper: ");
   for(i = 0; (unsigned)i < strlen(s); i++)
      printf("%c", toupper((int)s[i]));
   putchar('\n');

   printf("Lower: ");
   for(i = 0; (unsigned)i < strlen(s); i++)
      printf("%c", tolower((int)s[i]));
   putchar('\n');

   return 0;
} /* E0F main */

