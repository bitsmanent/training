/* Esercizio 3.21 (Cap. 3)
 *
 * Determina la paga lorda per ogni impiegato
*/

#include <stdio.h>

int main()
{
   int hours;
   float rate;

   printf("Enter # of hours worked (-1 to end): ");
   scanf("%d", &hours);

   while(hours != -1) {
      printf("Enter hourly rate of the worker ($00.00): ");
      scanf("%f", &rate);

      printf("Salary is $");
      if (hours <= 40)
	 printf("%.2f\n\n", rate * hours);
      else
         printf("%.2f\n\n", rate * 40 + rate + rate / 2);

      printf("Enter # of hours worked (-1 to end): ");
      scanf("%d", &hours);
   }

   return 0;
} /* E0F main */

