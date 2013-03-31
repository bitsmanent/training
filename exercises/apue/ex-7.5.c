/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 7.5
*/

#include <stdio.h>
#include <stdlib.h>

typedef void ExitFunc(void);

ExitFunc efunc;		/* Exit function */
int atexit(ExitFunc);	/* Prototyped again */

int
main(void)
{

   atexit(efunc);

   return EXIT_SUCCESS;
} /* eof main() */

void efunc(void)
{
   printf("Exiting...\n");
} /* eof efunc() */

