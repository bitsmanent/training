/* Exercise 8.33 */

#include <stdio.h>

size_t strlen(const char *s);

int main(void)
{
   char string[] = "strlen(string): 18";

   printf("strlen(string): %d\n", strlen(string));

   return 0;
} /* E0F main */

/* computes the lenght of the string s */
size_t strlen(const char *s)
{
   int i = 0;

   while( s[i++] != '\0' ) ;

   /* Second version
   while( *(s + i++) != '\0' ) ;
   */

   return i - 1;
} /* eof strlen() */

