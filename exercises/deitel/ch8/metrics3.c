/* Exercise 8.40 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TYPES 24
#define SIZE 254

char *getkey(char *s, char units[][TYPES][11], int *idx);

int main(void)
{
   int idx, wordm = 0, loop = 0;
   char class, *tokp, string[SIZE], word[12];
   double tot, divs;

   char units[3][TYPES][11] = {
      { /* The labels */
	"millimetr", "centimetr", "decimetr", "metr", "kilometr",
	"millilitr", "centilitr", "decilitr", "litr", "decalitr", "ettolitr",
        "milligramm", "gramm", "decagramm", "kilogramm", "tonnellat", "quintal",
        "gallon", "pollic", "pied", "libbr", "yard",

        /* Word meters */
        "quart", "dozzin" },

      { /* The values */
	"1", "10", "100", "1000", "1000000",
	"1", "10", "100", "1000", "10000", "100000",
	"1", "1000", "10000", "1000000", "10000000", "100000000",

	/* 3.7853  "2.54" "30.48"  "0.4536"  "0.9144" */
	"3785", "25.4", "304.8", "4.536", "914.4",

        /* Word meters */
	"4", "12" },

      { /* The classes */
	"A", "A", "A", "A", "A",
	"B", "B", "B", "B", "B", "B",
	"C", "C", "C", "C", "C", "C",
	"B", "A", "A", "C", "A",

        /* Word meters: 0 divide, 1 multiply */
	"0", "1" }
   };

   printf("Please, write your answer: ");
   gets(string);

   tokp = getkey(string, units, &idx);
   while(tokp != NULL) {

      /* Check for the "word meters": un quarto, una dozzina, etc. */
      if( !memcmp(tokp, "un", 2) )
	 strcpy(word, "1");
      else
	 strcpy(word, tokp);

      if( *units[2][idx] == '0' || *units[2][idx] == '1' ) {
	 wordm = 1; /* Mark the "operation" as "Word meter" */
	 strcat(word, " ");

	 if( (tokp = getkey(NULL, units, &idx)) != NULL )
	    strcat(word, tokp);
	 else
	    break;
      }

      switch(++loop) {
	 case 1:
	    divs = atof(units[1][idx]);
	    class = *units[2][idx];
	    break;
	 case 2:
	    tot = atof(word);
	    break;
	 case 3:

            /* If there is a word meter.. */
	    if(wordm) { /* Marked operation */
	       if( !memcmp(word, "quart", 5) )
		  tot *= atof(units[1][idx]) / 4;
	       else
		  tot *= atof(units[1][idx]) * 12;
	    }
	    else
	       tot *= atof(units[1][idx]);

	    if(class != *units[2][idx]) {
	       printf("error: conflict in conversion types\n");
	       return -1;
	    }
	    
	    break;
	 default:
	    printf("unknown error: please fix this\n");
	    break;
      }

      /* DeBuG
      printf("case[%d]===[ word: %s\n", loop, word);
      */

      tokp = getkey(NULL, units, &idx);
   }

   if(loop != 3)
      printf("Are you forgetting something? :-)\n");
   else
      printf("Results: %.2f\n", tot / divs);

   return 0;
} /* E0F main */

/* locate and tokenize the units[][][] elements */
char *getkey(char *s, char units[][TYPES][11], int *idx)
{
   int i;
   char *tokp;
   static char *prev_s;

   prev_s = s;

   tokp = strtok( s == NULL ? prev_s : s, " ");
   while(tokp != NULL) {

      for(i = 0; i < TYPES; i++) {
	 if( ! memcmp(tokp, units[0][i], strlen(units[0][i])) ||
	     isdigit((int)*tokp) || !memcmp(tokp, "un", 2) ) {

            /* Toggle the '?' at end of string */
	    if( tokp[strlen(tokp) - 1] == '?' )
	      tokp[strlen(tokp) - 1] = '\0';

            if(idx != NULL) *idx = i;
	    return tokp;
	 }
      }

      tokp = strtok(NULL, " ");
   }

   return NULL;
} /* eof getkey() */

