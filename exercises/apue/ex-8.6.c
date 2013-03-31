/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 8.6
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int
main(void)
{
   pid_t pid;

   if( (pid = fork()) == -1 ) {
      perror("fork");
      return EXIT_FAILURE;
   }
   else if( pid ) {
#if !defined(__linux__)
      sleep(1); /* Wait a bit to make a zombie */
#endif
      system("ps");
   }

   return EXIT_SUCCESS; /* Make C compiler happy! */
} /* eof main() */

