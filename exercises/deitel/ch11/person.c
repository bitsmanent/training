/* Exercise 11.11 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REC 100

struct person {
   char lastName[15];
   char firstName[15];
   char age[4];
};

int main(void)
{
   struct person empty = { "unassigned", "", "0" };
   struct person guy = { "unassigned", "", "0" };
   FILE *fd;
   int i;

   if( (fd = fopen("nameage.dat", "w")) == NULL) {
      printf("cannot open the file \"%s\"\n", "nameage.dat");
      exit(-1);
   }

   /* --- A --- */

   /* write the recors */
   for(i = 0; i < REC; i++) {
      fwrite(&empty, sizeof(struct person), 1, fd); 
   }

   /* --- B --- */

   /* insert ten entries of Surname, name and age to the file */
   for(i = 0; i < 10; i++) {
      printf("Surname, name and age: ");
      scanf("%s%s%s", guy.lastName, guy.firstName, guy.age);
      fwrite(&guy, sizeof(struct person), 1, fd); 
   }

   /* --- C --- */

   /* seek to one of the ten latest entries */
   fseek(fd, 100 + rand() % 10 * sizeof(struct person), SEEK_SET);

   fread(&guy, sizeof(struct person), 1, fd);
   if( ! strncmp(guy.lastName, "unassigned", sizeof(guy.lastName)) &&
       ! strncmp(guy.firstName, "", 1) && ! strncmp(guy.age, "", 1) ) {

      printf("No info\n");
      
   }
   printf("\n[update]: Surname, name and age: ");
   scanf("%s%s%s", guy.lastName, guy.firstName, guy.age);
   fwrite(&guy, sizeof(struct person), 1, fd); 

   /* --- D --- */

   fseek(fd, 100 * sizeof(struct person), SEEK_SET);

   for(i = 100; i < 110 && !feof(fd); i++) { /* feof() not required */
      if( strncmp(guy.lastName, "unassigned", sizeof(guy.lastName)) ||
          strncmp(guy.firstName, "", 1) || strncmp(guy.age, "", 1) ) {
	  i = 1;
	  break;
      }
      fread(&guy, sizeof(struct person), 1, fd);
   }

   if(i == 1) {
      fwrite(&empty, sizeof(struct person), 1, fd);
   }
   else {
      printf("No empty records!\n");
   }


   fclose(fd);

   return 0;
} /* E0F main */

