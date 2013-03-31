/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 6.3
 *
 * NOTE: operating system field has not been implemented
 *       since a Makefile is needed for this purpose.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int
main(void)
{
   struct utsname un;

   /* Get the informations */
   if( uname(&un) == -1 ) {
      perror("uname");
      return EXIT_FAILURE;
   }

   /* Show the informations */
   printf("%s %s %s %s %s",
      un.sysname, un.nodename, un.release,
      un.version, un.machine);
   
#if defined(__Linux__)
# define _UTSNAME_DOMAIN_LENGHT 1
   printf(" %s", un.domainname);
#endif

   printf("\n");

   return EXIT_SUCCESS;
} /* eof main() */

