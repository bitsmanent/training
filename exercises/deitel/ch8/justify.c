/* Exercise 8.35 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30
#define BUF  255

#define C4L 65 /* Characters for line */

int main(void)
{
   int i = 0, j;
   char string[SIZE][BUF] = { { 0 } };

   printf("Give me a string (%d to end): ", EOF);
   gets(string[i]);
   while( atoi(string[i++]) != EOF && i < SIZE ) {
      printf("Give me a string (%d to end): ", EOF);
      gets(string[i]);
   }
   string[i - 1][0] = '\0'; /* remove the EOF */

   /* loop the strings */
   for(i = 0; i < SIZE && strlen(string[i]); i++) {

      /* print the current line formatted */
      printf("%10c", ' '); /* Margin left */
      for(j = 1; j <= BUF && j <= (int)strlen(string[i]); j++) {
	 printf("%c", string[i][j - 1]);

	 if( !(j % C4L) ) { /* Characters for line */
            printf("\n%10c", ' '); /* Margin left */

	    /* Toggle the spaces and the newlines */
	    if(string[i][j] == ' ' || string[i][j + 1] == '\n')
	       ++j;
	 }
      }
      printf("%10c\n", ' '); /* Margin right */

   } /* end for (i) */

   return 0;
} /* E0F main */

