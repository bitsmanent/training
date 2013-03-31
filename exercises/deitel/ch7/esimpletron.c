/* Exercise 7.29 */

/* The Extended Simpletron (and LMS) implementation */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MEMSIZE 1000
#define MAXWORD 7

/* Input/Output */
#define READ   10
#define WRITE  11
#define NEWLINE 12
#define SREAD 13
#define SWRITE 14

/* Loading/Storing */
#define LOAD  20
#define STORE 21

/* Arithmetical */
#define ADD      30
#define SUBTRACT 31
#define DIVIDE   32
#define MULTIPLY 33
#define REST     34
#define POWER    35

/* Reference and control */
#define BRANCH     40
#define BRANCHNEG  41
#define BRANCHZERO 42
#define HALT       43

int checkword(int word, int size);
void dump(float acc, int icounter, float mem[]);
int r_htoi(const char string[]);
char * p_itoh(int num, char str[], int z);

int main(void)
{
   char s_mem[MAXWORD] = { 0 };
   float memory[MEMSIZE] = { 0 }, accumulator = 0;

   int operationCode = 0, instructionRegister = 0, operand = 0;
   int i, j, k, err = 0;
   float t_val = 0, f_tmp;

   printf("*** Welcome to the Simpletron! ***\n"
	  "*** Please enter your program one instruction ***\n"
	  "*** (or data word) at a time. I will type the ***\n"
	  "*** location number and a question mark (?).  ***\n"
	  "*** You then type the word for that location. ***\n"
	  "*** Use the sentinel -999999 to stop entering ***\n"
	  "*** your program. ***\n");

   for(i = 0; i < MEMSIZE; i++) {
      while(1) {
         printf("%.2d ?? ", i);
         scanf("%s", s_mem);

	 memory[i] = r_htoi(s_mem);

	 if(memory[i] == -999999) {
	    memory[i] = 0;
	    i = MEMSIZE; /* Terminate the for loop */
	    break;
	 }

	 if(s_mem[0] != '+') {
	    printf("*** Invalid instruction: %s\n", s_mem);
	    printf("*** Please use '+' or exit.\n");
	    continue;
	 }

	 if( checkword((int)memory[i], MEMSIZE) ) {
	    printf("*** Invalid instruction: +%.0f\n"
		   "*** Please retype it or exit.\n", memory[i]);
	 }
	 else
	    break;

      } /* end while */
   } /* end for (i) */

   printf("*** Program loading completed ***\n"
	  "*** Program execution begins  ***\n");

   for(i = 0; i < MEMSIZE; i++) {
      instructionRegister = (int)memory[i];

      operationCode = 
	 instructionRegister / (instructionRegister <= 9999 ? 100 : 1000);
      operand =
	 instructionRegister % (instructionRegister <= 9999 ? 100 : 1000);

      /* this is required because after the switch()
      statement the 'i' counter is incremented of 1. */
      if(operationCode >= BRANCH)
         --operand;

      switch(operationCode) {
	 case READ:
	    printf("\nInsert a word: ");
            scanf("%f", &memory[operand]);

	    break;
	 case WRITE:
	    printf("\nMemory location: %.2d\nWord: %.2f\n",
	       operand, memory[operand]);

	    break;
	 case NEWLINE:
	    printf("\n");
	    break;
	 case SREAD:
	    /* If this instruction is used then HALT is required */
	    printf("\nInsert a string: ");
	    scanf("%s", s_mem);

	    if(strlen(s_mem) > 3) {
	       err = 3;
	       break;
	    }

	    for(j = 0; (unsigned)j < strlen(s_mem); j++) {
	       if((int)s_mem[j] > 99) {
		  err = 4;
		  t_val = j;
		  break;
	       }
	    }
	    memory[operand] = 0;

	    for(j = strlen(s_mem), k = 1; j >= 0; k *= 100, j--)
	       memory[operand] += s_mem[j] * k;

            for(t_val = 0.1, k = 1; k < memory[operand]; t_val *= 0.10, k *= 10) ;
	    t_val /= 0.10;

	    memory[operand] *= t_val;
	    memory[operand] += strlen(s_mem);

	    break;
	 case SWRITE:
	    printf("\nMemory location: %.0f\nWord: ", memory[operand]);
	    for(j = (int)memory[operand], t_val = 100; j ; t_val *= 100, j--) { 
	       f_tmp = memory[operand] * t_val;
	       k = (int)f_tmp % 100;
	       printf("%c", k);
	    }
	    printf("\n");

	    break;
	 case LOAD:
	    accumulator = memory[operand];
	    break;
	 case STORE:
	    memory[operand] = accumulator;
	    break;

	 case ADD:
	    accumulator += memory[operand];

	    break;
	 case SUBTRACT:
	    accumulator -= memory[operand];

	    break;
	 case DIVIDE:
	    if( !memory[operand] )
	       err = 2;
	    else
	       accumulator /= memory[operand];

	    break;
	 case MULTIPLY:
	    accumulator *= memory[operand];

	    break;
	 case REST:
	    accumulator = (int)accumulator % (int)memory[operand];

	    break;

	 case POWER:
	    accumulator = pow(accumulator, memory[operand]);
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
	    i = MEMSIZE; /* terminate the for loop */
	    /* dump(accumulator, i, memory); */

            break;
	 case 0:
	    break;

	 default:
	    printf("*** unknown error: %d\n", instructionRegister);
	    dump(accumulator, i, memory);
	    printf("\nAre'nt you using HALT (+4300)?\n");
	    exit(-1);
      }

      if(accumulator > MEMSIZE * MEMSIZE - 1 ||
         accumulator < MEMSIZE * -MEMSIZE + 1)
         err = 1;

      if(err) { /* Error messages manager */
	 printf("\n*** ");
	 switch(err) {
	    case 1:
               printf("Out of the accumulator limit"); 
	       break;
	    case 2:
	       printf("Attempt to divide by zero");
	       break;
	    case 3:
	       printf("You can put max 3 numbers for memory location");
	       break;
	    case 4:
	       printf("This ASCII code is too long: %d (%c)",
		  s_mem[(int)t_val], s_mem[(int)t_val]);
	 }

	 printf(" ***\n");
	 
         printf("*** Simpletron execution abnormally terminated ***\n");
         dump(accumulator, i, memory);
         exit(-1);
      }

   } /* end for (i) */

   /* dump(accumulator, i, memory); */
   printf("\n*** Simpletron execution terminated ***\n");

   return 0;
} /* E0F main */

