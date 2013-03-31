/* Exercise 8.42 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define VER 12
#define HOR (VER + (VER / 2))

#define BCELL 35
#define WCELL 46

#define WORDS 98

void gridgen(char grid[][HOR][5], int ver, int hor);
void insnums(char grid[][HOR][5], int ver, int hor);
void showgrid(char grid[][HOR][5]);
void inswords(char grid[][HOR][5], char const * dict[WORDS * 2 + 1]);

int main(void)
{
   char grid[VER][HOR][5] = { { { 0 } } };

   char const * dict[WORDS * 2 + 1] = {
      /* Words */
      "CLAUDIO", "PALERMO", "ITA",
      "KATY", "NADIA", "DALILA", "CATRINE", "CRISTINA",  
      "QUINDICILETTERE", "QUESTESONOSEDICI", "SPACCO",
      "TENLETTERS", "CINQUE", "THESIX", "FOUR", "SIX",
      "SEX", "BSD", "UNIX", "GATTO", "MIAO",
      "SIAMOATREDICI", "SIAMODIECI", "ALTREDIECI",
      "QUATTORDICIBIS", "TRENTA", "OTTO", "UNODUETRE",
      "PA", "ME", "EN", "CT", "TP", "CL", "SI", "RA", "AG", 
      "DODICIPAROLE", "UNGRUPPOUTENTI", "UNIXUSERGROUP",
      "ILSETTE", "VENTOTTO", "LUG", "SUX", "OOP", "IP", "ID",
      "EIGHTNUM", "NINEWORDS", "NOVENOVES", "QUESTESONODICIOTTO",
      "DOMINATORIDELMONDO", "ABCDEFGHIJK", "THREE", "IDUE", "SET",
      "POP", "DICATRENTATRE", "SHOCK", "BURNING", "DICIASSETTENUMERI",
      "INUMERI", "ALICEADSLHOMETV4MB" "TEST", "FIGA", "QUESTAEVITA",
      "META", "LAPROMESSA", "BLACK", "UNALTROTEN", "QUATTROGATTI",
      "RET", "VELOCE", "POWER", "TAG", "RESTO", "ILLOOP", "SHUTDOWN",
      "TESI", "LEGA", "NASO", "TANA", "SAGGEZZA", "CODA", "VITA",
      "TESSERE", "LEANCORE", "GLIALBORI", "QUATTROCENTOVENTI", "CHECK",
      "MARKED", "TV", "IPASSORICORSIVI", "GO", "VI", "SONOANCORADICIOTTO",
      "TESTO", "CENTOVENTI", "SCACCOALLAREGINA", "QUADRO",

      /* Definitions */
      "Lo sviluppatore di questo software",
      "La città dello sviluppatore di questo software :-)",
      "Uno stato europeo",
      "Nome di donna k..", "Nome di donna na..", "Nome di donna d..",
      "Nome di donna: ca..", "Nome di donna cr..", "tanto per",
      "le ho contate", "ciò che faccio :P", "in inglese", "un numero",
      "un altro numero :-)", "un quattro di quattro lettere",
      "il numero delle sue lettere è pari alla meta del suo valore",
      "sicurezza extrema :P", "Il tipo di Unix migliore al mondo",
      "un sistema operativo caso ;)", "fa miao", "lo fa il gatto",
      "numero corrente", "quante dicono di essere?", "ce ne sono..",  
      "un articolo :p", "La metà delle sue lettere per 10 dà il suo nome",
      "Il doppio delle sue lettere diviso 2 da il suo nome", "Da uno a nove"
      "Palermo (sigla)", "Messina (sigla)", "Enna (sigla)", "Catania (sigla)",
      "Trapani (sigla)", "Caltanissetta (sigla)", "Siracusa (sigla)",
      "Ragusa (sigla)", "Agrigento (sigla)", "Tante parole quante lettere su..",
      "UUG", "UUG (sigla)", "Un numero", "Aggiungi *20* e dividi per *due*",
      "Gruppo utenti linux", "Questo non funziona..",
      "Programmazione orientata agli oggetti", "Internet Protocol",
      "Identification number", "L'otto ;)", "Nove parole",
      "Nove nove al plurale :P", "Lo dice chi le conta", "Io e Claudio ;)",
      "Le prime undici", "Tre con cinque", 
      "Anche se tanti, solo due.. con 4 (lol)",
      "Si usa per impostare qualcosa su qualsiasi shell",
      "In assembler si usa per rimuovere..", "Lo dice il dottore",
      "effetto provato dall'hiphop di Claudio :-)", "Masterizzando",
      "Il numero di lettere in esso scritto corrisponde alle sue lettere (uhm?)",
      "Una generalizzazione matematica..", "prova", "ce n'è in abbondanza :-)",
      "Lo dice che stà bene", "La insegue il viaggiatore",
      "Somiglia a un giuramento :-)", "Nero", "Ancora uno", "Lo sono in pochi",
      "Valore di ritorno", "Claudio scrive..", "Accende il PC",
      "L'html ne è pieno", "L'operatore col simbolo di percentuale",
      "Il *ciclo* storpiato", "Arresto del sistema", "La si sà per la laurea",
      "L'insieme dei materiale che costituiscono un oggetto",
      "Lo possiede chi ci sa fare", "Vi rimane chi si nasconde",
      "La possiede chi apprende dalle esperienze altrui",
      "Il gatto ne ha più di una", "L'uomo ne ha una soltanto",
      "Si presentano all'ingresso", "Le navi ne hanno almeno due",
      "Quando tutto cominciò",
      "140 più il numero delle sue lettere * 3 dà il numero in esso scritto :-)"
      "Controllo", "Spuntato, visitato", "La vecchia scatola magica",
      "Una solo può generarne molti", "Andare", "L'editor per eccellenza ;)",
      "Ne ho aggiunte ancora", "Lo scrive il cantante", "60 * 2 :)",
      "lo si fa alla moglie del re",
      "Lo si trova in gallerie d'arte e in ogni videogame :-)"
   };

   srand( time(NULL) );

   gridgen(grid, VER, HOR);
   /* inswords(grid, dict); */
   showgrid(grid);

   return 0;
} /* E0F main */

