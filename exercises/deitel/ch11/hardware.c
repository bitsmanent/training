/* Exercise 11.12 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REC 100
#define LEN 30

struct hwlist {
   int id;
   char product[LEN];
   int quantity;
   double price;
};

int main(void)
{
   FILE *fd;
   struct hwlist blank_t = { 0, "blank", 0, 0.0 };
   struct hwlist list_t = blank_t;
   char string[LEN];
   int i;

   /* open the file */
   if( (fd = fopen("hardware.dat", "w")) == NULL ) {
      printf("cannot open the file %s\n", "hardware.dat");
      exit(-1);
   }

   /* create the empty records */
   for(i = 1; i <= REC; i++) {
      list_t.id = i;
      fwrite(&list_t, sizeof(struct hwlist), 1, fd);
   }

   /*   S T A R T   O F   B A S E   D A T A   */

   list_t.id = 3;
   fseek(fd, (list_t.id - 1) * sizeof(struct hwlist), SEEK_SET);
   strncpy(list_t.product, "Smerigliatrice elettrica", 25);
   list_t.quantity = 7;
   list_t.price = 57.98;
   fwrite(&list_t, sizeof(struct hwlist), 1, fd);

   list_t.id = 17;
   fseek(fd, (list_t.id - 1) * sizeof(struct hwlist), SEEK_SET);
   strncpy(list_t.product, "Martello", 9);
   list_t.quantity = 76;
   list_t.price = 11.99;
   fwrite(&list_t, sizeof(struct hwlist), 1, fd);

   list_t.id = 24;
   fseek(fd, (list_t.id - 1) * sizeof(struct hwlist), SEEK_SET);
   strncpy(list_t.product, "Sega da traforo", 16);
   list_t.quantity = 21;
   list_t.price = 11.00;
   fwrite(&list_t, sizeof(struct hwlist), 1, fd);

   list_t.id = 39;
   fseek(fd, (list_t.id - 1) * sizeof(struct hwlist), SEEK_SET);
   strncpy(list_t.product, "Falciatrice", 12);
   list_t.quantity = 3;
   list_t.price = 79.50;
   fwrite(&list_t, sizeof(struct hwlist), 1, fd);

   list_t.id = 56;
   fseek(fd, (list_t.id - 1) * sizeof(struct hwlist), SEEK_SET);
   strncpy(list_t.product, "Sega elettrica", 15);
   list_t.quantity = 18;
   list_t.price = 99.99;
   fwrite(&list_t, sizeof(struct hwlist), 1, fd);

   list_t.id = 68;
   fseek(fd, (list_t.id - 1) * sizeof(struct hwlist), SEEK_SET);
   strncpy(list_t.product, "Giravite", 9);
   list_t.quantity = 106;
   list_t.price = 6.99;
   fwrite(&list_t, sizeof(struct hwlist), 1, fd);

   list_t.id = 77;
   fseek(fd, (list_t.id - 1) * sizeof(struct hwlist), SEEK_SET);
   strncpy(list_t.product, "Martello da fabbro", 19);
   list_t.quantity = 11;
   list_t.price = 21.50;
   fwrite(&list_t, sizeof(struct hwlist), 1, fd);

   list_t.id = 83;
   fseek(fd, (list_t.id - 1) * sizeof(struct hwlist), SEEK_SET);
   strncpy(list_t.product, "Chiave inglese", 15);
   list_t.quantity = 34;
   list_t.price = 7.50;
   fwrite(&list_t, sizeof(struct hwlist), 1, fd);

   /*   E N D   O F   B A S E   D A T A   */

   freopen("hardware.dat", "r+", fd);

   while(1) {
      printf( /* Menu */
         "\nChoose an action\n\n"
         "\t1. Edit a record\n"
         "\t2. Delete a record\n"
         "\t3. Show all records\n"
         "\t4. Exit\n"
	 "\nChoose: "
      ); /* end menu */
      scanf("%d", &i);

      if(i == 4)
	 break;

      printf("\n");

      switch(i)
      {
	 case 1: /* Edit a record */
	    printf("Insert a product ID: ");
	    scanf("%d", &i);

	    printf("\n");

	    fseek(fd, (i - 1) * sizeof(struct hwlist), SEEK_SET); 
	    fread(&list_t, sizeof(struct hwlist), 1, fd);

	    printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n\n",
	       list_t.id, list_t.product, list_t.quantity, list_t.price);

	    printf("Insert the new data or '-1' to leave unchanged\n\n");

	    printf("ID: %d (unchangable)\n", list_t.id);
	    printf("Name [%s]: ", list_t.product);
	    fscanf(stdin, "%s", string);

	    if( strncmp(string, "-1", 2) ) {
	       strncpy(list_t.product, string, sizeof(list_t.product));
	    }

	    printf("Quantity [%d]: ", list_t.quantity);
	    fscanf(stdin, "%s", string);
	    if( strncmp(string, "-1", 2) ) {
	       list_t.quantity = atoi(string);
	    }

	    printf("Price [%.2f]: ", list_t.price);
	    fscanf(stdin, "%s", string);

	    if( memcmp(string, "-1", 2) ) {
	       list_t.price = atof(string);
	    }

	    fseek(fd, -1 * sizeof(struct hwlist), SEEK_CUR); 
	    fwrite(&list_t, sizeof(struct hwlist), 1, fd);

	    break;
         case 2: /* Delete a record */
	    printf("Insert a product ID: ");
	    scanf("%d", &i);

	    printf("\n");

	    fseek(fd, (i - 1) * sizeof(struct hwlist), SEEK_SET); 
	    fread(&list_t, sizeof(struct hwlist), 1, fd);

	    if(
	       !memcmp(list_t.product, "blank", 5) ||
	       list_t.quantity
	    ) {
	       printf("Cannot delete product number %d.\n", list_t.id);
	       break;
	    }

	    printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n\n",
	       list_t.id, list_t.product, list_t.quantity, list_t.price);

	    printf("Are you sure (y/n)?: ");
	    fscanf(stdin, "%s", string);

	    printf("\nProduct number %d has ", list_t.id);

	    if( !memcmp(string, "y", strlen(string)) ) {
	       list_t = blank_t;
	       list_t.id = i;
	       fseek(fd, -1 * sizeof(struct hwlist), SEEK_CUR);
	       fwrite(&list_t, sizeof(struct hwlist), 1, fd);
	    }
	    else
	       printf("NOT ");

	    printf("been deleted.\n");

	    break;
	 case 3: /* Show all records */
	    rewind(fd);

	    printf("\n%-10s%-30s%-15s%-10s\n",
	       "ID", "Product", "Quantity", "Price");

	    for(i = 0; i < 60; i++)
	       printf("-");
	    printf("\n");

	    i = 0;
	    fread(&list_t, sizeof(struct hwlist), 1, fd);
	    while( !feof(fd) ) {
	       if( memcmp(list_t.product, "blank", 5) ) { 
	          printf("%-10d%-30s%-15d%-10.2f\n",
		     list_t.id, list_t.product, list_t.quantity, list_t.price);
	       }
	       else {
	          fread(&list_t, sizeof(struct hwlist), 1, fd);
		  continue;
	       }
	       fread(&list_t, sizeof(struct hwlist), 1, fd);

	       if( !(++i % 10) ) {
		  if(i == 10) getchar();
		  printf(
		     "\nPress return to continue "
		     "(or q and return to end)..\n"
		  );
		  string[0] = getchar();

		  if(string[0] == 'q')
		     break;
	       }
	    }

	    printf("\n");

	    break;
	 default:
	    printf("Invalid choose, please retry.\n");
      }

   }

   fclose(fd);

   return 0;
} /* E0F main */

