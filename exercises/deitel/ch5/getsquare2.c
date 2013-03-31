/* Esercizio 5.20 */

#include <stdio.h>

void square(int, int);

int main()
{
   int n, c;

   printf("Give me the side: ");
   scanf("%d", &n);

   getchar(); /* take newline and, of course, ignore it */

   printf("Give me the character: ");
   c = getchar();

   square(n, c);

   return 0;
} /* E0F main */

/* Print a square of "side" size */
void square(int side, int fillCharacter)
{
   int i, j;

   for(i = side; i >= 1; i--) {
      for(j = side; j >= 1; j--)
	 printf("%c", fillCharacter);
      printf("\n");
   }

} /* eof square() */

