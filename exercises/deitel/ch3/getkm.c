/* Esercizio 3.17 (Cap. 3)
 * Mostra i Km per litro di ogni tanta e, infine, di tutte le tange assieme.
 *
 -*- Pseudo-codice -*-
 Primo raffinamento:
    Prende i Km percorsi e i litri utilizzati per ogni pieno.
    Calcola i Km per litro di ogni pieno 
    Calcola i Km per litro totali

  Secondo raffinamento:
    Inizializzo il totale dei Km
    Inizializzo il totale dei Litri

    prendi il numero dei litri (o il valore dummy)
    prendi il numero dei Km

    Finche' non viene immesso il valore dummy
       dividi i km inseriti per i litri inseriti
       stampa il risultato
       salva la somma dei litri
       salva la somme dei Km

       prendi il numero dei litri (o il valore dummy)
       se non e' stato inserito il valore dummy
         prendi il numero dei Km

    dividi il totale dei Km per il totale dei Litri
    stampa il risultato
 -*- Fine Pseudo-codice -*-
*/

#include <stdio.h>

int main()
{
   int tot_km=0, km; /* Kilometri */
   float tot_litri=0, litri; /* Litri */

   printf("Numero di litri utilizzati (-1, esce): ");
   scanf("%f", &litri);

   /* Calcolo i Km/l per il pieno corrente */
   while(litri != -1) {
      printf("Numero di Km percorsi: ");
      scanf("%d", &km);
      tot_litri += litri;
      tot_km += km;

      printf("Km percorsi per litro: %f\n\n", km / litri);

      printf("Numero di litri utilizzati (-1, esce): ");
      scanf("%f", &litri);
   }

   /* Calcolo i Km/l per il totale dei pieni */
   printf("Totale Km/l: %f\n", tot_km / tot_litri);


} /* E0F main */

