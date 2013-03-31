/* Exercise 8.39 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 254
#define CHARS 39

void tomorse(char *string, char table[][CHARS][7]);
void toeng(char *string, char table[][CHARS][7]);

int main(void)
{
   char string[SIZE] = { 0 };
   char table[2][CHARS][7] = {

      /* Morse code [A,Z] */
      { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",

        /* Numbers [0,9] */
        "-----", ".----", "..---", "...--", "....-", ".....", "-....",
        "--...", "---..", "----.",

        /* Fullstop, comma and query */
	".-.-.-", "--..--", "..--.." },

      /* English charset [A,Z] */
      { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
        "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",

        /* Numbers [0,9] */
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",

        /* Fullstop, comma and query */
	".", ",", "*" }
   };

   printf("Give me an english word: ");
   gets(string);
   tomorse(string, table);

   printf("\nGive me a morse code: ");
   gets(string);
   toeng(string, table);

   printf("\n");

   return 0;
} /* E0F main */

/* Print a string converted to morse */
void tomorse(char *string, char table[][CHARS][7])
{
   int i, j, c;
   char *tokp;

   tokp = strtok(string, " ");
   while(tokp != NULL) {
      c = 0;

      for(i = 0; i < (int)strlen(tokp); i++) {
	 for(j = 0; j < CHARS; j++) {
	    if ( toupper((int)tokp[i]) == *table[1][j] ) {
	       printf("%s", table[0][j]);
	       c = 1;
	       break;
	    }
	 }

         /* Unknown characters */
	 if(!c)
	    printf("?");

	 printf(" ");
      }

      printf("   ");
      tokp = strtok(NULL, " ");
   }

} /* eof toeng() */

/* Print a string converted to english */
void toeng(char *string, char table[][CHARS][7])
{
   int i, c;
   char *tokp;

   tokp = strtok(string, " ");
   while(tokp != NULL) {
      c = 0;

      for(i = 0; i < CHARS; i++) {
	 if( !(memcmp(tokp, table[0][i],
	    strlen(tokp) > strlen(table[0][i]) ?
	       strlen(tokp) : strlen(table[0][i]) )) ) {

	    printf("%s", table[1][i]);
	    c = 1;
	    break;
	 }
      }

      /* Unknown characters */
      if(!c)
	 printf("?");

      if( !(strncmp((tokp + strlen(tokp) + 1), "  ", 2)) )
         printf(" ");

      tokp = strtok(NULL, " ");
   }

} /* eof toeng() */

