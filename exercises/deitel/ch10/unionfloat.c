/* Exercise 10.8 */

#include <stdio.h>

union floatingPoint {
   float f;
   double d;
   long double x;
} fp;

int main(void)
{
   printf("Float double long_double: ");
   scanf("%f%lf%Lf", &fp.f, &fp.d, &fp.x);

   printf("float: %f\ndouble: %f\nlong double: %Lf\n", fp.f, fp.d, fp.x);

   return 0;
} /* E0F main */

