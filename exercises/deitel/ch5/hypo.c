/* Esercizio 5.15 */

#include <stdio.h>
#include <math.h>

double hypotenuse(double, double);

int main()
{
   int i;
   double side1, side2;

   for(i = 1; i <= 3; i++) {
      printf("Give me sides (s1 s2): ");
      scanf("%lf%lf", &side1, &side2);

      printf("Side1\tSide2\tHypotenuse\n");
      printf("%.1f\t%.1f\t%.1f\n", side1, side2, hypotenuse(side1, side2));
   }

   return 0;
} /* E0F main */

double hypotenuse(double x, double y)
{
   return sqrt(x*x + y*y);
} /* eof hypotenuse() */
