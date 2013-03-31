/* Exercise 7.24 */

#include <stdio.h>

void quicksort(int array[], int sidx, int eidx);
int partition(int array[], int num, int size);
void iswap(int *a, int *b);
void i_pa(int a[], int size);

int main(void)
{
   int a[] = {
      8, 2, 25, 15, 31, 78, 23, 69, 19, 10, 41, 1, 1, 1,
      33, 58, 9, 15, 19, 8, 100, 28, 12, 5, 234, 734, 9,
      23, 12312, 21, 1231, 2123, 21321, 12, 123, 3, 432,
      2, 354, 34, 2, 3, 4, 423, 34, 685, 65, 4, 22, 521
   };

   int size = ( sizeof(a) / sizeof(int) );

   printf("The array before the order:\t");
   i_pa(a, size);

   quicksort(a, 0, size - 1);

   printf("\nThe array after the order:\t");
   i_pa(a, size);

   return 0;
} /* E0F main */

/* Sort an array using the quicksort algorithm */
void quicksort(int array[], int sidx, int eidx)
{
   int newidx;

   if(sidx == eidx)
      return;

   newidx = partition(array, sidx, eidx);

   if(newidx == sidx) {
      quicksort(array, newidx + 1, eidx);
   }
   else if(newidx == eidx) {
      quicksort(array, sidx, newidx - 1);
   }
   else {
      quicksort(array, newidx + 1, eidx);
      quicksort(array, sidx, newidx - 1);
   }

} /* eof quicksort() */

/* Partition a number to an array */
int partition(int a[], int num, int size)
{
   int l = 0, r = size;

   while(1) {

      for( ; r > num; r--) {
         if(a[r] < a[num]) {
	    iswap(&a[r], &a[num]);
	    num = r;
	    break;
         }
      }

      for(; l < num; l++) {
         if(a[l] > a[num]) {
	    iswap(&a[l], &a[num]);
	    num = l;
	    break;
         }
      }

      if(l == r)
	 break;

   }

   return num;

}

/* Swap two element */
void iswap(int *a, int *b)
{
   int hold = *a;
   *a = *b;
   *b = hold;
} /* eof iswap() */

void i_pa(int a[], int size)
{
   int i;

   printf("\n");

   for(i = 1; i <= size; i++) {
      printf("%6d ", a[i - 1]);

      if( !(i % 10) )
	 printf("\n");
   }

} /* end i_pa() */

