/* Exercise 7.19 */

/* The Simpletron (and LMS) implementation */

#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 100

/* Input/Output */
#define READ   10
#define WRITE  11

/* Loading/Storing */
#define LOAD  20
#define STORE 21

/* Arithmetical */
#define ADD      30
#define SUBTRACT 31
#define DIVIDE   32
#define MULTIPLY 33

/* Reference and control */
#define BRANCH     40
#define BRANCHNEG  41
#define BRANCHZERO 42
#define HALT       43

int checkword(int word, int size);
void dump(int acc, int icounter, int mem[]);

int main(void)
{
   int memory[MEMSIZE] = { 0 }, i, err = 0;

   int operationCode = 0, instructionRegister = 0;
   int accumulator = 0, operand = 0;

   printf("*** Welcome to the Simpletron! ***\n"
	  "*** Please enter your program one instruction ***\n"
	  "*** (or data word) at a time. I will type the ***\n"
	  "*** location number and a question mark (?).  ***\n"
	  "*** You then type the word for that location. ***\n"
	  "*** Type the sentinel -99999 to stop entering ***\n"
	  "*** your program. ***\n");
	   
   for(i = 0; i < MEMSIZE; i++) {
      while(1) {
         printf("%.2d ?? ", i);
         scanf("%d", &memory[i]);

	 if(memory[i] == -99999) {
	    memory[i] = 0;
	    i = MEMSIZE; /* Terminate the for loop */
	    break;
	 }

	 if( checkword(memory[i], MEMSIZE) ) {
	    printf("*** Invalid instruction: %d\n", memory[i]);
	    printf("*** Please retype it or exit.\n");
	 }
	 else
	    break;

      } /* end while */
   } /* end for (i) */

   printf("*** Program loading completed ***\n"
	  "*** Program execution begins  ***\n");

   for(i = 0; i < MEMSIZE; i++) {
      instructionRegister = memory[i];

      operationCode = instructionRegister / 100;
      operand = instructionRegister % 100;

      /* this is required because after the switch()
      statement the 'i' counter is incremented of 1. */
      if(operationCode >= BRANCH)
         --operand;

      switch(operationCode) {
	 case READ:
	    printf("Insert a word: ");
            scanf("%d", &memory[operand]);

	    break;
	 case WRITE:
	    printf("\nMemory location: %.2d\nWord: %d\nASCII: %c\n",
	       operand, memory[operand], memory[operand]);
	    break;
	 case LOAD:
	    accumulator = memory[operand];
	    break;
	 case STORE:
	    memory[operand] = accumulator;
	    break;

	 case ADD:
	    accumulator += memory[operand];

	    if(accumulator > +9999 || accumulator -9999)
	       err = 1;

	    break;
	 case SUBTRACT:
	    accumulator -= memory[operand];

	    if(accumulator > +9999 || accumulator -9999)
	       err = 1;

	    break;
	 case DIVIDE:
	    accumulator /= memory[operand];

	    if( !memory[operand] )
	       err = 2;

	    break;
	 case MULTIPLY:
	    accumulator *= memory[operand];

	    if(accumulator > +9999 || accumulator -9999)
	       err = 1;

	    break;

	 case BRANCH:
	    i = operand;
	    break;
	 case BRANCHNEG:
	    if(accumulator < 0)
	       i = operand;

	    break;
	 case BRANCHZERO:
	    if(!accumulator)
	       i = operand;

            break;

	 case HALT:
	    printf("*** Simpletron execution terminated ***\n");
	    dump(accumulator, i, memory);
	    return 0;

            break;
	 case 0:
	    break;

	 default:
	    printf("*** unknown error: %d\n", instructionRegister);
	    exit(-1);
      }

      /* fatal errors check */
      if(err) {
	 switch(err) {
	    case 1:
               printf("*** Out of the accumulator limit ***\n"); 
	       break;
	    case 2:
	       printf("*** Attempt to divide by zero ***\n");
	       break;
	 }
	 
         printf("*** Simpletron execution abnormally terminated ***\n");
         dump(accumulator, i, memory);
         exit(-1);
      }


   } /* end for (i) */

   dump(accumulator, i, memory);

   return 0;
} /* E0F main */

/* Check if a "word" is correct */
int checkword(int word, int size)
{
   if(word < 0 || word > 9999 || word % 100 >= size) {
      return 1;
   }

   switch(word / 100) {
      case READ:
      case WRITE:
      case LOAD:
      case STORE:
      case ADD:
      case SUBTRACT:
      case DIVIDE:
      case MULTIPLY:
      case BRANCH:
      case BRANCHNEG:
      case BRANCHZERO:
      case HALT:
      case 0:
         break;
      default:
	 return 1;

   } /* end switch (word) */

   return 0;

} /* eof checkword() */

/* Show a dump of the current memory state */
void dump(int acc, int icounter, int mem[])
{
   int i, j;

   printf("\nREGISTERS:\n");
   printf("accumulator\t\t%c%.4d\n"
	  "instructionCounter\t%.2d\n"
	  "instructionRegister\t%c%.4d\n"
	  "operationCode\t\t%.2d\n"
	  "operand\t\t\t%.2d\n",
	  acc < 0 ? '-' : '+', acc < 0 ? -acc : acc,
	  icounter, mem[icounter] < 0 ? '-' : '+',
	  mem[icounter] < 0 ? -mem[icounter] : mem[icounter],
	  mem[icounter] / 100, mem[icounter] % 100);
      

   printf("\nMEMORY:\n");

   /* Print the header */
   printf("%3c", ' ');
   for(i = 0; i < 10; i++)
      printf("%5d ", i);
   printf("\n");

   for(i = 0; i < MEMSIZE; i += 10) {
      printf("%.2d", i);
      for(j = i; j < i+10; j++) {
	 printf(" %c%.4d",
	    mem[j] < 0 ? '-' : '+', mem[j] < 0 ? -mem[j] : mem[j]);
      }
      printf("\n");
   }

} /* eof dump() */

