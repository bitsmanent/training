/* Esercizio 4.30 (2) */

#include <stdio.h>

int main()
{
   int grade;
   int aCount = 0, bCount = 0, cCount = 0, dCount = 0, fCount = 0;

   printf("Enter the letter grades.\n");
   printf("Enter the EOF chatacter to end input.\n");

   while (( grade = getchar()) != EOF ) {

      if (grade == 'A' || grade == 'a') {
         ++aCount;
	 continue;
      }
      if (grade == 'B' || grade == 'b') {
	 ++bCount;
	 continue;
      }
      if (grade == 'C' || grade == 'c') {
	 ++cCount;
	 continue;
      }
      if (grade == 'D' || grade == 'd') {
	 ++dCount;
	 continue;
      }
      if (grade == 'F' || grade == 'f') {
	 ++fCount;
	 continue;
      }
      if (grade == '\n' || grade == '\t' || grade == ' ') 
	 continue;

      printf("Incorrect letter grade entered.");
      printf("Enter a new grade.\n");

   } /* end of while */

   printf("Totals for each letter grade are:\n");
   printf("A: %d\n", aCount);
   printf("B: %d\n", bCount);
   printf("C: %d\n", cCount);
   printf("D: %d\n", dCount);
   printf("F: %d\n", fCount);

   return 0;
} /* E0F main */

