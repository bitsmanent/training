/* Exercise 11.8 */

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
   FILE *master, *trans;
   struct record rec;

   if( (master = fopen("oldmast.dat", "w")) == NULL ) {
      printf("Shit, i can't open the file %s\n", "oldmast.dat");
      exit(-1);
   }

   if( (trans = fopen("trans.dat", "w")) == NULL ) {
      printf("Oh, fucked filesystem.. i can't open the file %s\n", "trans.dat");
      exit(-1);
   }

   printf("Inserting data for the master file\n");

   printf("Account number (0 to end): ");
   scanf("%d", &rec.account);

   /* writing to the "master" file */
   while( rec.account > 0 ) {
      printf("Name: ");
      scanf("%s", rec.name);
      printf("Balance: ");
      scanf("%lf", &rec.balance);

      fwrite(&rec, sizeof(struct record), 1, master);
      printf("record stored!\n\n");

      printf("Account number (0 to end): ");
      scanf("%d", &rec.account);
   }

   printf("Inserting data for the transactions file\n");

   printf("Avvount number (0 to end): ");
   scanf("%d", &rec.account);

   /* writing to the "trans" file */
   while( rec.account > 0 ) {

      rec.name[0] = '\0'; /* not required */ 

      printf("Balance: ");
      scanf("%lf", &rec.balance);

      fwrite(&rec, sizeof(struct record), 1, trans);
      printf("record stored!\n\n");

      printf("Account number (0 to end): ");
      scanf("%d", &rec.account);
   }

   fclose(master);
   fclose(trans);

   return 0;
} /* E0F main */

