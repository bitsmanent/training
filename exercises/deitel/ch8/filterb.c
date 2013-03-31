/* Exercise 8.23 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 10
#define BUF  255

int main(void)
{
   char strings[SIZE][BUF];
   int i = 0;

   printf("Give me a string (%d to end): ", EOF);
   gets(strings[i]);

   while( atoi(strings[i++]) != EOF ) {
      printf("Give me a string (%d to end): ", EOF);
      gets(strings[i]);
   }

   for(i = 0; i < SIZE; i++) {
      if( tolower((int)strings[i][0]) == 'b')
	 printf("%s\n", strings[i]);
   }

   return 0;
} /* E0F main */

