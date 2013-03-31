/* Exercise 5.29 */

int gcd(int, int);

int main()
{
   int num1, num2;

   printf("Give me two numbers: ");
   scanf("%d%d", &num1, &num2);

   printf("GCD: %d\n", gcd(num1, num2));

   return 0;
} /* E0F main */

/* return GCD between two numbers */
int gcd(int x, int y)
{
   int i;

   for(i = x; i >= 2; i--) {
      if( !(x % i) && !(y % i) )
	 return i;
   }
   return 1;

} /* eof gcd() */

