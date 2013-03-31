/* Exercise 9.4 */

#include <stdio.h>

int main(void)
{
   unsigned int num = 40000;
   int hex, hour, minute, second;
   char s[] = "This is a practice string", *ptr;

   printf("\n%-15.8u\n\n", num);

   printf("Hex value: ");
   scanf("%i", &hex);
   printf(": %i\n", hex);

   printf("\n%+d\n", 200);
   printf("%d\n", 200);

   printf("\n%#x\n", 100);

   ptr = s;
   while( *ptr != 'p' && ptr != NULL )
      printf("%c", *ptr++);

   printf("\n\n%09.3f\n", 1.234);

   printf("\nTime: ");
   scanf("%d%*c%d%*c%d%*c", &hour, &minute, &second);
   printf("hour[%d] minute[%d] second[%d]\n", hour, minute, second);

   printf("\nstring: ");
   scanf("\"%[^\"]s", s);
   printf("string: %s\n", s);

   printf("\nTime[2]: ");
   scanf("%*c%d:%d:%d", &hour, &minute, &second);
   printf("%d %d %d\n", hour, minute, second);

   return 0;
} /* E0F main */
 
