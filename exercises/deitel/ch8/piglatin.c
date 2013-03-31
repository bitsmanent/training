/* Exercise 8.13 */

#include <stdio.h>
#include <string.h>

#define SIZE 30

void printLatinWord(char *p);

int main(void) {
   char english[SIZE] = "jump the computer";
   char *tokp;

   printf("The english string is:\t\t%s\n", english);
   printf("The pig lating string is:\t");

   tokp = strtok(english, " ");
   while( tokp != NULL ) {
      printLatinWord(tokp);
      tokp = strtok(NULL, " ");
   }

   printf("\n");

   return 0;
}

/* Take an english word and write it in Pig Latin */
void printLatinWord(char *p)
{
   char string[20];

   strcpy(string, ++p);

   string[strlen(string) + 1] = '\0';
   string[strlen(string)] = *(--p);

   strcat(string, "ay");

   printf("%s ", string);
} /* eof printLatinWord() */

