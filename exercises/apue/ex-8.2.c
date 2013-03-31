/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 8.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

pid_t vfunc(void);

int
main(void)
{
   pid_t pid;

   if( (pid = vfunc()) == -1 ) {
      perror("vfunc");
      return EXIT_FAILURE;
   }

   printf("[%d] Returning..\n", pid);

   return EXIT_SUCCESS;
} /* eof main() */

pid_t
vfunc(void)
{
   pid_t pid = vfork();

#if !defined(__linux__)
   if( pid > 0 )
      sleep(2); /* Parent: wait a bit to child returns first */
#endif

   return pid;
} /* eof vfunc() */

