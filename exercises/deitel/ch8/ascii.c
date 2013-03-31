/* Exercise 8.25 */

#include <stdio.h>

int main(void)
{
   int code;

/* Exercise 8.25: first step. 
   printf("Give me the ASCII code: ");
   scanf("%d", &code);

   printf("The character is: %c\n", code);
*/

   /* Exercise 8.25: final step. */
   printf("ASCII code\tASCII character\n");
   for(code = 0; code <= 255; code++) {
      printf("%.3d\t%c\n", code, code);
   }

   return 0;
} /* E0F main */

