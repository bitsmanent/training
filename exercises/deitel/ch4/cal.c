/* Esercizio 4.36 */

#include <stdio.h>

int main()
{
   int giorno, mese, anno;
   int giorni; /* giorni del mese corrente */

   /* l_giorni: copia di giorni (per il loop)
    * newline: per indentare e andare a capo. */
   int l_giorni = 0, newline = 0, i;

   do { /* Prendo in input l'anno */
      printf("Inserire anno [ '94 - '99 ]: ");
      scanf("%d", &anno);
   } while(anno < 1994 || anno > 1999);
   printf("\n");

   for(i = 1994; i <= anno; ++i) {

      /* mesi */
      for(mese = 1; mese <= 12; ++mese) {

         /* conto i giorni */
         switch(mese) {
	    case 1:
 	    case 3:
	    case 5:
	    case 7:
	    case 8:
	    case 10:
	    case 12:
	       giorni = 31;
	       break;

	    case 2:
               if ( !( i % 4 ) && i % 100 || !( i % 400 ) )
	          giorni = 29;
	       else
	          giorni = 28;

	       break;
 
	    case 4:
	    case 6:
	    case 9:
	    case 11:
	       giorni = 30;

         } /* end switch (mese) */

         if (i == anno) { /* se è l'anno richiesto */

	    printf("%5s", " ");

            switch(mese) {
	       case 1:
	          printf("Gennaio");
	          break;
	       case 2:
	          printf("Febbraio");
	          break;
	       case 3:
	          printf("Marzo");
	          break;
	       case 4:
	          printf("Aprile");
	          break;
	       case 5:
	          printf("Maggio");
	          break;
	       case 6:
	          printf("Giugno");
	          break;
	       case 7:
	          printf("Luglio");
	          break;
	       case 8:
	          printf("Agosto");
	          break;
	       case 9:
	          printf("Settembre");
	          break;
	       case 10:
	          printf("Ottobbre");
	          break;
	       case 11:
	          printf("Novembre");
	          break;
	       case 12:
	          printf("Dicembre");
            }

	    printf(" %d\n", anno);

            /* ciclo i giorni */
            printf("%3s%3s%3s%3s%3s%3s%3s\n",
               "Lu", "Ma", "Me", "Gi", "Ve", "Sa", "Do");

            for(giorno = 1; giorno <= giorni; ++giorno) {
 
               if (giorno == 1) { /* primo del mese */

	          switch((l_giorni+giorno) % 7) {

	             case 0: /* venerdì */
	                printf("%3s%3s%3s%3s",
			   " ", " ", " ", " ");
	                newline = 5;
	                break;
	             case 1: /* Sabato */
		        printf("%3s%3s%3s%3s%3s",
			   " ", " ", " ", " ", " ");
	                newline = 6;
	                break;
	             case 2: /* domenica */
	 	        printf("%3s%3s%3s%3s%3s%3s",
			   " ", " ", " ", " ", " ", " ");
	                newline = 0;
	                break;
	             case 3: /* lunedì */
	                newline = 1;
                        break;
	             case 4: /* martedì */
	   	        printf("%3s", " ");
	  	        newline = 2;
	                break;
	             case 5: /* mercoledì */
	  	        printf("%3s%3s", " ", " ");
	                newline = 3;
                        break;
	             case 6: /* giovedì */
	                printf("%3s%3s%3s", " ", " ", " ");
	                newline = 4;
			
                  } /* end switch (giorn? % 7) */
	       } /* end if (giorno == 1) */

	       printf("%3d", giorno);

	       if( !(newline % 7) && giorno != giorni)
	          printf("\n");
	       ++newline;

            } /* end for (giorno <= giorni) */
            printf("\n\n");
         } /* end if (i == anno) */

         l_giorni += giorni;

      } /* for (mesi) */
   } /* for (anno) */

   return 0;
} /* E0F main */

