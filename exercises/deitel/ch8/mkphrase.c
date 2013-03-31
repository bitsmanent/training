/* Exercise 8.11 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define PHRASES 20
#define SIZE 30

int main(void)
{
   int i, j, k;
   char tmp_s[SIZE], phrase[SIZE];
   const char * tokp;

   const char * const article = "the a one some any";
   const char * const noun = "boy girl do town car";
   const char * const verb = "drove jumped ran walked skipped";
   const char * const preposition = "to from over under on";

   /* Store the memory address for each string */
   const char * const string[6] = { 
      article, noun, verb,
      preposition, article, noun
   };

   srand( time(NULL) );

   /* loop the phrases */
   for(i = 0; i < PHRASES; i++) {

      /* loop the *string[] */ 
      for(j = 0; j < 6; j++) {

         /* Copy the string and tokenize it */
	 strcpy(tmp_s, string[j]);
	 tokp = strtok(tmp_s, " ");
         for(k = rand() % 5; k && tokp != NULL; k--)
	    tokp = strtok(NULL, " ");

         /* Append the token in the phrase */
         if(!j)
	    strcpy(phrase, tokp);
	 else {
	    strcat(phrase, tokp);
	 }
	 strcat(phrase, " ");
      }
      strcat(phrase, "\0"); /* "Close" the string */

      /* Add some graphic stuff :-) */
      phrase[0] = toupper((int)phrase[0]);
      phrase[strlen(phrase) - 1] = '.';

      printf("Phrase %2d: %s\n", i+1, phrase);

   }

   return 0;
} /* E0F main */

