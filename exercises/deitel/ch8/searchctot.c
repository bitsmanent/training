/* Exercise 8.19 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STRINGS 10
#define BUF 254
#define ASCII 127

int main(void)
{
   char string[STRINGS][BUF] = { { 0 } };
   int i = 0, j, counter[ASCII] = { 0 };

   /* Take the strings */
   printf("Give me a string (%d to end): ", EOF);
   gets(string[i]);

   while( atoi(string[i++]) != EOF ) {
      printf("Give me a string (%d to end): ", EOF);
      gets(string[i]);
   }

   string[i - 1][0] = '\0'; /* Remove the '-1' */

   for(i = 0; i < STRINGS; i++) {
      for(j = 0; (unsigned)j < strlen(string[i]); j++) {
	 ++counter[tolower((int)string[i][j])];
      }
   }
 
   for(i = 1; i < ASCII; i++) {
      if(counter[i]) {

	 i == 32 ? printf("spaces") : printf("%c", i);

         printf("[%d] ", counter[i]);
      }
   }
   printf("\n");

   return 0;
} /* E0F main */

