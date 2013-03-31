/* Exercise 6.22 */

#include <stdio.h>

#define VEND 4
#define PROD 5

int main()
{
   double sales[PROD + 1][VEND + 1] = { 0 };
   int v, p;
   double t;

   while(1) {
      printf("\nEnter new monthly vendor ticket.\n\n");
      printf("Vendor ID (%d to end): ", EOF);
      scanf("%d", &v);

      if( (v >= 1 && v <= VEND) || v == EOF )
	 break;
      else
	 printf("Invalid vendor ID: %d\n"
	        "Please check your vendor and try again.\n", v);
   }

   while(v != EOF) {

      while(1) {
         printf("Product ID: ");
         scanf("%d", &p);

	 if(p < 1 || p > PROD)
	    printf("Invalid product ID: %d\n"
		   "Please check your product and try again.\n", p);
         else
	    break;
      }

      while(1) {
         printf("Monthly total for this product: ");
         scanf("%lf", &t);

	 if( t < 0 )
	    printf("Invalid value: %d\n", t);
	 else
	    break;
      }

      sales[p][v] += t;

      while(1) {
         printf("\nEnter new monthly vendor ticket.\n\n");
         printf("Vendor ID (%d to end): ", EOF);
         scanf("%d", &v);

         if( (v >= 1 && v <= VEND) || v == EOF )
	    break;
         else
	    printf("Invalid vendor ID: %d\n"
	           "Please check your vendor and try again.\n", v);
      }
   }

   printf("\nThe results for this run are the follow:\n");

   /* print the header (cols - vendors) */
   printf("\nV:");
   for(v = 1; v <= VEND; v++)
      printf("\t V0%d\t", v);
   printf("\t TOT\n\n");

   /* sum the rows and the cols for the total */
   /* of each product and each vendor. */
   for(p = 1; p <= PROD; p++) {
      t = 0;
      printf("P%d:\t", p);
      for(v = 1; v <= VEND; v++) {
	 t += sales[p][v];
	 printf("$%.2f\t\t", sales[p][v]);
      }
      printf("$%.2f\n", t);
      t = 0;
   }
   printf("\nTOT\t");

   /* print the totals of all products for each vendor */

   sales[0][0] = 0; /* total of *all* products for *all* vendors */

   for(v = 1; v <= VEND; v++) {
      t = 0;
      for(p = 1; p <= PROD; p++) {
	 t += sales[p][v];
      }
      printf("$%.2f\t\t", t);
      sales[0][0] += t;
   }
   printf("$%.2f\n\n", sales[0][0]);

   return 0;
} /* E0F main */

