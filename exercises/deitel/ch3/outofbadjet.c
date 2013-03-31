/* Esercizio 3.18 (Cap 3)
 *
 * Determino se il cliente abbia superato
 * il limite di credito sul suo conto.
*/

#include <stdio.h>

int main()
{
   int account; /* Numero cliente */
   float saldoIniz, limiteCred, totArts, totCred;

   printf("Numero di conto (-1 esce): ");
   scanf("%d", &account);

   while(account != -1) {
      printf("Saldo iniziale: ");
      scanf("%f", &saldoIniz);

      printf("Totale articoli in conto: ");
      scanf("%f", &totArts);

      printf("Totale crediti: ");
      scanf("%f", &totCred);

      printf("Limite di credito: ");
      scanf("%f", &limiteCred);

      if ((saldoIniz + totArts - totCred) > limiteCred) {
	 printf("Account:\t%d\n", account);
	 printf("Credit limit:\t%2.f\n", limiteCred);
	 printf("Balance:\t%2.f\n", saldoIniz + totArts - totCred);
	 printf("Credit Limit Exceeded.\n");
      }

     printf("\nNumero di conto (-1 esce): ");
     scanf("%d", &account);

   }

   return 0;

} /* E0F main */

