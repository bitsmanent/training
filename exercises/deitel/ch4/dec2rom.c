/* Esercizio 4.33 */

#include <stdio.h>

int main()
{
   int i, j;

   printf("Decimale\tRomani\n");

   for(i = 900; i < 1000; ++i) {

      printf("%d\t\t", i);

      if (i < 10)
	 j = i;
      else
	 j = i / 1 % 10;

      switch(i / 10 % 10) { /* decine */
         case 1:
            printf("X");
            break;
         case 2:
            printf("XX");
            break;
         case 3:
            printf("XXX");
            break;
         case 4:
            printf("XL");
            break;
         case 5:
            printf("L");
            break;
         case 6:
            printf("LX");
            break;
         case 7:
            printf("LXX");
            break;
         case 8:
            printf("XXC");
            break;
         case 9:
           printf("XC");
           break;
      } /* end of switch (decine) */

      switch(j) { /* unità */
	 case 1:
	    printf("I");
	    break;
	 case 2:
	    printf("II");
	    break;
	 case 3:
	    printf("III");
	    break;
	 case 4:
	    printf("IV");
	    break;
	 case 5:
	    printf("V");
	    break;
	 case 6:
	    printf("VI");
	    break;
	 case 7:
	    printf("VII");
	    break;
	 case 8:
	    printf("VIII");
	    break;
	 case 9:
	    printf("IX");
	    break;

      } /* end of switch (unit) */

      printf("\n");
   }

   printf("%d\t\tC\n", i);

   return 0;
} /* E0F main */

