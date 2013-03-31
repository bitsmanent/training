/* Exercise 8.12 */

/* A bad implementation of the limerick generator */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define LIMS 5
#define WORDS 8 /* Words for string (article, noun, etc.) */
#define SIZE 90

char *strrpbrk(const char * const s, const char * const charset);

int main(void)
{
   int i, j, k, x, l, rloop, rhymes[5] = { 0 };
   char tmp_s[SIZE], phrase[SIZE];
   const char matches[] = "aeiou", *tokp;

   const char * const article = "the a one some any each no that";
   const char * const noun = "stupid girl guy town car dog cat day";
   const char * const verb = "drove looking ran walked skipped found seen borned";
   const char * const preposition = "to from over under on by in up";

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
			if(*strrpbrk(tokp, matches) == rhymes[0]) {
		           break;
		        }
		     }
		     else if(i == 2) {
			if(*strrpbrk(tokp, matches) != rhymes[0])
			   break;
		     }
		     else if(i == 3) {
		       if(*strrpbrk(tokp, matches) == rhymes[2])
  		           break;
		     }
		     else if(i == 4) {
			if(*strrpbrk(tokp, matches) == rhymes[0])
			   break;
		     }
	          }
	       }
	    }

            /* Append the token in the phrase */
            if(!j)
	       strcpy(phrase, tokp);
	    else
	       strcat(phrase, tokp);
	    strcat(phrase, " ");
         }
         rhymes[i] = *strrpbrk(phrase, matches);
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

/* The same of strbprk(3) except that the check
 * is done from end to start of string pointer. */
char * strrpbrk(const char * const s, const char * const charset)
{  
   int i;
   char *ret;

   for(i = strlen(s) - 1; i >= 0 ; i--) {
      if( (ret = strchr(charset, s[i])) != NULL ) {
         break;
      }
   }

   return ret;

} /* eof strrbprk() */

