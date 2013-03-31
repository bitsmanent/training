/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 4.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int
main(int argc, char *argv[])
{
   int		i;
   struct stat	buf;
   char		*ptr;

   for(i = 1; i < argc; i++) {
      printf("%s: ", argv[i]);
      /*
       * Do not use lstat(2)
      */
      if(stat(argv[i], &buf) < 0) {
         perror("stat");
	 continue;
      }

      if( S_ISREG(buf.st_mode))
         ptr = "regular";
      else if( S_ISDIR(buf.st_mode))
         ptr = "directory";
      else if( S_ISCHR(buf.st_mode))
         ptr = "character special";
      else if( S_ISBLK(buf.st_mode))
         ptr = "block special";
      else if( S_ISFIFO(buf.st_mode))
         ptr = "fifo";
#ifdef S_ISLNK
      else if( S_ISLNK(buf.st_mode))
         ptr = "symbolic link";
#endif
#ifdef S_ISSOCK
      else if( S_ISDIR(buf.st_mode))
         ptr = "socket";
#endif
      else
         ptr = "** unknown mode **";

      printf("%s\n", ptr);
   }

   return EXIT_FAILURE;
} /* eof main() */

