/* Exercise 8.21 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 20
#define BUF 254

void bsortp(char *string[]);

int main(void)
{
   char cities[SIZE][BUF], *pointers[SIZE] = { 0 };
   int i = 0, j;

   printf("Give me a city (%d to end): ", EOF);
   gets(cities[i]);

   while( atoi(cities[i++]) != EOF ) {
      /* convert the string to lowercase */
      for(j = 0; j < (int)strlen(cities[i - 1]); j++)
	 cities[i - 1][j] = tolower((int)cities[i - 1][j]);

      printf("Give me a city (%d to end): ", EOF);
      gets(cities[i]);
   }

   cities[i - 1][0] = '\0'; /* Remove the '-1' */

   /* Copy the address of each phrase to pointers[] */
   for(i = 0; i < SIZE; i++)
      pointers[i] = cities[i];

   bsortp(pointers); /* Order the pointers[] array */

   /* Print the non-empty strings in the pointer[] */
   for(i = 0; i < SIZE; i++) {
      if( strlen(pointers[i]) )
         printf("%s\n", pointers[i]);
   }

   return 0;
} /* E0F main */

/* Sort an array of pointers using the BubbleSort alrorithm */
void bsortp(char *string[])
{
   int i, j;
   char *tmpp;

   for(i = 1; i < SIZE; i++) {
      for(j = 0; j < SIZE - 2; j++) {
         if( strcmp(string[j], string[j + 1]) > 0 ) {
            /* Swap the addresses */
	    tmpp = string[j];
	    string[j] = string[j + 1];
	    string[j + 1] = tmpp;
	 }
      }
   }
} /* eof bsortp() */

