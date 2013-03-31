/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 6.4
 *
 * Sample output: ven feb 15 16:30:43 CET 2008
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TMBUFSZ 64

int
main(void)
{
   struct tm *tm_t;
   char tmbuf[TMBUFSZ];
   time_t tmcal;

   tmcal = time(NULL);

   /* Get the broken-down local time */
   if( (tm_t = localtime(&tmcal)) == NULL ) {
      perror("localtime");
      return EXIT_FAILURE;
   }

   /* Generate the output string */
   strftime(tmbuf, TMBUFSZ, "%a %b %d %X %Z %Y", tm_t);

   printf("%s\n", tmbuf);

   return EXIT_SUCCESS;
} /* eof main() */

