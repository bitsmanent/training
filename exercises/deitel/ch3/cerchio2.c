/* Esercizio 2.20 (Cap. 2)
   Leggo il raggio di un cerchio e calcolo il diametro,
   la circonferenza e l'aria dello stesso */

#include <stdio.h>

int main()
{
   float raggio;

   printf("Raggio del cerchio: ");
   scanf("%f", &raggio);

   printf("Diametro: %.2f\n", raggio * 2.0);
   printf("Circonferenza: %.2f\n", 3.14159 * 2 * raggio);
   printf("Area %.2f\n", raggio*raggio * 3.14159);

   return 0; 

} /* E0F main */

