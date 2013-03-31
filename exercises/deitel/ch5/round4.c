/* Esercizio 5.11 */

#include <stdio.h>
#include <math.h>

float roundToInteger(float);
float roundToTenths(float);
float roundToHundreths(float);
float roundToThousandths(float);

int main()
{
   float num = 21.199;

   do {
      printf("%.3f %.3f %.3f %.3f\n",
	 roundToInteger(num),
	 roundToTenths(num),
	 roundToHundreths(num),
	 roundToThousandths(num));

      printf("Give me a number (0 to end): ");
      scanf("%f", &num);
   } while(num * 100 / 100);

   return 0;
} /* E0F main */

float roundToInteger(float n)
{
   return floor( n * 1 + .5) / 1;
} /* eof roundToInteger */

float roundToTenths(float n)
{
   return floor( n * 10 + 5.) / 10;
} /* eof roundToTenths */

float roundToHundreths(float n)
{
   return floor( n * 100 + .5) / 100;
} /* eof roundToHundreths */

float roundToThousandths(float n)
{
   return floor( n * 1000 + .5) / 1000;
} /* eof roundToThousandths */

