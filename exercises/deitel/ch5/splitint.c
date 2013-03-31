/* Exercise 5.22 */

#include <stdio.h>

void splint(int); /* splint :-) */

int main()
{
   int num = 0;

   while(num < 1 || num > 32767) {
      printf("Give me an integer between 1 and 32767: ");
      scanf("%d", &num);
   }

   splint(num);

   return 0;
} /* E0F main */

/* Split an integer in the range 1-32767 */
void splint(int n)
{
   int i, check = 0;

   for(i = 10000; i >= 1; i /= 10) {
      if(n / i % 10 != 0)
	 check = 1;
      if(!check)
	 continue;

      printf("%d  ", n / i % 10);
   }
   printf("\n");

} /* eof splint() */

