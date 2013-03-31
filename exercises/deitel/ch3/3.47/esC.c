/* Esercizio 3.47 (c) */

#include <stdio.h>

int main()
{
   /* Costanti */
   float e = 1.0; /* e = 1 + ... */
   int x = 1;

   int p_count; /* contatore per la potenza */
   int f_count; /* contatore per il fattoriale */

   int fatt; /* fattoriale */
   int c_fatt; /* copia del fattoriale per il decremento */

   int c_val = 1; /* common value: fattoriale e potenza */

   while(c_val < 5) {
      fatt = c_fatt = c_val; /* Reinizializzo */
      p_count = f_count = 1; /* le variabili. */

      /* elevo x a potenza */
      while(++p_count < c_val)
	 x *= x;

      /* calcolo il fattoriale */
      while(--c_fatt > 1)
	 fatt = --c_fatt;

      /* elevo e a potenza */
      p_count = 1;
      while(++p_count < c_val)
	 e *= e;

      e += (float) x / fatt;

      ++c_val;
   }

   printf("e elevato a x = %.2f\n", e);

   return 0;
} /* E0F main */

