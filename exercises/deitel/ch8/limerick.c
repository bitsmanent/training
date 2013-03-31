/* Exercise 8.12 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define LIMS 5
#define WORDS 5 /* Words for string (article, noun, etc.) */
#define SIZE 30

int main(void)
{
   int i, j, k, x, l, rloop, rhymes[5] = { 0 };
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

   for(l = 0; l < LIMS; l++) { 

      /* loop the phrases */
      for(i = 0; i < 5; i++) {

         /* loop the *string[] */ 
         for(j = 0; j < 6; j++) {

            /* Create the phrase */
	    rloop = 1 + rand() % WORDS;
 
            for(k = 0; k < rloop && tokp != NULL; k++) {
	       if(!k) {
	          strcpy(tmp_s, string[j]);
	          tokp = strtok(tmp_s, " ");
	       }
	       else tokp = strtok(NULL, " ");

	       if(i && j == 5) {
		  /* Check the rhymes */
	          for(x = 0; x < 5; x++) {
	             if(!x) {
                        strcpy(tmp_s, string[j]);
		        tokp = strtok(tmp_s, " ");
 	  	     }
	   	     else tokp = strtok(NULL, " ");

		     /* set the rhymes */
		     if(i == 1) {
		        if(tokp[strlen(tokp) - 1] == rhymes[0]) {
		           break;
		        }
		     }
		     else if(i == 2) {
			if(tokp[strlen(tokp) - 1] != rhymes[0])
			   break;
		     }
		     else if(i == 3) {
		       if(tokp[strlen(tokp) - 1] == rhymes[2])
  		           break;
		     }
		     else if(i == 4) {
		        if(tokp[strlen(tokp) - 1] == rhymes[0])
			   break;
		     }

	          }
	       }
	    }

            /* Append the token in the phrase */
            if(!j)
	       strcpy(phrase, tokp);
	    else {
	       strcat(phrase, tokp);
	    }
	    strcat(phrase, " ");
         }
         rhymes[i] = phrase[strlen(phrase) - 2];
         strcat(phrase, "\0"); /* "Close" the string */

         /* Add some graphic stuff :-) */
         phrase[0] = toupper((int)phrase[0]);
         phrase[strlen(phrase) - 1] = '.';

         printf("%2d: %s\n", i + 1, phrase);

      }

      printf("\n");
   } /* end for (l) */

   return 0;
} /* E0F main */

