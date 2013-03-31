/* Esercizio 5.8 */

#include <stdio.h>
#include <math.h>

int main()
{
   printf("%.1f\n", fabs( 7.5 ));
   printf("%.1f\n", fabs( 0.0 ));
   printf("%.1f\n", ceil( 0.0 ));
   printf("%.1f\n", fabs( -6.4 ));
   printf("%.1f\n", ceil( -6.4 ));
   printf("%.1f\n", ceil( -fabs( -8+floor( -5.5) ) ));

   return 0;
} /* E0F main */

