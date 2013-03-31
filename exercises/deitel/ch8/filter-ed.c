/* Exercise 8.24 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 10
#define BUF  255

int main(void)
{
   char strings[SIZE][BUF];
   int i = 0, j;

   printf("Give me a string (%d to end): ", EOF);
   gets(strings[i]);

   while( atoi(strings[i++]) != EOF ) {
      printf("Give me a string (%d to end): ", EOF);
      gets(strings[i]);

      for(j = 0; j < (int)strlen(strings[i]); j++)
	 strings[i][j] = tolower((int)strings[i][j]);
   }

   for(i = 0; i < SIZE; i++) {
      /* If the current string terminate with "ed", then print it */
      if( !strncmp( &strings[i][ strlen(strings[i]) - 2 ], "ed", 2 ) )
	 printf("%s\n", strings[i]);
   }

   return 0;
} /* E0F main */

