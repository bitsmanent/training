/* Esercizio 5.3 */

#include <stdio.h>
#include <math.h>

int main()
{
   printf("Expr\t\tBook\t\tCheck\n");

   /* sqrt(3) */
   printf("sqrt(900.0)\t30.0\t\t%.1f\n", sqrt(900.0));
   printf("sqrt(9.0)\t3.0\t\t%.1f\n", sqrt(9.0));
   printf("\n");

   /* exp(3) */
   printf("exp(1.0)\t2.178282\t%f\n", exp(1.0));
   printf("exp(2.0)\t7.389056\t%f\n", exp(2.0));
   printf("\n");
   
   /* log(3) */
   printf("log(2.718282)\t1.0\t\t%.1f\n", log(2.718282));
   printf("log(7.389056)\t2.0\t\t%.1f\n", log(7.389056));
   printf("\n");

   /* log10(3) */
   printf("log10(1.0)\t0.0\t\t%.1f\n", log10(1.0));
   printf("log10(10.0)\t1.0\t\t%.1f\n", log10(10.0));
   printf("log10(100.0)\t2.0\t\t%.1f\n", log10(100.0));
   printf("\n");

   /* fabs(3) */
   printf("fabs(5.0)\t5.0\t\t%.1f\n", fabs(5.0));
   printf("fabs(0.0)\t0.0\t\t%.1f\n", fabs(0.0));
   printf("fabs(-5.0)\t-5.0\t\t%.1f\t*\n", fabs(-5.0)); /* diff */
   printf("\n");

   /* ceil(3) */
   printf("ceil(9.2)\t10.0\t\t%.1f\n", ceil(9.2));
   printf("ceil(-9.9)\t-9.0\t\t%.1f\n", ceil(-9.9));
   printf("\n");
   
   /* floor(3) */
   printf("floor(9.2)\t9.0\t\t%.1f\n", floor(9.2));
   printf("floor(-9.8)\t-10.0\t\t%.1f\n", floor(-9.8));
   printf("\n");

   /* pow(3) */
   printf("pow(2, 7)\t128.0\t\t%.1f\n", pow(2, 7));
   printf("pow(9, .5)\t3.0\t\t%.1f\n", pow(9, .5));
   printf("\n");

   /* fmod(3) */
   printf("fmod(13.657, 2.333)\t1.992\t%.3f\n", fmod(13.657, 2.333));
   printf("\n");

   /* sin(3) */
   printf("sin(0.0)\t0.0\t\t%.1f\n", sin(0.0));
   printf("\n");

   /* cos(3) */
   printf("cos(0.0)\t1.0\t\t%.1f\n", cos(0.0));
   printf("\n");
   
   /* tan(3) */
   printf("tan(0.0)\t0.0\t\t%.1f\n", tan(0.0));
   printf("\n");

   return 0;
} /* E0F main */

