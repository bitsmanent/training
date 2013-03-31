/* Esercizio 3.22 (Cap. 3)
 *
 * Dimostra la differenza tra il predecremento
 * e il postdecremento utilizzando l'operatore --.
*/

#include <stdio.h>

int main()
{
   int i = 10;

   printf("i vale %d: verrà postdecrementata 5 volte..\n", i);
   while(i > 5)
      printf("ciclo: i-- vale %d\n", i--);

   printf("Quì i vale %d: verrà predecrementata altre 5 volte..\n", i);
   while(i > 0)
      printf("ciclo: --i vale %d\n", --i);

   printf("Infine, dopo 2 cicli, i vale %d.\n", i);

   return 0;
} /* E0F main */

