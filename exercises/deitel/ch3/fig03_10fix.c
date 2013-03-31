/* Fig. 3.10: fig03_10.c
   Analisi dei risultati dell'esame */
#include <stdio.h>

/* l'esecuzione del programma inizia dalla funzione main */
int main()
{
   /* inizializza le variabili nelle dichiarazioni */
   int passes = 0; /* numero di promozioni */
   int failures = 0; /* numero di bocciature */
   int student = 1; /* conttore degli studenti */
   int result; /* risultato di un esame */

   /* elabora 10 studenti; ciclo controllato da un contatore */
   while ( student <= 10 ) {

      /* sollecita l'utente a inserire i dati e ottiene i valori 
	 da quest'ultimo */
      printf( "Enter result (1=pass,2=fail): ");
      scanf("%d", &result );

      /* se il risultato è 1, incremente il numero di promozioni */
      if ( result == 1 ) {
	 passes = passes + 1;
      } /* fine del ramo if */
      else if ( result == 2 ) { /* altrimenti incremente le bocciature */
         failures = failures + 1;
      } /* fine del raom else */
      else {
	 printf("Valore non corretto (%d)\n", result); 
         continue;
      }

      student = student +1; /* incremente il contatore degli studenti */
   } /* fine del comando while */

   /* fase di terminazione; visualizza il numero di promozioni 
      e di bocciature */
   printf( "Passed %d\n", passes );
   printf( "Failed %d\n", failures );

   /* se più di otto studenti sono stati promossi, visualizza
      "raise tuition" */
   if ( passes > 8 ) {
      printf( "Raise tuition\n" );
   } /* fine del comando if */

   return 0; /* chiusura con successo */

} /* fine della funzione main */



