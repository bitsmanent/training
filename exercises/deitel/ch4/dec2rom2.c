/* Esercizio 4.33 */
 
#include <stdio.h>

int main()
{
   int i, num = 1984;

   /* migliaia */
   for(i = num / 1000; i >= 1; --i) {
      printf("M");
      num -= 1000;
   }

   /* cinque-centinaia */
   if (num / 500) {
      printf("D");
      num -= 500;
   }

   /* centinaia */
   for(i = num / 100; i >= 1; --i) {

      if (i == 4) {
	 printf("CD");
	 num -= 400;
	 break;
      }
      printf("C");
      num -= 100;
   }

   /* stampo le decine */
   if (num / 10 >= 5) {
      printf("L");
      num -= 50;
   }

   /* stampo il resto delle decine */
   for(i = num / 10; i >= 1; --i) {
      if (i == 4) {
	 printf("XL");
	 num -= 40;
	 break;
      }
      printf("X");
      num -= 10;
   }

   /* cinquetti */
   if (num >= 5) {
      printf("V");
      num -= 5;
   }

   for(i = num ; i >= 1 ; --i) {
      if (i == 4) {
	 printf("IV");
	 num -= 4; /* not required */
	 break;
      }
      printf("I");
      num -= 1; /* not required */
   }

   printf("\n");

   return 0;
} /* E0F main */

