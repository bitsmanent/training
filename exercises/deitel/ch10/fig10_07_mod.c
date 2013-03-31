/* Exercise 10.11 */

/* Fig. 10.7: fig10_07.c
   Printing an unsigned integer in bits */
#include <stdio.h>

typedef unsigned u_int; /* Portable definition */
void displayBits( u_int value ); /* prototype */

int main(void)
{ 
   u_int x; /* variable to hold user input */

   printf( "Enter an unsigned integer: " );
   scanf( "%lu", &x );

   displayBits( x );
   
   return 0; /* indicates successful termination */

} /* end main */

/* display bits of an unsigned integer value */
void displayBits( u_int value )
{ 
   u_int c; /* counter */

   /* define displayMask and left shift 31 bits */
   u_int displayMask = 1 << 31; 

   printf( "%10lu = ", value );

   /* loop through bits */ 
   for ( c = 1; c <= 32; c++ ) { 
      putchar( value & displayMask ? '1' : '0' );
      value <<= 1; /* shift value left by 1 */   

      if ( c % 8 == 0 ) { /* output space after 8 bits */
         putchar( ' ' );
      } /* end if */

   } /* end for */

   putchar( '\n' );
} /* end function displayBits */

