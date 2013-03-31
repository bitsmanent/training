/*
 * Esercizio 3.46
 * Questo software cifra un intero di 4 cifre.
 *
 * Algoritmo: sostituisce ogni cifra con il resto della
 * divisione di (la somma di quella cifra più 7) per 10.
 * In seguito, scambia la prima cifra con la terza e la
 * seconda con la quarta.
 *
 * NOTA: 7 cifra, 3 decifra.
*/

#include <stdio.h>

int main()
{
   int num;
   int p, s, t, q;

   printf("Inserire l'intero da cifrare: ");
   scanf("%d", &num);

   p = num / 1000 % 10; /* primo */ 
   s = num / 100 % 10; /* secondo */
   t = num / 10 % 10; /* terzo */
   q = num / 1 % 10; /* quarto */

   p = (p + 7) % 10;
   s = (s + 7) % 10;
   t = (t + 7) % 10;
   q = (q + 7) % 10;

   printf("Numero cifrato: %d%d%d%d\n", t, q, p, s);

   return 0;
} /* E0F main */

