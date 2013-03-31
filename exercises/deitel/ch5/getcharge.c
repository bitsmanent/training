/* Esercizio 5.9 */

#include <stdio.h>

float calculateCharges(float);

int main()
{
   int i;
   float t_hours = 0.0, t_charge = 0.0;
   float c1_hours, c2_hours, c3_hours;
   float c_charge; /* for all clients */

   for(i = 1; i <= 3; i++) {
      printf("Client %d, get hours: ", i);
      switch(i) {
	 case 1:
            scanf("%f", &c1_hours);
	    break;
	 case 2:
            scanf("%f", &c2_hours);
	    break;
         case 3:
	    scanf("%f", &c3_hours);
	    break;
      } /* end switch (i) */
   } /* end for (i) */

   printf("\nCar\tHours\tCharge\n");
   for(i = 1; i <= 3; i++) {
      switch(i) {
	 case 1:
	    c_charge = calculateCharges(c1_hours);
	    printf("%d\t%.1f\t%.2f\n", i, c1_hours, c_charge); 
	    t_charge += c_charge;
	    t_hours += c1_hours;
	    break;
	 case 2:
	    c_charge = calculateCharges(c2_hours);
	    printf("%d\t%.1f\t%.2f\n", i, c2_hours, c_charge); 
	    t_charge += c_charge;
	    t_hours += c2_hours;
	    break;
	 case 3:
	    c_charge = calculateCharges(c3_hours);
	    printf("%d\t%.1f\t%.2f\n", i, c3_hours, c_charge); 
	    t_charge += c_charge;
	    t_hours += c3_hours;
      } /* end switch (i) */
   } /* end for (i) */

   printf("TOTAL\t%.1f\t%.2f\n", t_hours, t_charge);

   return 0;
} /* E0F main */

/* calcultate client charge */
float calculateCharges(float x) 
{
   /* x = hours
      t = charge */

   float t = 1.50;
   int i;

   if (x > 3.0) {
      for(i = 3; i <= x * 100.0 / 100.0; i++) {
	 t += 0.50;
      }
      if(x - (i - 1))
         t += 0.50;
   }
   else
      t += 0.50;

   if( t > 10.0)
      t = 10.0;

   return t;

} /* E0F calculateChages */

