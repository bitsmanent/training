/* Esercizio 4.27
 * Terne pitagoriche: brute force. */

#include <stdio.h>

int main()
{
   int i, j, k;
	
   printf("IPOTENUSA\tCATETO 1\tCATETO 2\n");
   for (i = 1; i < 500; ++i)
      for (j = i ; j > i / 2; --j)
	 for (k = 1; k < j ; ++k)
	    if (i * i == j * j + k * k)
               printf("%d\t\t%d\t\t%d\n", i, j, k);

   return 0;
} /* E0F main */

