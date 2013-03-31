/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 3.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/*
 * Determinate the maximum number of open files (fds)
*/
#ifdef OPEN_MAX
static int openmax = OPEN_MAX;
#else
#define OPEN_MAX_GUESS	256
static int openmax = 0;
#endif

/*
 * Functions prototypes
*/
int set_open_max(void);
int my_dup2(int fd1, int fd2);

int
main(void)
{

   /* set the openmax variable */
   if( set_open_max() )
      return EXIT_FAILURE ;

   /*
    * Testing the function
   */
   if( my_dup2(STDOUT_FILENO, 5) == -1 ) {
      perror("my_dup2()");
      return EXIT_FAILURE ; /* Something went wrong */
   }

   /* Write to the new file descriptor */
   if( write(5, "my_dup2()", 9) != 9 ) {
      perror("write()");
      return EXIT_FAILURE ; /* Something went wrong */
   }

   /*
    * File descriptors are implicitally at the end of the program
   */

   return EXIT_SUCCESS ;
} /* eof main() */

/*
 * Set the maximum number of file descriptors.
 * Adapted from the APUE sample program 2.3.
*/
int
set_open_max(void)
{

   if( ! openmax ) {

      errno = 0;

      if( (openmax = sysconf(_SC_OPEN_MAX)) < 0 ) {
         if( ! errno )
	    openmax = OPEN_MAX_GUESS;
	 else
	    return -1;
      }

   }

   return 0;
} /* eof set_open_max() */

/*
 * Duplicate a file descriptor (non atomically)
*/
int
my_dup2(int fd1, int fd2)
{
   int fds_total = 0, *fds_list;

   /* check if are valid file descriptors */
   if( fd1 < 0 || fd1 > openmax || fd2 < 0 || fd2 > openmax ) {
      errno = EBADF;
      return -1;
   }

   /* If the descriptors are not the same then duplicate fd1 to fd2 */
   if( fd1 != fd2 ) {

      /* Allocate the file descriptors container */
      if( (fds_list = calloc(1, openmax * sizeof(int))) == NULL )
         return -1;

      /* close fd2 first, if open */
      (void)close(fd2);

      /* get the duplicated file descriptor number "fd2" */
      while( (fds_list[fds_total] = dup(fd1)) != fd2 )
         ++fds_total;
      
      /* close the others descriptors */
      while( --fds_total >= 0 )
         (void)close(fds_list[fds_total]);

      free(fds_list);

   }

   return fd2;
} /* eof my_dup2() */

