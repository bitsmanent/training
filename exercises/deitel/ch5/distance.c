/* Exercise 5.45 */

#include <stdio.h>

double distance(double, double, double, double);

int main()
{
   double a, b, c, d;

   printf("Give me x1 x2 y1 y2: ");
   scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

   printf("Distance is %.2f.\n", distance(a, b, c, d));

   return 0;
} /* E0F main */

/* Calculate the distance between two points */
double distance(double x1, double y1, double x2, double y2)
{
   return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); /* taken from the web */
} /* eof distance() */

