/* Esercizio 4.29 */

/*
 * a) !( x < 5 ) && !( y >= 7)
 * b) !( a == b ) || !( g != 5 )
 * c) !( ( x <= 8 ) && ( Y > 4 ) )
 * d) !( ( i > 4 ) || ( j <= 6 ) )
 **********************************
 * a) !( x < 5 || y >= 7 )
 * b) !( a == b && g != 5 )
 * c) ( !( x <= 8 ) || !( Y > 4 ) )
 * d) ( !( i > 4 ) && !( j <= 6 ) )
*/

#include <stdio.h>

int main()
{
   int i = 3, j = 5, k = 9;

   printf("Expression\t\t\tvalue\n");
   printf("!( %d < 5 ) && !( %d >= 7)\t%d\n", i, j, !(i<5)&&!(j>=7));
   printf("!( %d < 5 || %d >= 7 )\t\t%d\n\n", i, j, !(i<5||j>=7)); 

   printf("!( ( %d == %d ) || !( %d != 5 )\t%d\n", i, j, k, !((i==j)||!(k!=5)));
   printf("!( %d == %d && %d != 5 )\t\t%d\n\n", i, j, k, !(i==j&&k!=5));

   printf("!( ( %d <= 8 ) && ( %d > 4 ) )\t%d\n", i, j, !((i<=8)&&(j>4)));
   printf("( !( %d <= 8 ) || !( %d > 4 ) )\t%d\n\n", i, j, (!(i<=8)||!(j>4)));

   printf("!( ( %d > 4 ) || ( %d <= 6 ) )\t%d\n", i, j, !((k>4)||(j<=6)));
   printf("( !( %d > 4 ) && !( %d <= 6 ) )\t%d\n\n", i, j, (!(i>4)&&!(j<=6)));



   return 0;
} /* E0F main */

