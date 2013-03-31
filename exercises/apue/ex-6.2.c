/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 6.2
*/

#include <stdio.h>
#include <stdlib.h>

#include <paths.h>	/* Needed for _PATH_SHADOW */

#if defined(_PATH_SHADOW)
# include <shadow.h>
#else
# include <pwd.h>
#endif

int
main(int argc, char *argv[])
{
   char *user, *pass;

#if defined(_PATH_SHADOW)
   struct spwd *p;
#else
   struct passwd *p;
#endif

   /* Check the arguments */
   if( argc != 2 ) {
      printf("Usage: %s <username>\n", argv[0]);
      return EXIT_FAILURE;
   }

   /* Get the informations */
#if defined(_PATH_SHADOW)
   if( (p = getspnam(argv[1])) == NULL )
      return EXIT_FAILURE;

   user = p->sp_namp;
   pass = p->sp_pwdp;
#else
   if( (p = getpwnam(argv[1])) == NULL )
      return EXIT_FAILURE;

   user = p->pw_name;
   pass = p->pw_passwd;
#endif

   /* Show the informations */
   printf("Encrypted password for %s: %s\n", user, pass);

   return EXIT_SUCCESS;
} /* eof main() */

