/*
 * Esercizio 3.46
 * Questo software decifra un intero di 4 cifre.
 *
 * Algoritmo: sostituisce ogni cifra con il resto della
 * divisione di (la somma di quella cifra più 3) per 10.
 * In seguito, scambia la prima cifra con la terza e la
 * seconda con la quarta.
 *
 * NOTA: 3 decifra, 7 cifra.
*/

#include <stdio.h>

int main()
{
   int num;
   int p, s, t, q;

   printf("Inserire l'intero da decifrare: ");
   scanf("%d", &num);

   p = num / 1000 % 10; /* primo */ 
   s = num / 100 % 10; /* secondo */
   t = num / 10 % 10; /* terzo */
   q = num / 1 % 10; /* quarto */

   p = (p + 3) % 10;
   s = (s + 3) % 10;
   t = (t + 3) % 10;
   q = (q + 3) % 10;

   printf("Numero decifrato: %d%d%d%d\n", t, q, p, s);

   return 0;
} /* E0F main */

