/* Exercise 6.28 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int ison(int, int [], int);

int main(void)
{
   int tree[SIZE] = { 0 };
   int num, p = 0; /* the number and its position */

   int i; /* just a counter */

   srand( time(NULL) );

   for(i = 1; i <= SIZE; i++) {
      num = 1 + rand() % 20;
      if( !ison(num, tree, SIZE) )
	 tree[p++] = num;
   }

   for(i = 0; i < SIZE; i++)
      if(tree[i])
         printf("%d ", tree[i]);

   printf("\n");

   return 0;
} /* E0F main */

/* check if 'n' in on 'v[]'.
 * If yes return its position, else 0 */
int ison(int n, int v[], int s)
{
   int c;

   for(c = 0; c < s; c++)
      if(v[c] == n)
	 return c;

   return 0;
}

