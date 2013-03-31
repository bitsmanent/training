/* Exercise 6.10 */

#include <stdio.h>

#define BASE 200 /* base pay */
#define XC 9 /* percentage */
#define I_VAL 10 /* intervals */

int main()
{
   int interval[I_VAL] = { 0 }; /* interval[0] == current total */

   printf("Enter your gross total (%d to end): ", EOF);
   scanf("%d", &interval[0]);

   while(interval[0] != EOF) {
      interval[0] = BASE + interval[0] * XC / 100;
      printf("\nYour pay is $%d\n\n", interval[0]);

      if(interval[0] >= 1000)
         ++interval[1];
      else
         ++interval[interval[0] / 100 % 10];

      printf("Enter your gross total (%d to end): ", EOF);
      scanf("%d", &interval[0]);
   }

   printf("Results:\n");

   for(interval[0] = 2; interval[0] < I_VAL; interval[0]++) {
      printf("$%d to $%d: %d\n",
	 interval[0] * 100, interval[0] * 100 + 99, interval[interval[0]]);
   }
   printf("More of $%d: %d\n", 1000, interval[1]);

   return 0;
} /* E0F main */

