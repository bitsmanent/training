/* Exercise 7.28 */

/* Fig. 6.22: fig06_22.c
   Double-subscripted array example */
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

/* function prototypes */
void minimum( const int grades[][ EXAMS ], int pupils, int tests );
void maximum( const int grades[][ EXAMS ], int pupils, int tests );
void average( const int setOfGrades[][ EXAMS ], int pupils, int tests );
void printArray( const int grades[][ EXAMS ], int pupils, int tests );

/* function main begins program execution */
int main(void)
{
   /* initialize student grades for three students (rows) */
   const int studentGrades[ STUDENTS ][ EXAMS ] =  
      { { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 } };

   void (*processGrades[4])(const int [][EXAMS], int, int) = {
      printArray, minimum, maximum, average
   };
   int sel;

   while(1) {
      printf("Enter a choice:\n"
	     "  0  Print the array of grades\n"
	     "  1  Find the minimum grade\n"
	     "  2  Find the maximum grade\n"
	     "  3  Print the average on all tests for each student\n"
	     "  4  End program\n");
      printf("Selection: ");
      scanf("%d", &sel);

      if(sel > 4 || sel < 0) {
	 printf("\nInvalid choice: choose another option\n\n");
      }
      else if(sel == 4)
         return 0;
      else
	 break;
   }

   (*processGrades[sel])( studentGrades, STUDENTS, EXAMS ); 

   return 0; /* indicates successful termination */

} /* end main */

/* Find the minimum grade */
void minimum( const int grades[][ EXAMS ], int pupils, int tests )
{
   int i; /* student counter */
   int j; /* exam counter */
   int lowGrade = 100; /* initialize to highest possible grade */

   /* loop through rows of grades */
   for ( i = 0; i < pupils; i++ ) {

      /* loop through columns of grades */
      for ( j = 0; j < tests; j++ ) {

         if ( grades[ i ][ j ] < lowGrade ) {
            lowGrade = grades[ i ][ j ];
         } /* end if */

      } /* end inner for */

   } /* end outer for */

   printf("Lowest grade: %d\n", lowGrade);

} /* end function minimum */

/* Find the maximum grade */
void maximum( const int grades[][ EXAMS ], int pupils, int tests )
{
   int i; /* student counter */
   int j; /* exam counter */
   int highGrade = 0; /* initialize to lowest possible grade */

   /* loop through rows of grades */
   for ( i = 0; i < pupils; i++ ) {

      /* loop through columns of grades */
      for ( j = 0; j < tests; j++ ) {

         if ( grades[ i ][ j ] > highGrade ) {
            highGrade = grades[ i ][ j ];
         } /* end if */

      } /* end inner for */

   } /* end outer for */

   printf("Highest grade: %d\n", highGrade);

} /* end function maximum */

/* Determine the average grade for a particular student */
void average( const int setOfGrades[][ EXAMS ], int pupils, int tests )
{
   int i, j; /* exam counters */
   int total = 0; /* sum of test grades */

   /* total all grades for one student */
   for ( i = 0; i < pupils; i++ ) {
      for( j = 0; j < tests; j++) {
         total += setOfGrades[ i ][ j ];
      }

      printf("The average grade for student %d is %.2f\n",
	 i, (double) total / j);
      total = 0;
   } /* end for */

} /* end function average */

/* Print the array */
void printArray( const int grades[][ EXAMS ], int pupils, int tests )
{
   int i; /* student counter */
   int j; /* exam counter */

   printf( "The array is:\n" );

   /* output column heads */
   printf( "                 [0]  [1]  [2]  [3]" );

   /* output grades in tabular format */
   for ( i = 0; i < pupils; i++ ) {

      /* output label for row */
      printf( "\nstudentGrades[%d] ", i );

      /* output grades for one student */
      for ( j = 0; j < tests; j++ ) {
         printf( "%-5d", grades[ i ][ j ] );
      } /* end inner for */

   } /* end outer for */
   printf("\n");

} /* end function printArray */

