/* Esercizio 2.19 (Cap. 2)
   Visualizza la somma, media, prodotto,
   minore e maggiore di 3 interi. */

#include <stdio.h>

int main()
{
   int a, b, c;
   int largest, smallest;

   printf("Input three different integers: ");
   scanf("%d%d%d", &a, &b, &c);

   printf("Sum is %d\n", a + b + c);
   printf("Average is %d\n", (a + b + c) / 3);
   printf("Product is %d\n", a * b * c);
 
   /* Trovo il > e il < di tre numeri (a, b, c) */

   if (a > b)
      largest = a;
 
   if (a < b)
      largest = b;
 
   if (c > largest)
      largest = c;

   if (a < b)
      smallest = a;

   if (a > b)
      smallest = b;

   if (c < smallest)
      smallest = c;

   printf("Smallest: %d\n", smallest);
   printf("Largest: %d\n", largest);

   return 0; 
     
} /* E0F main */

