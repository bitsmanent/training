/* Exercise 5.43 */

#include <stdio.h>

int main()
{
   static int count = 1;

   printf("%d\n", count++);
   main();

   return 0;
} /* E0F main */