/* Check if a "word" is correct */
int checkword(int word, int size)
{
   if( word < 0 || word >= MEMSIZE * MEMSIZE ||
       word % (word <= 9999 ? 100 : 1000) >= size ) {
      return 1;
   }

   switch(word / (word <= 9999 ? 100 : 1000)) {
      case READ:
      case WRITE:
      case NEWLINE:
      case SREAD:
      case SWRITE:
      case LOAD:
      case STORE:
      case ADD:
      case SUBTRACT:
      case DIVIDE:
      case MULTIPLY:
      case REST:
      case POWER:
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
void dump(float acc, int icounter, float mem[])
{
   int i, j;
   char string[6] = { 0 };

   printf("\nREGISTERS:\n");

   printf("accumulator\t\t%c%s\n", acc < 0 ? '-' : '+', p_itoh(acc, string, 4));
   printf("instructionCounter\t%s\n", p_itoh(icounter, string, 2));

   printf("instructionRegister\t%c%s\n", mem[icounter] < 0 ? '-' : '+',
      p_itoh(mem[icounter] < 0 ? -mem[icounter] : mem[icounter], string, 4));

   printf("operationCode\t\t%s\n", p_itoh(mem[icounter] / 100, string, 2));
   printf("operand\t\t\t%s\n", p_itoh((int)mem[icounter] % 100, string, 2));

   printf("\nMEMORY:\n");

   /* Print the header */
   printf("%3c", ' ');
   for(i = 0; i < 10; i++)
      printf("%5d ", i);
   printf("\n");

   for(i = 0; i < MEMSIZE; i += 10) {
      printf("%.3d", i);
      for(j = i; j < i+10; j++) {
	 printf(" %c%s", mem[j] < 0 ? '-' : '+',
	   p_itoh(mem[j] < 0 ? -mem[j] : mem[j], string, 4));
      }
      printf("\n");
   }

} /* eof dump() */

int r_htoi(const char string[])
{
   int i, num = 0, n = 1;
   char s[1] = { 0 };

   for(i = strlen(string) - 1; i >= 0; i--) {
      if(string[i] >= 'A' && string[i] <= 'F')
         n *= 10;

      n *= 10;
   }

   n /= 10;

   for(i = 0; i < 7; n /= 10, i++) {

      if(string[i] >= 'A' && string[i] <= 'F') {
         num += 1 * n;
         n /= 10;
      }

      switch(string[i])
      {  
         case 'A':
	 case 'a':
            /* 0 */
            break;
         case 'B':
	 case 'b':
            num += 1 * n;
            break;
         case 'C':
	 case 'c':
            num += 2 * n;
            break;
         case 'D':
	 case 'd':
            num += 3 * n;
            break;
         case 'E':
	 case 'e':
            num += 4 * n;
            break;
         case 'F':
	 case 'f':
            num += 5 * n;
            break;
         default:
            *s = string[i];
            if(string[0] == '-')
               num -= atoi(s) * n;
            else
               num += atoi(s) * n;
      } /* end switch */

   }

   return num;
}

char * p_itoh(int num, char str[], int z)
{
   int i, idx = 0;

   if(num > 0) {
      if(num <= 9) i = 1;
      else if(num <= 99) i = 10;
      else if(num <= 999) i = 100;
      else if(num <= 9999) i = 1000;
      else if(num <= 99999) i = 10000;
      else {
	 printf("error in p_itoh(): unknown range: %d\n", num);
	    printf("\nAre'nt you using HALT (+4300)?\n");
	 exit(-1);
      }
   }
   else if(!num) {
      for(i = 0; i < (int)sizeof(str); i++) {
	 if(i < z) str[i] = '0';
	 else str[i] = ' ';
      }
      return str;
   }
   else {
      printf("Negative numbers are not allowed!\n");
      return 0;
   }

   for( ; i ; idx++, i /= 10) {

      if( (num / i % 10) == 1 ) {

         i /= 10;
	 if(!i) break;
         switch(num / i % 10) {
	    case 0:
	       str[idx] = 'A';
	       break;
	    case 1:
	       str[idx] = 'B';
	       break;
	    case 2:
	       str[idx] = 'C';
	       break;
	    case 3:
	       str[idx] = 'D';
	       break;
	    case 4:
	       str[idx] = 'E';
	       break;
            case 5:
	       str[idx] = 'F';
	       break;
	    default:
	       str[idx] = (char)(num / i % 10) + '0';
	       i *= 10;
	 }
      }

      else {
	 str[idx] = (char)(num / i % 10) + '0';
      }
   } /* end for (i) */

   return str;
}

