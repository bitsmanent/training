/* Exercise 5.21 */

void triangle(int, int, int);
void square(int, int, int);

int main()
{
   int n, c, choose = 0;

   while(choose > 4 || choose < 1) {
      printf(
	 "\nFigures:\n\n"
	 "   1: empty triangle\n"
	 "   2: full triangle\n"
	 "   3: empty square\n"
	 "   4: full square\n"
	 "\n"
      );

      printf("Choose a figure number: ");
      scanf("%d", &choose);
   }

   printf("\nGive me height: ");
   scanf("%d", &n);

   getchar(); /* take newline and, of course, ignore it */

   printf("Give me the character: ");
   c = getchar();

   printf("\n");
   switch(choose) {
      case 1:
         triangle(n, c, 0);
	 break;
      case 2:
	 triangle(n, c, 1);
	 break;
      case 3:
	 square(n, c, 0);
	 break;
      case 4:
	 square(n, c, 1);
	 break;
   } /* end switch (choose) */
   printf("\n");

   return 0;
} /* E0F main */

/* Show a triangle of "character" of "height" size */
void triangle(int height, int character, int full)
{
   int i, j, k, x;

   for(i = height - 1, x = 1; i >= 1; x+=2, i--) {
      for(j = 1; j <= i; j++)
	 printf(" ");

      printf("%c", character);

      if(i == height - 1) {
	 printf("\n");
	 continue;
      }

      for(k = x; k > 2; k--)
	 printf("%c", full ? character : ' ');

      printf("%c\n", character);
   }

   /* print the base */
   if(full)
      height = height-- * 2;

   for(i = 1; i <= height ; i++)
      printf("%c%s", character, full ? "" : " ");
   printf("\n");
} /* eof triangle() */

/* Show a square of "character" of "height" size */
void square(int height, int character, int full)
{
   int i, j;

   int base() {
      for(i = full ? height : height / 2 + (!(height % 2) ? 0 : 1); i >= 1; i--)
         printf("%c%s", character, full ? "" : " ");
      printf("\n");
   }

   base(height);
   /* begin square */
   for(i = height - 2; i >= 1; i--) {
      printf("%c", character);
      for(j = 1; j <= height - (full ? 2 : !(height % 2) ? 3 : 2 ); j++)
	 printf("%c", full ? character : ' ');
      printf("%c\n", character);
   }
   /* end square */
   base(height);

} /* eof square() */

