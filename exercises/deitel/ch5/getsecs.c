/* Esercizio 5.23 */

#include <stdio.h>

int getsecs(int, int, int);

int main()
{
   int h, m, s;
   int t_1, t_2;

   printf("Give me the first time (hh mm ss): ");
   scanf("%d%d%d", &h, &m, &s);
   if( !(t_1 = getsecs(h, m, s)) ) {
      printf("Wrong date: %d:%d:%d\n", h, m, s);
      return -1;
   }

   printf("Give me the first time (hh mm ss): ");
   scanf("%d%d%d", &h, &m, &s);
   if( !(t_2 = getsecs(h, m, s)) ) {
      printf("Wrong date: %d:%d:%d\n", h, m, s);
      return -1;
   }

   printf("Difference in second it: %ds\n", t_1 >= t_2 ? t_1 - t_2 : t_2 - t_1);

   return 0;
} /* E0F main */

/* Count the seconds between 12:00 and "hh:mm:ss" */
int getsecs(int hh, int mm, int ss)
{
   int i;

   if(hh > 12 || (hh == 12 && (mm || ss)) ) {
      printf("Date is deleted!\n");
      return 0;
   }

   /* count seconds from hh to 12 */
   for(i = hh; i < 12; i++) {
      ss += 3600;
   } /* eof for (i) */

   /* count the seconds of mm */
   for(i = mm; i >= 1; i--) {
      ss += 60;
   }

   return 43200 - ss;

} /* eof getsecs() */

