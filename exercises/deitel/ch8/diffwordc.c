/* Exercise 8.34 (c) */

/* NOTE: orderall() is not so "smart" */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 10
#define BUF 254
#define MAX 30

int ison(char s[][BUF], char *word);
char *sclean(char *s);
void orderall(char s[][BUF], int n[MAX]);


int main(void)
{
   char string[SIZE][BUF] = { { 0 } }, *tokp;
   int i, idx, midx = 0, counter[MAX] = { 0 };
   char sstr[MAX][BUF] = { { 0 } };

   /* Take the strings */
   printf("Give me a string (%d to end): ", EOF);
   gets(string[i]);

   while( atoi(string[i++]) != EOF ) {
      printf("Give me a string (%d to end): ", EOF);
      gets(string[i]);
   }

   string[i - 1][0] = '\0'; /* Remove the '-1' */

   for(i = 0; i < SIZE; i++) {

      /* count the words */
      tokp = strtok(string[i], " ");
      while( tokp != NULL ) {

	 if( (idx = ison(sstr, tokp)) > midx)
	    midx = idx;

	 if(idx == -1) {
	    strcpy(sstr[++midx], tokp);
	    counter[midx] = 1;
	 }
	 else {
	    ++counter[idx];
	 }

	 tokp = strtok(NULL, " ");
      }
   }

   orderall(sstr, counter); /* Order the output */

   /* Show the results */
   printf("\nTABLE..\n\n%4s%31s\n", "Word", "Occurrences");
   printf("-----------------------------------\n");
   for(i = 0; i < MAX; i++) {
      if( strlen(sstr[i]) )
         printf("%c%-13s\t\t%11.2d\n",
	    toupper((int)sstr[i][0]), &sstr[i][1], counter[i]);
   }

   printf("\n");

   return 0;
} /* E0F main */

/* locate word to s[][] strings */
int ison(char s[][BUF], char *word)
{
   int i;

   for(i = 0; i < MAX; i++) {
      if( ! strcmp(s[i], sclean(word)) )
	 return i;
   }

   return -1;
} /* eof ison() */

/* clean a string :-) */
char *sclean(char *s)
{
   int i;

   for(i = 0; s[i] != '\0'; i++)
      s[i] = !ispunct((int)s[i]) ? tolower((int)s[i]) : ' ';

   return s;
   
} /* eof sclean() */

/* Order alphabetically s and swap the indexes in the n array */
void orderall(char s[][BUF], int n[MAX])
{
   int i, j, num;
   char string[BUF] = { 0 };

   for(i = 0; i < MAX - 1; i++) {
      for(j = 0; j < MAX - 1; j++) {

         if( strcmp(s[j], s[j + 1]) > 0 ) {

	    /* swap the strings */
	    strcpy(string, s[j]);
	    strcpy(s[j], s[j + 1]);
	    strcpy(s[j + 1], string);

            /* swap the numbers */
	    num = n[j];
	    n[j] = n[j + 1];
	    n[j + 1] = num;
	 }

      }
   }
} /* eof orderall */

