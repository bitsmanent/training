/* Exercise 8.18 */

#include <stdio.h>
#include <string.h>

#define BUF 254

int main(void)
{
   char string[BUF], search, *searchPtr;

   printf("Give me a string: ");
   gets(string);

   printf("Give me your search character: ");
   search = getchar();

   searchPtr = strchr(string, search); /* Start the search */ 
   while( searchPtr != NULL ) { /* Found all next matches */
      printf("String: %s\n", searchPtr);
      searchPtr = strchr(searchPtr + 1, search);
   }

   return 0;
} /* E0F main */

