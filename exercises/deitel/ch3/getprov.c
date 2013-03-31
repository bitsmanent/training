/* Esercizio 3.19 (Cap. 3)
 *
 * Calcolo il salario settimanale degli
 * operai di un'azienda chimica
*/

#include <stdio.h>

int main()
{
   float lorde;

   printf("Vendite lorde (-1 esce): ");
   scanf("%f", &lorde);

   while((int)lorde != -1) {
      printf("Salario: $%.2f\n\n", lorde * 9 / 100 + 200);
      printf("Vendite lorde (-1 esce): ");
      scanf("%f", &lorde);
   }

   return 0;
} /* E0F main */

