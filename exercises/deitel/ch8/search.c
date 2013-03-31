/* Exercise 8.16 */

#include <stdio.h>
#include <string.h>

#define BUF 254

int main(void)
{
   char string[BUF], search[BUF / 2], *searchPtr;

   printf("Give me a string: ");
   gets(string);

   printf("Give me your search string: ");
   gets(search);

   searchPtr = strstr(string, search); /* Start the search */ 
   while( searchPtr != NULL ) { /* Found all next matches */
      printf("String: %s\n", searchPtr);
      searchPtr = strstr(searchPtr + 1, search);
   }

   return 0;
} /* E0F main */

