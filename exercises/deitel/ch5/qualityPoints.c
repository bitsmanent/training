/* Exercise 5.30 */

#include <stdio.h>

int qualityPoints(int);

int main()
{
   int average;

   printf("Give me your average: ");
   scanf("%d", &average);

   printf("Your score is %d.\n", qualityPoints(average));

   return 0;
} /* E0F main */

/* return a score depending of average */
int qualityPoints(int avr)
{
   if(avr > 100) /* He/she is a genius :-) */
      return 100;

   if(avr >= 90 && avr <= 100)
      return 4;
   else if(avr >= 80 && avr <= 89)
      return 3;
   else if(avr >= 70 && avr <= 79)
      return 2;
   else if(avr >= 60 && avr <= 69)
      return 1;
   else
      return 0;
} /* eof qualityPoints() */

