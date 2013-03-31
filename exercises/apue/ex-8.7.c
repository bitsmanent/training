/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 8.7
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

void pflags(int fd);

int
main(void)
{
   DIR *dir;
   const char *dirname = "/";
   int fd;

   /* open the directory stream */
   if( (dir = opendir(dirname)) == NULL ) {
      perror("opendir");
      return EXIT_FAILURE;
   }
   pflags(dirfd(dir)); /* close-on-exec flag status */

   /* Open the directory for reading */
   if( (fd = open(dirname, O_RDONLY)) == -1 ) {
      closedir(dir);
      perror("open");
      return EXIT_FAILURE;
   }

   pflags(fd); /* close-on-exec flag status */

   close(fd);     /* close the descriptor */
   closedir(dir); /* close the stream */

   return EXIT_SUCCESS; /* Make C compiler happy! */
} /* eof main() */

void
pflags(int fd)
{
   int flags;

   if( (flags = fcntl(fd, F_GETFD)) != -1 )
      printf("close-on-exec: %s\n", (flags & FD_CLOEXEC ? "on" : "off"));
   
} /* eof pflags() */

