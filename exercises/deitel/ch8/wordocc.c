/* Exercise 8.34 (b) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
#define BUF 255
#define MAXWORD 30

int main(void)
{
   char string[SIZE][BUF] = { { 0 } }, *tokp;
   int count[MAXWORD] = { 0 };
   int i = 0, highest = 0;

   /* start to take the strings */
   printf("str (%d to end): ", EOF);
   gets(string[i]);

   /* continue to take the strings */
   while( atoi(string[i++]) != EOF ) {
      printf("str (%d to end): ", EOF);
      gets(string[i]);
   }
   string[i - 1][0] = '\0'; /* clear the EOF char */

   /* count the lenght for each word */
   for(i = 0; i < SIZE; i++) {

      /* tokenizing.. */
      tokp = strtok(string[i], " ");
      while( tokp != NULL ) {
	 ++count[(int)strlen(tokp)];
        
	 /* this instruction is not optimized */
	 if((int)strlen(tokp) > highest)
	    highest = (int)strlen(tokp);

	 tokp = strtok(NULL, " ");
      }
   }

   /* print the results */
   printf("Word size\tOccurrences\n");
   for(i = 1; i <= highest; i++) {
      printf("%9d\t\t%3d\n", i, count[i]);
   }

   return 0;
} /* E0F main */

