/* Esercizio 5.13 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand(time(NULL));

   printf("1 <= %d <= 2\n", 1 + rand() % 2);
   printf("1 <= %d <= 100\n", 1 + rand() % 100);
   printf("0 <= %d <= 9\n", rand() % 10);
   printf("1000 <= %d <= 1112\n", 1000 + 1 + rand() % 112);
   printf("-1 <= %d <= 3\n", -1 + rand() % 5);
   printf("-3 <= %d <= 11\n", -3 + rand() % 15);

   return 0;
} /* E0F main */

