/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 9.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main(int argc, char *argv[])
{
   pid_t pid;

   strncpy(argv[0], "ex-9.2", strlen(argv[0]));

   if( (pid = fork()) )
      exit(1);

   if( (pid = fork()) == -1 ) {
      perror("fork");
      return EXIT_FAILURE;
   }
   else if( pid == 0 ) {	/* child */
      sleep(1); /* Wait for the parent to terminate (?) */

      if( setsid() == -1 ) { /* Start a new session */
         perror("setsid");
	 return EXIT_FAILURE;
      }

      /* Some dirty output */
      printf("\n");

      system(
#if defined(__linux__)
      "ps jx"
#else
      "ps jx -otpgid"
#endif
      );

      sleep(1);
   }

   /*
    * The parent just terminate
    * 
    *    ...
   */

   return EXIT_SUCCESS; /* Make C compiler happy! */
} /* eof main() */

