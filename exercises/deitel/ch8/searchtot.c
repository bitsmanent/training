/* Exercise 8.17 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRINGS 10
#define BUF 254

int main(void)
{
   char string[STRINGS][BUF], search[BUF / 2], *searchPtr;
   int i = 0, counter = 0;

   /* Take the strings */
   printf("Give me a string (%d to end): ", EOF);
   gets(string[i]);

   while( atoi(string[i++]) != -1 ) {
      printf("Give me a string (%d to end): ", EOF);
      gets(string[i]);
   }

   /* Take the search string */
   printf("Give me your search string: ");
   gets(search);

   for(i = 0; i < STRINGS; i++) {
      searchPtr = strstr(string[i], search); /* Start the search */
      while( searchPtr != NULL ) { /* Found all next matches */
	 //printf("Match found to line %d: %s\n", i, searchPtr);
	 searchPtr = strstr(searchPtr + 1, search);
	 ++counter;
      }
   }

   if(!counter)
      printf("No match found!\n");
   else
      printf("Found %d matches!\n", counter);

   return 0;
} /* E0F main */

