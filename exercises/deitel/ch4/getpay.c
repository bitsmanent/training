/* Esercizio 4.28 */

#include <stdio.h>

int main()
{
   int code = 0, w_time, arts; /* code, ore lavorative e arts */
   int a_code = 0; 
   float paga;

   printf("\nInserire codice di pagamento (-1 esce): ");
   scanf("%d", &code);
   while(code != EOF) {

      switch(code) {
	 case 1:
	    printf("\n-+- MANAGER -+-\n");
	    printf("\nCodice di pagamento: %d\n", code);
	    printf("Paga settimanale: $350.00\n");

	    break;
	 case 2:
	    printf("\n-+- LAVORATORI AD ORE -+-\n\n");

	    printf("Ore lavorative: ");
	    scanf("%d", &w_time);
	    printf("Paga oraria fissa: ");
	    scanf("%f", &paga);

            /* calcolo la paga */
	    if (w_time <= 40)
	       paga *= w_time;
	    else
	       paga *= 40 + w_time + paga / 2 * (w_time - 40);
	       
	    printf("\nCodice di pagamento: %d\n", code);
	    printf("Ore lavorative: %d\n", w_time);
	    printf("Paga settimanale: $%.2f\n", paga);

	    break;
	 case 3:
	    printf("\n-+- LAVORATORI A PROVVIGIONE -+-\n\n");

	    printf("Importo vendite lorde: ");
	    scanf("%f", &paga);

	    paga = (paga * 5.7) / 100 + 250;

	    printf("\nCodice di pagamento: %d\n", code);
	    printf("Paga settimanale: $%.2f\n", paga);

	    break;
	 case 4:
	    printf("\n-+- LAVORATORI A COTTIMO -+-\n\n");

	    /* sfrutto w_time come 'code' */  
	    printf("Tipo di articolo [1-3]: ");
	    scanf("%d", &w_time);

            switch(w_time) {

	       case 1:
	          if (a_code == 2 || a_code == 3)
			break;

		     a_code = 1;
	             printf("\n** ARTICOLO 1\n\n");
		     printf("Numero articoli (-1 esce): ");
		     scanf("%d", &arts);
		     paga = 5.15 * arts;

  		     break;
	       case 2:
	          if (a_code == 1 || a_code == 3)
 		     break;

		     a_code = 2;
	             printf("\n** ARTICOLO 2\n\n");
		     printf("Numero articoli (-1 esce): ");
		     scanf("%d", &arts);
		     paga = 9.13 * arts;

		     break;
	          case 3:
		     if (a_code == 1 || a_code == 2)
			break;

		     a_code = 3;
	             printf("\n** ARTICOLO 3\n\n");
		     printf("Numero articoli (-1 esce): ");
		     scanf("%d", &arts);
		     paga = 13.5 * arts;

	             break;
	          case ' ':
	          case '\t':
                  case '\n':
                     break;

	          default:
		     printf("Selezione non valida!\n");
       
  	    } /* eof switch: lavoratori a cottimo */

            printf("\nCodice di pagamento: %d\n", code);
	    printf("Codice articolo: %d\n", a_code);
	    printf("Numero articoli: %d\n", arts);
	    printf("Paga settimanale: %.2f\n", paga);
	    a_code = 0;

	    break;

	 case ' ':
	 case '\t':
	 case '\n':
	    break;

	 default:
	    printf("\nCodice di pagamento errato: %d\n", code);
	    printf("\nCodici attualmente disponibili:\n\n");
	    printf("\t1: Mangager\n");
	    printf("\t2: Lavoratori ad ore\n");
	    printf("\t3: Lavoratori a provvigione\n");
	    printf("\t4: Lavoratori a cottimo\n");
      }
      printf("\nInserire codice di pagamento (-1 esce): ");
      scanf("%d", &code);
   }

   printf("\nCalcolo eseguito correttamente!\n");

   return 0;
} /* E0F main */

