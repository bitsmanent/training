/* Exercise 8.34 (a) */

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

   printf("\nOccurrences table\n"
	  "* (NP = not printable)\n"
	  "* (SP = spaces)\n\n");
 
   for(i = j = 1; i < ASCII; i++) {
      if(counter[i]) {

	 if(i < 32) printf("NP: ");
	 else if(i == 32) printf("SP: ");
	 else printf("%2c: ", i);
         printf("%2d | ", counter[i]);

         if( !(j % 4) )
	    printf("\n-----------------------------------\n");
	 ++j;
      }
   }
   printf("\n\n");

   return 0;
} /* E0F main */

