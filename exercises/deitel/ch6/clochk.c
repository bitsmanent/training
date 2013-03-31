/* Exercise 6.15 */

#include <stdio.h>
#define SIZE 20

int bs(int, const int [], int);
void bsort(int [], int);

int main()
{
   int num[SIZE + 1] = { 0 };
   int i, j;
   int c = 1;

   int k;
   for(i = 1; i <= SIZE; i++) {
      do {
	 printf("Give me a number (10-100): ");
	 scanf("%d", &num[0]);
      } while(num[0] < 10 || num[0] > 100);

      bsort(num, SIZE);

      if(!bs(num[0], num, SIZE))
	 printf("New number: %d\n", num[c++] = num[0]);
   } /* end for (i) */

   return 0;
} /* E0F main */

/* Binary search: find (?) key in the array v[] */
int bs(int key, const int v[], int s)
{
   int i, m;
   int low = 1;

   while(low <= s) {
      m = (low + s) / 2;
      if(key == v[m])
	 return m;

      if(key < v[m])
	 s = m - 1;
      else
	 low = m + 1;
   }
   return 0;

} /* eof bs() */

/* Order an array using Bubble Sort algorithm */
void bsort(int v[], int s)
{
   int i, j;
   int t_val, t_val2;

   for(i = 0; i < s; i++) {
      for(j = 1; j < s - i; j++) {
         if(v[j] > v[j + 1]) {
            t_val = v[j];
            v[j] = v[j + 1];
            v[j + 1] = t_val;
         } /* end if */
      } /* end for (j) */

      if(t_val2 == t_val)
         break;
   } /* end for (i) */

} /* eof bsort() */

