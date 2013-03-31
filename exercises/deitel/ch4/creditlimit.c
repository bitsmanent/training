/* Esercizio 4.17 */

#include <stdio.h>

int main()
{
   int i, account;
   float c_limit, c_saldo;

   for (i = 1; i <= 3; ++i) {
      printf("Account number: ");
      scanf("%d", &account);
      printf("Current credit limit: ");
      scanf("%f", &c_limit);
      printf("Current credit: ");
      scanf("%f", &c_saldo);
    
      printf("\n------------------------\n");
      printf("Account number: %d\n", account);
      printf("New credit limit: %.2f\n", c_limit /= 2);
      printf("Current credit: %.2f\n", c_saldo);
      printf("------------------------\n");

      if ((int) c_saldo > c_limit) {
	 printf("* You are out of limit!\n");
         printf("------------------------\n");
      }
       printf("\n");

   }

   return 0;
} /* E0F main */

