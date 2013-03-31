/*
 * File holes.
 *
 * APUE experimental - Just to understand.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FILE_NAME	"test.hole"
#define BUFSZ		512

int
main(void)
{
   int fd;
   char before[BUFSZ];
   char after[] = "This is the text written after the hole";

   for(fd = 0; fd < BUFSZ; fd++)
      before[fd] = 'X';

   /* open the file */
   if( (fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)) == -1 ) {
      perror("open");
      return EXIT_FAILURE;
   }

   /* write few data */
   if( write(fd, before, sizeof(before)) != sizeof(before) ) {
      perror("write");
      close(fd);
      return EXIT_FAILURE;
   }

   /* seek after the end of file */
   if( lseek(fd, BUFSZ * BUFSZ, SEEK_SET) < 0 ) {
      perror("lseek");
      close(fd);
      return EXIT_FAILURE;
   }

   /* write few data (make the hole) */
   if( write(fd, after, sizeof(after)) != sizeof(after) ) {
      perror("write");
      close(fd);
      return EXIT_FAILURE;
   }

   close(fd); /* close the file */
   
   return EXIT_SUCCESS;
} /* eof main() */

