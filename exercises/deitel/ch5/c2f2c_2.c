/* Exercise 5.24 */

#include <stdio.h>

double celsius(double);
double fahrenheit(double);

int main()
{
   double i, j;
   int line = 9; /* number of entries for line */

   /* print 1st table */
   printf("\t\t\tFrom °C to °F (1-100)\n\n");
   for(i = 0.0; i < 100 ; i += line) {
      printf("°C:\t");
      for(j = i; j < i + line && j <= 100; j++)
	 printf("%.1f\t", j);

      printf("\n°F:\t");
      for(j = i; j < i + line && j <= 100; j++) {
	 printf("%.1f\t", fahrenheit(j));
      }
      printf("\n");
   }

   /* print 2nd table */
   printf("\n\t\t\tFrom °F to °C (32-212)\n\n");
   for(i = 32; i <= 212; i += line) {
      printf("°F:\t");
      for(j = i; j < i + line && j <= 212; j++)
	 printf("%.1f\t", j);

      printf("\n°C:\t");
      for(j = i; j < i + line && j <= 212; j++)
	 printf("%.1f\t", celsius(j));

      printf("\n");
   }

   return 0;
} /* E0F main */

/* convert from Celsius to Fahrenheit */
double celsius(double fahrenheit)
{
   /* °C=(5/9)x(°F-32) */
   return (5.0 / 9.0) * (fahrenheit - 32);
} /* eof celsius() */

/* convert from Fahrenheit to Celsius */
double fahrenheit(double celsius)
{
   /* °F=(9/5)°C+32 */
   return (9.0 / 5.0) * celsius + 32;
} /* eof fahrenheit() */

