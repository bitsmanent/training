/* Exercise 5.31 */

#include <stdio.h>
#include <stdlib.h>

int flip(void);

int main()
{
   int i;
   int heads, tails;
   heads = tails = 0;

   srand( time(NULL) );

   for(i = 1; i <= 100; i++) {
      if(flip())
	 ++heads;
      else
	 ++tails;
   } /* end for (i) */

   printf("Results:\n");
   printf("Heads: %d\nTails: %d\n", heads, tails);

   return 0;
} /* E0F main */

/* simulate a currency launch */
int flip(void)
{
   int n = rand() % 2;

   if(n)
      printf("Heads\n");
   else
      printf("Tails\n");

   return n;
} /* eof flip() */

