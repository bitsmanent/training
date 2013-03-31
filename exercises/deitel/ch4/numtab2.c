/* Esercizio 4.34 */

#include <stdio.h>
#include <math.h>

int main()
{
   int num, c_num;
   int base; /* start from base 2 (binary) */
   int i, j, p, check;

   for(num = 1; num <= 256; num++) {
      printf("%d%3s", num, " ");

      /* print equivalent in "base" */
      for(i = 1; i <= 4; i++) {

         /* dynamic base */
	 if(i == 2) /* ignore base 4 */
	    continue;
	 base = pow(2, i);

         /* found the values order.. */
         for(j = 0; pow(base, j) <= num; j++) {
	    p = pow(base, j);
         } /* ..and print the symbols one for one */
         c_num = num;
         for(j = p; j >= 1; j /= base) {

	    if(base == 16 && c_num / j >= 10 && c_num / j <= 15) {
	    
	       switch(c_num / j) {
		  case 10:
		     printf("A");
		     break;
		  case 11:
		     printf("B");
		     break;
		  case 12:
		     printf("C");
		     break;
		  case 13:
		     printf("D");
		     break;
		  case 14:
		     printf("E");
		     break;
		  case 15:
		     printf("F");

	       } /* end switch (c_num / j) */

	       continue;
	    } /* end if (hex) */

            printf("%d", c_num / j);
	    c_num %= j;
         } /* end for (j) */

	 printf("%3s", " ");
      } /* end for (i) */

      printf("\n");
   } /* end for (num) */

   return 0;
} /* E0F main */

