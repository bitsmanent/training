/* Exercise 6.21 */

#include <stdio.h>
#include <stdlib.h>

#define POS 10

int getpost(int, int []);

int main()
{
   int positions[POS+1] = { 0 }; /* positions[0] do a lot of things :-) */
   int c; /* 1 = first class, 2 = economy. */

   srand( time(NULL) ); /* for the flight numbers ;) */

   /* available classes (2 + 1): ac[0] is not a class */
   int ac[3] = { 0, 1, 1 };

   int chclass = 0; /* for auto-change of class check */

   while(1) {

      if(!chclass) {
	 printf("\n"
		"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
	        "American airlines international airport :-)\n"
	        "AIRLINES PRENOTATION SYSTEM! (C)Claudio M.\n"
		"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
                "\nPlease type 1 for \"first class\"\n"
	        "Please type 2 for \"economy\"\n"
	        "Choose: ");
         scanf("%d", &c);
	 printf("\n");
      }
      else
	 --chclass;

      positions[0] = getpos(c, positions);

      if(positions[0] == -1) {
	 printf("The class %d is not exists, choose another class.\n", c);
	 continue;
      }
      else if(positions[0]) {
	 printf("<==================[ BOARDING PAPER ]==================>\n"
		"Class: %d\n"
		"Positions: %d\n"
		"Fly number: *%d\n\n"
		"Thank you for fly with us!\n"
		"Hope you enjoy with our company.\n"
	        "<==================[ BOARDING PAPER ]==================>\n"
		,c, positions[0], 6789 + rand() & 1000);
	 positions[positions[0]] = 1;

         printf("\nPress a key for reserve a flight.\n");
	 getchar(); /* ignore the newline */
         getchar(); /* wait for a key */
      }
      else { /* there are not positions available in the class */
	 ac[c] = 0; 

	 /* check if there is at least one available class */
	 for(ac[0] = 0, positions[0] = 1; positions[0] <= 2; positions[0]++)
	    ac[0] += ac[positions[0]];

	 if(!ac[0]) {
	    printf("Sorry! There are not classes available.\n");
	    printf("Take your car or run ;)\n");
	    break;
	 }

	 while( (positions[0] = getchar()) != 'n' && positions[0] != 'y') { 
	    printf("Class %d is full! Want you try to check class %d?\n"
	           "Choose (y / n): ", c, c == 1 ? 2 : 1);
         }

	 if(positions[0] == 'n') {
	    printf("Next flight leaves in 3 hours\n");
	    break;
	 }
	 c = c == 1 ? 2 : 1;
	 ++chclass;
      }
   } /* end while(1) */
	 
   return 0;
} /* E0F main */

/* Return the first free position of a class */
int getpos(int class, int v[])
{
   if(class != 1 && class != 2) {
      return -1;
   }

   int i; 
   int x = class == 1 ? 1 : 6;
   int y = class == 1 ? 5 : 10;

   for(i = x; i <= y; i++) {
      if(!v[i]) {
	 return i;
      }
   } /* end for (i) */

   return 0;
} /* eof getpos() */

