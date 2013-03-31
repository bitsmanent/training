/* Exercise 6.14 */

#include <stdio.h>
#define SIZE 100

/* function prototypes */
void mean( const int answer[] );
void median( int answer[] );
void mode( int freq[], const int answer[] ) ;
void bubbleSort( int a[] );
void printArray( const int a[] );

/* function main begins program execution */
int main()
{
   int frequency[ 10 ] = { 0 }; /* initialize array frequency */
   
   /* initialize array response */
   int response[ SIZE ] =             
      { 0, 8, 8, 9, 8, 9, 8, 9, 8, 9,
        7, 8, 9, 9, 9, 8, 9, 8, 9, 8,
        6, 9, 8, 9, 3, 9, 8, 9, 8, 9,
        7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
        6, 7, 8, 9, 8, 9, 9, 8, 9, 2,
        7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
        5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
        7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
        7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
        4, 5, 6, 1, 6, 5, 7, 8, 7 };

   /* process responses */
   mean( response );
   median( response );
   mode( frequency, response );

   return 0; /* indicates successful termination */

} /* end main */

/* calculate average of all response values */
void mean( const int answer[] )
{
   int j; /* counter for totaling array elements */
   int total = 0; /* variable to hold sum of array elements */

   printf( "%s\n%s\n%s\n", "********", "  Mean", "********" );

   /* total response values */
   for ( j = 0; j < SIZE; j++ ) {
      total += answer[ j ];
   } /* end for */

   printf( "The mean is the average value of the data\n"
           "items. The mean is equal to the total of\n"
           "all the data items divided by the number\n"
           "of data items ( %d ). The mean value for\n"
           "this run is: %d / %d = %.4f\n\n",
           SIZE, total, SIZE, (  double  ) total / SIZE );
} /* end function mean */

/* sort array and determine median element's value */
void median( int answer[] )
{
   printf( "\n%s\n%s\n%s\n%s", 
           "********", " Median", "********", 
           "The unsorted array of responses is" );

   printArray( answer ); /* output unsorted array */

   bubbleSort( answer ); /* sort array */

   printf( "\n\nThe sorted array is" );
   printArray( answer ); /* output sorted array */

   /* display median element */

   if( !(SIZE % 2) )
      /* if the number is pair */
      printf("\n\nThe median is the mean of the two middle elements\n"
	     "%d and %d of the sorted %d element array.\n"
	     "For this run the median is %d\n\n",
                answer[SIZE / 2], answer[SIZE / 2 + 1], SIZE,
                (answer[SIZE / 2] + answer[SIZE / 2 + 1]) / 2 );
   else
      printf( "\n\nThe median is element %d "
              "of the sorted %d element array.\n"
              "For this run the median is %d\n\n",
              SIZE / 2, SIZE, answer[ SIZE / 2 ] );

} /* end function median */

/* determine most frequent response */
void mode( int freq[], const int answer[] )
{
   int rating; /* counter for accessing elements 1-9 of array freq */
   int j; /* counter for summarizing elements 0-98 of array answer */
   int h; /* counter for diplaying histograms of elements in array freq */
   int largest = 0; /* represents largest frequency */
   int p_mode = 0; /* represents the mode clone */
   int modeValue = 0; /* respesents most frequent response */

   printf( "\n%s\n%s\n%s\n", 
           "********", "  Mode", "********" );

   /* initialize frequencies to 0 */
   for ( rating = 1; rating <= 9; rating++ ) {
      freq[ rating ] = 0;
   } /* end for */

   /* summarize frequencies */
   for ( j = 0; j < SIZE; j++ ) {
      ++freq[ answer[ j ] ];
   } /* end for */

   /* output headers for result columns */
   printf( "%s%11s%19s\n\n%54s\n%54s\n\n",
           "Response", "Frequency", "Histogram",
           "1    1    2    2", "5    0    5    0    5" );

   /* output results */
   for ( rating = 1; rating <= 9; rating++ ) {
      printf( "%8d%11d          ", rating, freq[ rating ] );

      /* keep track of mode value and largest frequency value */
      if ( freq[ rating ] > largest ) {
         largest = freq[ rating ];
         modeValue = rating;
      } /* end if */
      else if(freq[ rating ] == largest) {
	 /* There is a pair of modes */
	 p_mode = rating;
      }

      /* output histogram bar representing frequency value */
      for ( h = 1; h <= freq[ rating ]; h++ ) {
         printf( "*" );
      } /* end inner for */

      printf( "\n" ); /* being new line of output */
   } /* end outer for */

   /* display the mode value */
   printf("The mode is the most frequent value.\n");
   if(freq[p_mode] == freq[modeValue])
      printf("For this run the modes are %d and %d which"
	     " occurred %d times.\n", modeValue, p_mode, largest );
   else
      printf("For this run the mode is %d which occurred"
      " %d times.\n", modeValue, largest );

} /* end function mode */

/* function that sorts an array with bubble sort algorithm */
void bubbleSort( int a[] )
{
   int pass; /* pass counter */
   int j;    /* comparison counter */
   int hold; /* temporary location used to swap elements */

   /* loop to control number of passes */
   for ( pass = 1; pass < SIZE; pass++ ) {

      /* loop to control number of comparisons per pass */
      for ( j = 0; j < SIZE - 1; j++ ) {

         /* swap elements if out of order */
         if ( a[ j ] > a[ j + 1 ] ) {
            hold = a[ j ];
            a[ j ] = a[ j + 1 ];
            a[ j + 1 ] = hold;
         } /* end if */

      } /* end inner for */

   } /* end outer for */

} /* end function bubbleSort */

/* output array contents (20 values per row) */
void printArray( const int a[] )
{
   int j; /* counter */

   /* output array contents */
   for ( j = 0; j < SIZE; j++ ) {

      if ( j % 20 == 0 ) { /* begin new line every 20 values */
         printf( "\n" );
      } /* end if */

      printf( "%2d", a[ j ] );
   } /* end for */

} /* end function printArray */

