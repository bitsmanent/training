/* Esercizio 4.19 */

#include <stdio.h>

int main()
{
   int productid = 0, quantity;
   int prod1 = 0, prod2 = 0, prod3 = 0, prod4 = 0, prod5 = 0; /* product list */

   printf("Product ID: ");
   scanf("%d", &productid);

   while(productid != EOF) {
      printf("Day's quantity: ");
      scanf("%d", &quantity);

      switch(productid) {
	 case 1:
	    prod1 += quantity;
	    break;
	 case 2:
	    prod2 += quantity;
	    break;
	 case 3:
	    prod3 += quantity;
	    break;
	 case 4:
	    prod4 += quantity;
	    break;
	 case 5:
	    prod5 += quantity;
	    break;

	 /* questi caratteri..
	 case '\n':
	 case '\t':
	 case ' ': 
	    break;
	 ..verranno ignorati. */

	 default:
	    printf("Il prodotto inserito non è valido!\n");
	    printf("Verificare l'ID e riprovare.\n"); 
	    break;
      }
      printf("\nProduct ID: ");
      scanf("%d", &productid);
   }

   printf("Total products price: $%.2f\n", (2.98 * prod1) + (4.50 * prod2) + \
	 (9.98 * prod3) + (4.49 * prod4) + (6.87 * prod5));

   return 0;
} /* E0F main */

