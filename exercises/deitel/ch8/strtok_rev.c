/* Exercise 8.15 */

#include <stdio.h>
#include <string.h>

#define SIZE 254

void strtok_rev(char *s);

int main(void)
{
   char string[SIZE], *c;

   printf("Give me a string: ");
   gets(string);

   c = strtok(string, " ");
   strtok_rev(string);
   printf("%s\n", c);

   return 0;
} /* E0F main */

void strtok_rev(char *s)
{
   char *tokp;

   tokp = strtok(NULL, " ");

   if(tokp != NULL) {
      strtok_rev(s);
      printf("%s ", tokp);
   }

} /* eof strtok_rev() */

