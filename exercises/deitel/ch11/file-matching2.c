/* Exercise 11.10
 *
 * NOTE: i suppose that the records stored to the
 *       files are in an ascending order sequence.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 29

struct record {
   int account;
   char name[SIZE];
   char address[SIZE];
   int phone;
   double balance; 
   char notes[255];
};

int main(void)
{
   FILE *clients, *trans, *newfile;
   struct record cRec, tRec;
   int found;

   /* open the clients file */
   if( (clients = fopen("oldmast.dat", "r")) == NULL ) {
      printf("%s: cannot open the file\n", "oldmast.dat");
      exit(-1);
   }

   /* open the transactions file */
   if( (trans = fopen("trans.dat", "r")) == NULL ) {
      printf("%s: cannot open the file\n", "trans.dat");
      exit(-1);
   }

   /* open the new archive file */
   if ( (newfile = fopen("newmast.dat", "w")) == NULL ) {
      printf("%s: cannot open the file\n", "newmast.dat");
      exit(-1);
   }

   /* Read the first record */
   fread(&cRec, sizeof(struct record), 1, clients);

   /* loop the clients */
   while( !feof(clients) ) {

      fread(&tRec, sizeof(struct record), 1, trans);

      /* check the transactions */
      while( !feof(trans) && tRec.account <= cRec.account ) {
	 if(tRec.account == cRec.account) {
	    cRec.balance += tRec.balance;
	 }
	 fread(&tRec, sizeof(struct record), 1, trans);
      }
      fwrite(&cRec, sizeof(struct record), 1, newfile);

      rewind(trans);
      fread(&cRec, sizeof(struct record), 1, clients);
   }

   fread(&tRec, sizeof(struct record), 1, trans);

   /* check the mismathed transactions */
   while( !feof(trans) ) {

      rewind(clients);
      fread(&cRec, sizeof(struct record), 1, clients);

      found = 0;

      /* loop the clients */
      while( !feof(clients) && cRec.account <= tRec.account ) {
	 if(cRec.account == tRec.account) {
	    found = 1;
	    break;
	 }
         fread(&cRec, sizeof(struct record), 1, clients);
      }

      if(!found) {
	 printf("Unmatched transaction record for account number %d\n",
	    tRec.account);
      }

      fread(&tRec, sizeof(struct record), 1, trans);
   }

   fclose(clients);
   fclose(trans);
   fclose(newfile);

   return 0;
} /* E0F main */

