/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 4.19
 *
 * NOTE: the exercise is done assuming PATH_MAX already defined
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>

#define DIRNAME	"ex-4.19_dir"

int
main(void)
{
   int i, levels, umask_save;
   char cwd[PATH_MAX * 2] = { 0 };

   umask_save = umask(0); /* Store the umask value and clear the mask */

   levels = PATH_MAX / sizeof(DIRNAME) + 1;

   printf("Creating a %d-levels deep directories tree..", levels);
   fflush(stdout);

   /* Create a deep directories tree */
   for(i = 0; i < levels; i++) {

      /* Create the directory */
      if( mkdir(DIRNAME, 0700) == -1 ) {
         perror("\nmkdir");
	 break;
      }

      /* Enter the directory */
      if( chdir(DIRNAME) == -1 ) {
         perror("\nchdir");
	 break;
      }

   }

   /* Get the working directory on the leaf directory */
   if( getcwd(cwd, sizeof(cwd)) == NULL ) {
      perror("\ngetcwd");
      printf("\tdirectory: %d; full path length: %d\n", i, sizeof(DIRNAME)*i);
   }

   printf(" done\n");

   (void)umask(umask_save); /* Restore the umask value (pretty useless here) */
   
   return EXIT_SUCCESS;
} /* eof main() */

