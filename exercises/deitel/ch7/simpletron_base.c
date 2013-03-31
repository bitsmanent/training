/* Exercise 7.18 (a, b, and c) */

/* The Simpletron (and LMS) implementation */

#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 100
#define BUFSIZE 21

/* Input/Output */
#define READ  10
#define WRITE 11

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

void checkword(int word, int size);

int main(void)
{
   int memory[MEMSIZE] = { 0 };
   int accumulator = 0, i;

   int m_loc, cmd; /* the memory location and the command */

   int program[BUFSIZE] = { 

   /* Calculate the sum of 2 numbers 
      +1009, +1010, +2009, +3110,
      +4107, +1109, +4300, +1110,
      +4300, +0000, +0000 */

   /* Calculate the largest of 2 numbers 
      +1007, +1008, +2007, +3008,
      +2109, +1109, +4300, +0000,
      +0000, +0000 */


   /* 7.18 (a): take 10 numbers (in a loop with a dummy value)
		and calculate its sum */
   /*
      +1008, +2008, +4106, +3009,
      +2109, +4000, +1109, +4300,
      +0000, +0000
   */

   /* 7.18 (b): take 7 numbers positive or negative (in a loop
		with a counter) and calculate the media */
   /*
      7, 7, 1, +1020, +2020,
      +3021, +2121, +2001, +3102,
      +2101, +4212, +4003, +2021,
      +3200, +2120, +1120, +4300,
      +0000, +0000, +0000, +0000
   */

   /* 7.18 (c): take a serie of numbers and determine and print
		the largest. The first number readed set how many
		values will be inserted */
      +1000, 1, +2000, +2117,
      +2000, +3101, +2100, +4214,
      +1018, +2018, +3117, +4104, +2018, +4003,
      +2017, +1117, +4300
   };

   /* Load the program into the memory */
   for(i = 0; i < BUFSIZE; i++) {
      checkword(program[i], MEMSIZE); /* check the word */
      memory[i] = program[i]; /* passed - loaded */
   }

   /* Execute the program: i use BUFSIZE to optimize */
   for(i = 0; i < MEMSIZE; i++) {
      m_loc = memory[i] % 100;
      cmd = memory[i] / 100;

      /* this is required because after the switch()
      statement the 'i' counter is incremented of 1. */
      if(cmd >= BRANCH)
         --m_loc;

      switch(cmd) {
	 case READ:
	    printf("Insert a word: ");
	    scanf("%d", &memory[m_loc]);

	    break;
	 case WRITE:
	    printf("\nMemory location: %d\nWord: %d\n",
	       m_loc, memory[m_loc]);
	    break;
	 case LOAD:
	    accumulator = memory[m_loc];
	    break;
	 case STORE:
	    memory[m_loc] = accumulator;
	    break;

	 case ADD:
	    accumulator += memory[m_loc];
	    break;
	 case SUBTRACT:
	    accumulator -= memory[m_loc];
	    break;
	 case DIVIDE:
	    accumulator /= memory[m_loc];
	    break;
	 case MULTIPLY:
	    accumulator *= memory[m_loc];
	    break;

	 case BRANCH:
	    i = m_loc;
	    break;
	 case BRANCHNEG:
	    if(accumulator < 0)
	       i = m_loc;

	    break;
	 case BRANCHZERO:
	    if(!accumulator)
	       i = m_loc;

            break;

	 case HALT:
	    return 0;

	 case 0:
	    break;

	 default:
	    printf("simpletron: unknown error.\n");
	    exit(-1);
      }
   } /* end for (i) */

   return 0;
} /* E0F main */

/* check if a "word" is correct */
void checkword(int word, int size)
{
   if(word < 0 || word > 9999 || word % 100 >= size)
      printf("*** Simpletron: unkwown word: %d\n", word);

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
	 printf("*** Simpletron: unknown word: %d\n", word);
	 exit(-1);

   } /* end switch (word) */

} /* eof checkword() */

