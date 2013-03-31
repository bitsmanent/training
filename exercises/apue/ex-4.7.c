/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 4.7
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 8192

int
main(int argc, char *argv[])
{
   int fd, fd2;
   ssize_t size;
   char buf[BUFSIZE] = { 0 };

   /* Arguments check */
   if( argc != 3 ) {
      printf("Usage: %s <source file> <destination file>\n", argv[0]);
      return EXIT_FAILURE;
   }

   /* open the source file */
   if( (fd = open(argv[1], O_RDONLY)) == -1 ) {
      perror("open(source)");
      return EXIT_FAILURE;
   }

   /* open the destination file */
   if( (fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1 ) {
      perror("open(destination)");

      close(fd); /* close the source file */
      return EXIT_FAILURE;
   }

   /* copy the file */
   while( (size = read(fd, buf, 1)) > 0 ) {
      if( *buf && write(fd2, buf, size) != size ) {
         perror("write");
	 break;
      }
   }

   /* read error */
   if( size == -1 )
      perror("read");

   close(fd);
   close(fd2);

   return EXIT_SUCCESS;
} /* eof main() */

