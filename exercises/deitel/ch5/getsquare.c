/* Esercizio 5.19 */

void square(int);

int main()
{
   int n;

   printf("Give me the side: ");
   scanf("%d", &n);

   square(n);

   return 0;
} /* E0F main */

/* Print a square of "side" size */
void square(int side)
{
   int i, j;

   for(i = side; i >= 1; i--) {
      for(j = side; j >= 1; j--)
	 printf("*");
      printf("\n");
   }

} /* eof square() */

