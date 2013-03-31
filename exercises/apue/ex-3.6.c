/*
 * Advanced Programming in the UNIX(r) Environment
 *
 * Exercise 3.6
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE	"test"

int
main(void)
{
   int fd;
   char buf[10] = { 0 };
   
   printf("lseek(2) test for RW file with append flag\n\n");

   /* open the file */
   printf("open(2)...");
   if( (fd = open(FILE, O_RDWR | O_APPEND | O_CREAT | O_TRUNC, S_IRWXU)) == -1 ) {
      printf(" KO\n");
      return EXIT_FAILURE;
   }
   printf("OK\n");

   /* write something */
   printf("write(2)...");
   if( write(fd, "{first write call}", 18) != 18 ) {
      printf(" KO\n");
      (void)close(fd);
      return EXIT_FAILURE;
   }
   printf(" OK\n");

   printf("\nTrying to seek 5 bytes from the beginning of the file..\n\n");

   /* move somewhere */
   printf("lseek(2)...");
   if( lseek(fd, 5, SEEK_SET) < 0 ) {
      printf(" KO\n");
      (void)close(fd);
      return EXIT_FAILURE;
   }
   printf(" OK\n");

   /* read something */
   printf("read(2)...");
   if( read(fd, buf, 5) == -1 ) {
      printf(" KO\n");
      (void)close(fd);
      return EXIT_FAILURE;
   }
   printf(" OK\n");

   /* write something, again */
   printf("write(2)...");
   if( write(fd, "[2nd write]", 11) != 11 ) {
      printf(" KO\n");
      (void)close(fd);
      return EXIT_FAILURE;
   }
   printf(" OK\n");

   close(fd);

   printf("\nTest finished. Check the '%s' file.\n", FILE);

   return EXIT_SUCCESS;
} /* eof main() */

