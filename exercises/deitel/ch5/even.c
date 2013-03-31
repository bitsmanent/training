/* Esercizio 5.18 */

#include <stdio.h>

int even(int);

int main()
{
   int num;

   printf("Give me a number (%d to end): ", EOF);
   scanf("%d", &num);
   while(num != EOF) {
      printf("%d ", num);
      if(!even(num))
	 printf("is even\n");
      else
	 printf("is odd\n");

      printf("Give me a number (%d to end): ", EOF);
      scanf("%d", &num);
   } /* end while (num) */

   return 0;
} /* E0F main */

/* check if n is even */
int even(int n)
{
   if( !(n % 2))
      return 0;
   else
      return 1;
} /* eof even() */

