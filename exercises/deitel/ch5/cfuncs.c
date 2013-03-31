/* Exercise 5.49 */

#include <stdio.h>
#include <math.h>

int main()
{
   int i;

   printf("\n\t\tPrint a lot of (math?) tables\n\n");

   /* sqrt(), exp() and log() */
   for(i = 1; i <= 10; i++) {
      printf("sqrt(%.2f) == %.2f\t", (double)i, sqrt((double)i));
      printf("exp(%.2f) == %.2f\t", (double)i, exp((double)i));
      printf("log(%.2f) == %.2f\n", (double)i, log((double)i));
   }

   printf("\n");

   /* fabs(), ceil() and floor() */
   for(i = 1; i <= 10; i++) {
      printf("fabs(%.2f) == %.2f\t", (double)i, fabs((double)i));
      printf("ceil(%.2f) == %.2f\t", (double)i, ceil((double)i));
      printf("floor(%.2f) == %.2f\n", (double)i, floor((double)i));
   }

   printf("\n");

   /* pow() and fmod() */
   for(i = 1; i <= 10; i++) {
      printf("pow(%.1f, %d) == %.2f\t\t", (double)i, 3, pow( (double)i, 3) );
      printf("fmod(%.2f, 3) == %.2f\n", (double)i, fmod( (double)i, 3) );
   }

   printf("\n");

   /* sin(), cos() and tan() */ 
   for(i = 1; i <= 10; i++) {
      printf("sin(%.2f) == %.2f\t", (double)i, sin((double)i));
      printf("cos(%.2f) == %.2f\t", (double)i, cos((double)i));
      printf("tan(%.2f) == %.2f\n", (double)i, tan((double)i));
   }

   return 0;
} /* E0F main */

