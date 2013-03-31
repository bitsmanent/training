/* Exercise 6.19 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../practice/mt19937ar.c"

int dice(void);

#define LAUNCHES 36000
#define LIMIT 50

int main()
{
   int i, t;
   int results[13] = { 0 };

   init_genrand( time(NULL ) );
   //srand( time(NULL) );

   for(i = 1; i <= LAUNCHES; i++)
      ++results[dice()];

   printf("Print the results (* = not sense)\n");
   printf("There is a tollerance of \"n [-+] %d\"\n\n", LIMIT);
   for(i = 2; i <= 12; i++) {
      printf("%d:\t%d", i, results[i]);

      if(i <= 7) {
	 t = LAUNCHES / 36 * (i - 1);

	 if(results[i] < t - LIMIT || results[i] > t + LIMIT)
	    printf("\t*\tout of range (%d-%d)", t - LIMIT, t + LIMIT);
      }
      else {
	 t = LAUNCHES / 36 * ((14 - i) - 1);

	 if(results[i] < t - LIMIT || results[i] > t + LIMIT)
	    printf("\t*\tout of range (%d-%d)", t - LIMIT, t + LIMIT);

      }
      printf("\n");
   }

   return 0;
} /* E0F main */

int dice(void)
{
   //int d1 = 1 + rand() % 6;
   //int d2 = 1 + rand() % 6;
   int d1 = 1 + genrand_int32() % 6;
   int d2 = 1 + genrand_int32() % 6;
   return d1 + d2;
}

