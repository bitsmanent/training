/* Exercise 8.41 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF 30
#define SIZE 8

void prompt(const char * const debitor,
            const char * const address,
	    const char * const account,
	    const double money, const int delay);

int main(void)
{
   char debitor[BUF], address[BUF], account[SIZE], money[SIZE];
   int delay;

   printf("Debitor's (name and surname): ");
   gets(debitor);

   printf("Debitor's address: ");
   gets(address);

   printf("Account number: ");
   gets(account);

   printf("Due money: ");
   gets(money);

   printf("How many months of delay: ");
   scanf("%d", &delay);

   prompt(debitor, address, account, atof(money), delay);

   return 0;
} /* E0F main */


void prompt(const char * const debitor,
            const char * const address,
	    const char * const account,
	    const double money, const int delay)
{
   printf("\n----- Letter [%d] -----\n\n", delay >= 5 ? 5 : delay);
   switch(delay >= 5 ? 5 : delay) {
      case 1:
	 printf("Hello %s,\n\t"
		"we are writing to you because you have one month of delay\n"
		"in the payment of our products. Please, it supplies first\n"
		"possible! We remember you some data stuff:\n\n"
		"\tYour account number: %s\n"
		"\tYour address: %s\n"
		"\tQuantity to pay: %.2f\n"
		"\n"
		"We are waiting for your reply, in the while give you\n",
		debitor, account, address, money);
	 break;
      case 2:
	 printf("Letter.. (priority low)\n");
	 break;
      case 3:
	 printf("Letter.. (priority medium)\n");
	 break;
      case 4:
	 printf("Letter.. (priority high)\n");
	 break;
      case 5:
	 printf("Letter.. (priority very high)\n");
	 break;
   }
   printf("\nBest regards\n\nClaudio M. corporation\n12534, Madison DC\nbla..\n");
   printf("\n----- End letter -----\n");

} /* eof prompt() */

