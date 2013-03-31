/* Exercise 11.16 */

#include <stdio.h>
#include <stdlib.h>

#define BUF 255

int main(void)
{
   FILE *fd;

   if( (fd = fopen("datasize.dat", "w")) == NULL) {
      printf("%s: cannot open the file\n", "datasize.dat");
      exit(-1);
   }

   fprintf(fd, "%-30s%4s\n", "Data type", "Size");
   fprintf(fd, "%-30s%4d\n", "char", sizeof(char));
   fprintf(fd, "%-30s%4d\n", "unsigned char", sizeof(unsigned char));
   fprintf(fd, "%-30s%4d\n", "short int", sizeof(short int));
   fprintf(fd, "%-30s%4d\n", "unsigned short int", sizeof(unsigned short int));
   fprintf(fd, "%-30s%4d\n", "int", sizeof(int));
   fprintf(fd, "%-30s%4d\n", "unsigned int", sizeof(unsigned int));
   fprintf(fd, "%-30s%4d\n", "long int", sizeof(long int));
   fprintf(fd, "%-30s%4d\n", "unsigned long int", sizeof(unsigned long int));
   fprintf(fd, "%-30s%4d\n", "float", sizeof(float));
   fprintf(fd, "%-30s%4d\n", "double", sizeof(double));
   fprintf(fd, "%-30s%4d\n", "long double", sizeof(long double));

   return 0;
} /* E0F main */

