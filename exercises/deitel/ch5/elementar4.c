/* Exercise 5.44 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pok(void);
void pko(void); 

int main()
{
   int n1, n2, num; /* random numbers and user input */
   int level, mode; /* level and mode */
   int mode2; /* mode2 needed for mode 5 */
   int correct = 0; /* counter for correct answer */
   int i; /* only a counter for loops */

   do {
      printf("Choose a level.\n");
      printf(
	 "\t1: one number (easy)\n"
         "\t2: two numbers (medium)\n"
      );

      printf(": ");
      scanf("%d", &level);

   } while( level < 1 || level > 2 );

   level = level == 1 ? 9 : 99; /* set level */

   do {
      printf("\nChoose a mode.\n");
      printf(
	 "\t1: addition (easy)\n"
	 "\t2: removal (medium)\n"
	 "\t3: moltiplication (hard)\n"
	 "\t4: division (very hard)\n"
	 "\t5: two operations (random)\n"
	 );

      printf(": ");
      scanf("%d", &mode);

   } while( mode < 1 || mode > 5 );

   printf("\n");

   for(i = 1; i <= 10; i++) {
      srand( time(NULL) );

      n1 = 1 + rand() % level;
      n2 = 1 + rand() % level;

      if(mode == 5)
	 mode2 = 1 + rand() % 4;
      else mode2 = mode;

      switch(mode2) { /* set mode */
         case 1: /* addition */
	    printf("How much is %d plus %d?\n", n1, n2);
	    printf("Answer: ");
	    scanf("%d", &num);

	    printf("\n");
	    if(num == n1 + n2) {
	       pok();
	       ++correct;
	    }
	    else
	       pko();
	    break;
	 case 2: /* removal */
	    printf("How much is %d minus %d?\n", n1, n2);
	    printf("Answer: ");
	    scanf("%d", &num);

	    printf("\n");
	    if(num == n1 - n2) {
	       pok();
	       ++correct;
	    }
	    else
	       pko();
	    break;
         case 3: /* moltiplication */
            printf("How much is %d times %d?\n", n1, n2);
            printf("Answer: ");
            scanf("%d", &num);

            printf("\n");
            if(num == n1 * n2) {
	       pok();
	       ++correct;
            }
            else
	       pko();
	    break;
	    case 4: /* division */
	       printf("How much is %d divided %d?\n", n1, n2);
	       printf("Answer: ");
	       scanf("%f", &num);

	       printf("\n");
	       if(num == n1 / n2) {
		  pok();
		  ++correct;
	       }
	       else
		  pko();
      } /* end switch (mode) */

      printf("\n\n");

   } /* end for (i) */

   if( (100 * correct) / 10 < 75)
      printf("Please ask your instructor for extra help\n");

   printf("Game over!\n");

   return 0;
} /* E0F main */

/* print a nice string :-) */
void pok(void)
{
   switch(1 + rand() % 4) {
      case 1:
         printf("Very good!");
         break;
      case 2:
         printf("Excellent!");
         break;
      case 3:
         printf("Nice work!");
         break;
      case 4:
         printf("Keep up the good work!");
   }
} /* eof pok() */

/* print a less nice string :| */
void pko(void)
{
   switch(1 + rand() % 4) {
      case 1:
	 printf("No. Please try again.");
	 break;
      case 2:
	 printf("Wrong. Try one more.");
         break;
      case 3:
         printf("Don't give up!");
         break;
      case 4:
         printf("No. Keep trying.");
   } /* end switch */
} /* eof pko() */

