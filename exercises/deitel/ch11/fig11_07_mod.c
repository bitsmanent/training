/* Exercise 11.9 */

/* Fig. 11.7: fig11_07.c
   Reading and printing a sequential file */
#include <stdio.h>

#define SIZE 29

struct record {
   int account;
   char name[SIZE];
   char address[SIZE];
   int phone;
   double balance;
   char notes[255];
};

int main(int argc, char *argv[])
{ 
   FILE *cfPtr;
   struct record recPtr;

   if(argc != 2) {
      printf("Usage: %s <file>\n", argv[0]);
      return -1;
   }

   /* fopen opens file; exits program if file cannot be opened */ 
   if ( ( cfPtr = fopen( argv[1], "r" ) ) == NULL ) {
      printf( "File could not be opened\n" );
   } /* end if */
   else { /* read account, name and balance from file */
      printf( "%-10s%-13s%s\n", "Account", "Name", "Balance" );
      fread(&recPtr, sizeof(struct record), 1, cfPtr);

      /* while not end of file */
      while ( !feof( cfPtr ) ) { 
         printf( "%-10d%-13s%7.2f\n",
            recPtr.account, recPtr.name, recPtr.balance );
         fread(&recPtr, sizeof(struct record), 1, cfPtr);
      } /* end while */

      fclose( cfPtr ); /* fclose closes the file */
   } /* end else */

   return 0; /* indicates successful termination */

} /* end main */

