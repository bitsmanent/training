/* Exercise 5.26 */

/*
Time results with "n <= 100000":

   6: 1 2 3 = 6
   28: 1 2 4 7 14 = 28
   496: 1 2 4 8 16 31 62 124 248 = 496
   8128: 1 2 4 8 16 32 64 127 254 508 1016 2032 4064 = 8128

   166.42s real   159.95s user     0.00s system
*/

#include <stdio.h>

int perfect(int);

int main()
{
   int n, s, f;

   for(n = 1; n <= 100000; n++) {
      if(perfect(n)) {
         printf("%d: ", n);
	 for(s = 1, f = 0; s < n; s++) {
	    if( !(n % s) ) {
	       printf("%d ", s);
	       f += s;
	    }
	 }
	 printf("= %d\n", f);
      }
   } /* end for (n) */

   return 0;

} /* E0F main */

/* check if num is a perfect number */
int perfect(int num)
{
   int i, f_sum = 0;

   /* check its factors */
   for(i = 1; i < num; i++) {
      if( !(num % i) ) {
	 /* num is multiple of i */
	 f_sum += i;
      }
   }

   if(f_sum == num) return 1;

   return 0;
} /* eof perfect() */

