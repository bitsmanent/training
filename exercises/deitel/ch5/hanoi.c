/* Exercise 5.39 */

#include <stdio.h>

int hanoi(int, int, int, int);

int main()
{
   int d = 4; /* disks number */

   printf("Total moves: %d\n", hanoi(d, 1, 3, 2));

   return 0;
} /* E0F main */


/* Move the disks of the Hanoi towers */ 
int hanoi(int disks, int p_src, int p_dst, int p_tmp)
{
   static int moves = 0;
   ++moves;

   if(disks == 1) {
      printf("%d => %d\n", p_src, p_dst);
   }
   else {
      /* 1. Move n - 1 disks from pole 1 to 2, using the 3 as temp pole */
      /* 2. Move the latest disk (largest) from pole 1 to 3 */
      /* 3. Move the n - 1 disks from pole 2 to 3, using the 1 as temp pole */

      hanoi(disks - 1, p_src, p_tmp, p_dst);
      printf("%d => %d\n", p_src, p_dst);
      hanoi(disks - 1, p_tmp, p_dst, p_src);
   }

   return moves;
} /* eof hanoi() */