/* ehm.. show the grid :-) */
void showgrid(char grid[][HOR][5])
{
   int i, j;
   for(i = 0; i < VER; i++) {
      for(j = 0; j < HOR; j++)
	 printf("%4s", grid[i][j]);
      printf("\n");
   }
}

/* create an empty grid */
void gridgen(char grid[][HOR][5], int ver, int hor)
{
   int i, j;

   for(i = 0; i < ver; i++) {
      for(j = 0; j < hor; j++) {
	 if( !(rand() % 5) )
	    *grid[i][j] = BCELL;
	 else
	    *grid[i][j] = WCELL;
      }
   }

   insnums(grid, ver, hor);

} /* eof gridgen() */

/* insert the numbers to an empty grid */
void insnums(char grid[][HOR][5], int ver, int hor)
{
   int i, j, num = 1;

   for(i = 0; i < ver; i++) {
      for(j = 0; j < hor; j++) {

	 if(*grid[i][j] == BCELL)
	    continue;

	 if( /* Toggle the closed cells */
	    (*grid[i - 1][j] == BCELL || !i) &&
	    (*grid[i + 1][j] == BCELL || i == ver - 1) &&
	    (*grid[i][j + 1] == BCELL || j == hor - 1) &&
	    (*grid[i][j - 1] == BCELL || !j)
	 ) {
	    
	    if(j < hor - 1) {
	       *grid[i][j + 1] = WCELL;
	       --j;
	    }
	    else if( i < ver - 1 ) {
	       *grid[i + 1][j] = WCELL;
	    }
	    else { /* Latest cell down/right */
	       *grid[i][j] = BCELL;
	    }
	 }

	 else if( /* Check the cell to put it the number */
	    ((*grid[i][j - 1] == BCELL || !j) &&
	    (*grid[i][j + 1] != BCELL && j < hor - 1)) ||
 	    ((*grid[i - 1][j] == BCELL || !i) &&
	    (*grid[i + 1][j] != BCELL && i < ver - 1))
	 ) {

	       if( num <= 9 ) {
	          *grid[i][j] = num + (int)'0';
               }
	       else if(num <= 99) {
	          grid[i][j][0] = num / 10 % 10 + '0';
	          grid[i][j][1] = num % 10 + '0';
	       }
	       else if(num <= 999) {
	          grid[i][j][0] = num / 100 % 10 + '0';
	          grid[i][j][1] = num / 10 % 10 + '0';
		  grid[i][j][2] = num % 10 + '0';
 	       }
	    ++num;

         }
      }
   }
} /* eof insnums() */

/* Insert the words to the cruciverb */
void inswords(char grid[][HOR][5], char const * dict[WORDS * 2 + 1])
{
   int i, j, k, x, len;
   int done[WORDS] = { 0 };

   for(i = 0; i < VER; i++) {
      for(j = 0, len = 0; j <= HOR; j++) {

	 /* Found a delimiter (BCELL or right border) */
	 if( (*grid[i][j] == BCELL || j == HOR) && len ) {

            k = -1; /* Count the string */
	    while(++k < WORDS * 2) {
	       if( *dict[k] != 1 &&
		   (int)strlen(dict[k]) == len &&
		   done[k] != '*' )
		     break;
	    }

	    /* Overwrite the token with the string */
	    if(k < WORDS) {
	       done[k] = '*'; /* Marked as inserted */

	       x = k;
	       for(k = 0; k < len; k++) {

		  grid[i][j - len + k][0] = ' '; /* clean */
		  grid[i][j - len + k][1] = dict[x][k];
		  grid[i][j - len + k][2] = '\0'; /* clean */


	       }
	    }

	    len = 0;
	 }
	 else { /* Increment the token size */
 	    ++len;
	 }
      }
   }
} /* eof inswords() */

