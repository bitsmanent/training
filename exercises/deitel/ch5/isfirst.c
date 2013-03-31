/* Exercise 5.27 */

int isfirst(int);

int main()
{
   int n;

   for(n = 1; n <= 10000; n += 2) {
      if(isfirst(n))
	 printf("%d\t", n);
   } /* end for (n) */

   printf("\n");
   return 0;
} /* E0F main */

/* check if num is first */
int isfirst(int num)
{
   int i;

   for(i = 2; i <= 9; i++) {
      if( (!(num % i) && (num != i)) || num == 2 )
         return 0;
   } /* end for (i) */

   return 1;
} /* eof isfirst() */

