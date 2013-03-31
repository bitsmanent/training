/* Exercise 8.37 */

#include <stdio.h>
#include <string.h>

#define NUMBERS 9

int main(void)
{
   char import[NUMBERS] = { 0 };
   int n = NUMBERS;

   printf("Give me the import: ");
   gets(import);
   while( (int)strlen(import) > NUMBERS ) {
      printf("Error: too many numbers\n");
      printf("Give me the import: ");
      gets(import);
   }

   printf("Protect number: ");
   n -= (int)strlen(import);
   while(n--)
      printf("*");

   printf("%s\n", import);

   return 0;
}

