/* Esercizio 5.14 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i;

   srand( time(NULL) );

   /* 2 4 6 8 10 */
   while((i = 2 + rand() % 10) % 2) ;
   printf("2 4 6 8 10: %d\n", i);

   /* 3 5 7 9 11 */
   while( !( (i = 3 + rand() % 9) % 2) ) ;
   printf("3 5 7 9 11: %d\n", i);

   /* 6 10 14 18 22 */
   while( (i = 6 + rand() % 17) % 4 != 2) ;
   printf("6 10 14 18 22: %d\n", i);

   return 0;
} /* E0F main */

