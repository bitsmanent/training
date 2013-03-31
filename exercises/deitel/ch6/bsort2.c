/* Exercise 6.11 *

/* Bubble Sort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void parray(int [], int);

int main()
{
   int array[SIZE];
   int i, j, t_val;

   srand( time(NULL) );

   /* assign a random value to every element of array[] */
   for(i = 0; i < SIZE; i++) {
      array[i] = 1 + rand() % 999;
   }

   printf("This is the array before order:\n");
   parray(array, SIZE);

   /* bubble sort */
   int t_val2;
   for(i = 0; i < SIZE; i++) {
      for(j = 0; j < SIZE - i; j++) {
	 if(array[j] > array[j + 1]) {
	    t_val = array[j];
	    array[j] = array[j + 1];
	    array[j + 1] = t_val;
	 } /* end if */
      } /* end for (j) */

      if(t_val2 == t_val)
         break;

   } /* end for (i) */

   printf("\nThis is the array after the order:\n");
   parray(array, SIZE);

   printf("\n");

   return 0;
} /* E0F main */

/* print an array */
void parray(int a[], int size)
{
   int i;

   for(i = 0; i < size; i++)
      printf("%d ", a[i]);

   printf("\n");

} /* eof parray() */

