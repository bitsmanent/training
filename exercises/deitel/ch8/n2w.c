/* Exercise 8.38 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

void printw(double n);
void pnumz(int num, int kind);

double tonum(char *s);

int main(void)
{
   char number[SIZE] = { 0 };
   double n;

   printf("Give me a number: ");
   gets(number);
   while( (int)strlen(number) > SIZE ) {
      printf("Error: too many numbers\n");

      printf("Give me a number: ");
      gets(number);
   }

   n = tonum(number);

   printw(n);

   printf("\n");

   return 0;
} /* E0F main */

/* convert from "1,234.56" format to 1234.56 */
double tonum(char *s)
{
   int i, num[SIZE] = { 0 };
   double n = 0, x = 1;
   char string[SIZE], *tokp;

   strcpy(string, s);

   tokp = strtok(string, ",");
   while( tokp != NULL ) {
      for(i = 0; tokp[i] != '\0' && !ispunct((int)tokp[i]); i++) {
	 num[(int)n++] = (int)tokp[i] - '0';
	 x *= 10;
      }

      tokp = strtok(NULL, ",");
   }
   x /= 10;
   n = 0;

   for(i = 0; (int)x && i < SIZE * 2; i++) {
      n += num[i] * x;
      x /= 10;
   }

   x = 1;

   strtok(s, "."); /* Before '.' */
   tokp = strtok(NULL, "."); /* After the '.' */
   if(tokp != NULL) {
      for(i = 0; tokp[i] != '\0'; i++) {
	 x *= 0.1;
         n += (tokp[i] - '0') * x;
      }
   }

   return n;

} /* eof tonum() */

/* print a number in letters (1) */
void printw(double n)
{
   int k = 4, x = 1000000000, num;

   do {
      num = (int)n / x % 1000;

      if(num) {
         pnumz((int)n / x % 1000, k);
      }

      --k;

   } while( x /= 1000 );

   /* Floating numbers */
   if(n - (int)n)
      printf(" virgola %.0f", (n - (int)n) * 100); 
} /* eof printw() */

/* print a number in letters (2) */
void pnumz(int num, int kind)
{
   switch(num / 100 % 10) {
      case 2:
	 printf("due");
	 break;
      case 3:
	 printf("tre");
	 break;
      case 4:
	 printf("quattro");
	 break;
      case 5:
	 printf("cinque");
	 break;
      case 6:
	 printf("sei");
	 break;
      case 7:
	 printf("sette");
	 break;
      case 8:
	 printf("otto");
	 break;
      case 9:
	 printf("nove");
	 break;
   }

   if( (num / 100 % 10) )
      printf("cento");

   switch(num / 10 % 10) {
      case 1:
	 switch(num % 10) {
	    case 0:
	       printf("dieci");
	       break;
	    case 1:
	       printf("un");
	       break;
	    case 2:
	       printf("do");
	       break;
	    case 3:
	       printf("tre");
	       break;
	    case 4:
	       printf("quattor");
	       break;
	    case 5:
	       printf("quin");
	       break;
	    case 6:
	       printf("se");
	       break;
	    case 7:
	       printf("diciassette");
	       break;
	    case 8:
	       printf("diciotto");
	       break;
	    case 9:
	       printf("diciannove");
	       break;
	 }

	 if( (num % 10) < 7 && ( num % 10 ) )
	    printf("dici");

	 break;
      case 9:
	 printf("nov");
	 break;
      case 8:
	 printf("ott");
	 break;
      case 7:
	 printf("sett");
	 break;
      case 6:
	 printf("sess");
	 break;
      case 5:
	 printf("cinqu");
	 break;
      case 4:
	 printf("quar");
	 break;
      case 3:
	 printf("trenta");
	 break;
      case 2:
	 printf("venti");
	 break;
   }

   if( (num / 10 % 10) >= 4 )
      printf("anta");

   if( (num % 10 == 8 && num != 8) ||
       ((num % 10) == 1 && (num != 1 && num / 10 % 10 != 1) ) )
      printf("\b");

   if(num / 10 % 10 != 1) { /* If is not [10,19] */
      switch(num % 10) {
         case 1:
	    if (kind == 4 && num == 1)
	       printf("un");
	    else if(kind == 3 && num == 1)
	       printf("un");
	    else if(kind == 2 && num == 1)
	       printf("mille");
	    else
	       printf("uno");
	    break;
         case 2:
	    printf("due");
	    break;
         case 3:
	    printf("tre");
	    break;
         case 4:
	    printf("quattro");
	    break;
         case 5:
	    printf("cinque");
	    break;
         case 6:
	    printf("sei");
	    break;
         case 7:
	    printf("sette");
	    break;
         case 8:
	    printf("otto");
	    break;
         case 9:
	    printf("nove");
	    break;
      }
   } /* end if */

   switch(kind) {
      case 4:
	 if( !(num % 100) || num % 100 > 1 )
	    printf("miliardi");
	 else
	    printf("miliardo");
	 break;
      case 3:
	 if( !(num % 100) || num % 100 > 1 )
	    printf("milioni");
	 else
	    printf("milione");
	 break;
      case 2:
	 if(num > 1)
	    printf("mila");
	 break;
   }
} /* eof pnumz() */

