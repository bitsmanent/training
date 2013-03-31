/* Exercise 9.7 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void)
{
   int i, tot = 0, num[SIZE];

   /* srand( time(NULL) ); */

   /* Initialize the array */
   for(i = 0; i < SIZE; i++) {
      num[i] = 1 + rand() % 1000;
   }

   /* Print the table */
   for(i = 0; i < SIZE; i++) {
      tot += printf("%d", num[i]);
      printf("\t%d\n", tot);
   }

   return 0;
} /* E0F main */

