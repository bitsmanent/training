/* Exercise 8.20 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRINGS 10
#define BUF 254

int main(void)
{
   char string[STRINGS][BUF] = { { 0 } }, *tokp;
   int i = 0, counter = 0;

   /* Take the strings */
   printf("Give me a string (%d to end): ", EOF);
   gets(string[i]);

   while( atoi(string[i++]) != -1 ) {
      printf("Give me a string (%d to end): ", EOF);
      gets(string[i]);
   }

   string[i - 1][0] = '\0'; /* Remove the '-1' */

   for(i = 0; i < STRINGS; i++) {
      tokp = strtok(string[i], " ");

      while( tokp != NULL ) {
         ++counter;
         tokp = strtok(NULL, " ");
      }

   }

   if(!counter)
      printf("There are no words!\n");
   else
      printf("There are %d words!\n", counter);

   return 0;
} /* E0F main */

