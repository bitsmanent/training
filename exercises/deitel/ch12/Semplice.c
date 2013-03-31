/*
 * Exercise 12.27
 * The Simple compiler
 *
 * WARNING: this code is *very* unstable!
 * NO WARRANTY!! - USE AT YOUR OWN RISK!!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUT  "source.s"
#define OUTPUT "fout.lms"

#define SIZE 255
#define BUF 100

/* Symbol table */
typedef struct symtab_t {
   int symbol;
   char type; /* 'L', 'C' or 'V' */
   int location; /* from 00 to 99 */
} Table;

/* Stack structure */
typedef struct stack_t {
   char c;
   struct stack_t *next;   
} Stack;

/*
 * Prototypes
*/
char pop(Stack **stackp);
void push(Stack **stackp, char value);
void topostfix(char infix[], char postfix[]);
void evalpfexp(char *expr, Table *stab, int *icount,
               int *t, int *emem, int *lmsmem);
int calculate(int op1, int op2, char operator);
int isoper(char c); 
char isempty(Stack *stackp);
int precedence(char op1, char op2);
char stacktop(Stack *stackp);
int getcode(char *cmd);
int getsym(int c, int len, Table *stab);
void pw_lmsmem(int *lmsmem, const int size, char *o_file);
void showtab(Table *stab, const int size);

/* Compilation steps */
void fstep(Table *stab, char *infile, int *lmsmem, int *flags);
void sstep(Table *stab, int *lmsmem, int *flags, int size);

/* The main function */
int main(void)
{
   int lmsmem[BUF], flags[BUF];
   Table stab[BUF];
   int c;

   fstep( stab, (char *)INPUT, lmsmem, flags ); /* The 1st step */
   sstep( stab, lmsmem, flags, BUF );           /* The 2nd step */

   printf("\nShow the symbol table (y/n)?: ");
   while( (c = fgetc(stdin)) != EOF ) {
      if( c == 'y' ) {
	 showtab(stab, BUF);
	 break;
      }
      else if( c == 'n' )
	 break;
      else {
	 puts("\nInvalid input");
         printf("Show the symbol table (y/n)?: ");
      }
   }

   putchar('\n');

   return 0;
} /* E0F main */

/*
 * First step: create the symbol table and some incomplete
 * instruction putting them to the memory array "lmsmem"
*/
void fstep(Table *stab, char *infile, int *lmsmem, int *flags)
{
   FILE *fd;
   char cline[SIZE]; /* Current line */
   char postfix[BUF], *tokp;

   const int size = BUF - 1;
   int t = 0, icount = 0;
   int emem = size; /* End memory */
   int x, i;

   /* Initialize the data */ 
   for(i = 0; i < BUF; i++) {
      lmsmem[i] = 0;
      flags[i] = -1;

      stab[i].location = 0; 
      stab[i].type = stab[i].symbol = '0';
   }

   /* open the file */
   if( (fd = fopen(infile, "r")) == NULL ) {
      printf("Cannot open the file: %s\n", infile);
      exit(-1);
   }

   fgets(cline, sizeof(cline), fd);
   cline[ strlen(cline) + 1 ] = '\0';
   while( !feof(fd) ) {

      /* Line number */
      if( (tokp = strtok(cline, " ")) != NULL ) {
         stab[t].symbol = atoi(tokp);
         stab[t].type = 'L';
         stab[t].location = icount;
	 ++t;
      }

      if( (tokp = strtok(NULL, " ")) != NULL ) {

         /* check the command */
	 switch( getcode(tokp) ) {
	    case 1: /* rem */

	       /* do nothing */

	       break;
	    case 10: /* input */

	       /* take the variable */
	       if( (tokp = strtok(NULL, " ")) != NULL ) {

		  if( (x = getsym(*tokp, size, stab)) == -1 ) {
		     stab[t].symbol = *tokp;
		     stab[t].type = 'V';
		     x = stab[t].location = emem--;
		     ++t;
		  }
		  else
		     x = stab[x].location;

		  lmsmem[icount] = 1000 + x;
	       }

	       ++icount;
	       break;
	    case 3: /* let */

	       /* Add all symbols to the table */
	       tokp = strtok(NULL, " ");
	       while( tokp != NULL ) {
		  if( !isoper(*tokp) && *tokp != '=' &&
		      getsym(*tokp, size, stab) == -1
		  ) {
		      stab[t].symbol = *tokp;
		      stab[t].location = emem--;
		      stab[t].type = isdigit((int)*tokp) ? 'C' : 'V';
		      ++t;
		  }
		  tokp = strtok(NULL, " ");
	       }

	       /* Retrieve the right side of the expression.. */
	       for(x = 0; cline[x] != '='; x++) ;
	       x += 2;

	       memset(postfix, '\0', sizeof(postfix));

	       while( cline[x] != '\0' ) {
		  strncat(postfix, &cline[x], sizeof(postfix));
		  strncat(postfix, " ", sizeof(postfix));
		  x += 2;
	       }

	       memset(cline, '\0', sizeof(cline));
	       memcpy(cline, postfix, sizeof(cline));

	       /* ..and convert it to postfix format */
	       topostfix(cline, postfix);

	       /*
		* Evalutate the results and create
		* the Simpletron instructions
  	       */
	       evalpfexp(postfix, stab, &icount, &t, &emem, lmsmem);

	       ++icount;
	       break;
	    case 11: /* print */
	       
	       tokp = strtok(NULL, " "); /* Take the variable */
	       x = getsym(*tokp, size, stab);

	       lmsmem[icount] = 1100 + stab[x].location;
	       
	       ++icount;
	       break;
	    case 40: /* goto */

	       tokp = strtok(NULL, " "); /* Take the line number */
	       lmsmem[icount] = 4000;
	       if( (x = getsym(atoi(tokp), size, stab)) == -1 )
		  flags[icount] = *tokp;
	       else
		  lmsmem[icount] += stab[x].location;

	       ++icount;
	       break;
	    case 6: /* if */

	       tokp = strtok(NULL, " ");
	       if( (x = getsym(atoi(tokp), size, stab)) == -1 ) {
		  stab[t].symbol = *tokp;
		  stab[t].type = 'V';
		  x = stab[t].location = emem--;
	          ++t;
	       }
	       else
	          x = stab[x].location;

	       lmsmem[icount++] = 2000 + x; /* +20x */

	       tokp = strtok(NULL, " "); /* Skip the operator */
	       tokp = strtok(NULL, " "); /* Read the 2nd variable */
	       if( (x = getsym(*tokp, size, stab)) == -1 ) {
		  stab[t].symbol = *tokp;
		  stab[t].type = 'V';
		  x = stab[t].location = emem--;
		  ++t;
	       }
	       else
		  x = stab[x].location;

	       lmsmem[icount++] = 3100 + x; /* +31x */ 

	       /* Read the branch position */
	       while( getcode(tokp) != 40 && tokp != NULL )
	          tokp = strtok(NULL, " ");
	       tokp = strtok(NULL, " ");

	       /* Look for the destination in the symbol table */
	       lmsmem[icount] = 4200;
	       if( (x = getsym(*tokp, size, stab)) == -1 ) {
		  flags[icount] = atoi(tokp);
	       }
	       else
		  lmsmem[icount] += stab[x].location;

	       ++icount;
	       break;
	    case 43: /* end */
	       lmsmem[icount] = 4300;

	       ++icount;

	       break;
	    default: /* unknown command */
	       puts("Some error..");
	 }
      }

      fgets(cline, sizeof(cline), fd);
   }

   fclose(fd); /* Close the input file */

} /* eof fstep() */

/*
 * Second step: find the incomplete instructions, complete them
 * and write the results to the screen and in the OUTPUT file
*/
void sstep(Table *stab, int *lmsmem, int *flags, int size)
{
   int i, x;

   for(i = 0; i < size; i++) {
      if( flags[i] != -1 ) {
	 x = getsym(flags[i], size, stab);
	 lmsmem[i] += stab[x].location;
      }
   }

   /* Show the memory and write it to a file */
   pw_lmsmem(lmsmem, size, (char *)OUTPUT);

} /* eof sstep() */

/*
 * Print the whole LMS memory array
*/
void pw_lmsmem(int *lmsmem, const int size, char *o_file)
{
   FILE *fd;
   int i;

   /* Open the file */
   if( (fd = fopen(o_file, "wb+")) == NULL ) {
      printf("Cannot open the file: %s\n", o_file);
      return;
   }

   puts("\n> Simpletron memory");
   for(i = 0; i < size && lmsmem[i]; i++) {
      printf("%.2d: %+.4d\n", i, lmsmem[i]);
      fprintf(fd, "%+.4d\n", lmsmem[i]);
   }

   fclose(fd);
} /* eof pw_lmsmem() */

/*
 * Print the whole symbol table
*/
void showtab(Table *stab, const int size)
{
   int i;

   puts("\n> Symbol table");

   for(i = 1; i < size; i++) {
      if( stab[i - 1].type == '0' )
	 break;

      if( stab[i - 1].type == 'L' )
         printf("s[%2d] ", stab[i - 1].symbol);
      else
         printf("s[%2c] ", stab[i - 1].symbol);

      printf("t[%1c] l[%.2d]\n", stab[i - 1].type, stab[i - 1].location);
   }
} /* eof showtab() */

/*
 * Returns the position of 'c' in the Table 'stab'
*/
int getsym(int c, int len, Table *stab)
{
   int i;

   for(i = 0; i < len; i++) {
      if( stab[i].symbol == c )
	 return i;
   }

   return -1;
} /* eof getsym() */

/*
 * Returns the Simpletron operation code
 * from the Simple instruction 'cmd'
*/
int getcode(char *cmd)
{
   if( !memcmp(cmd, "rem", 3) )
      return 1;
   else if( !memcmp(cmd, "input", 5) ) /* read - 10 */
      return 10;
   else if( !memcmp(cmd, "let", 3) )
      return 3;
   else if( !memcmp(cmd, "print", 5) ) /* write - 11 */
      return 11;
   else if( !memcmp(cmd, "goto", 4) ) /* branch - 40 */
      return 40;
   else if( !memcmp(cmd, "if", 2) )
      return 6;
   else if( !memcmp(cmd, "end", 3) )
      return 43;

   return 0;
} /* eof getcode() */

/*
 * Pop a value from top of the stack
*/
char pop(Stack **stackp)
{
   Stack *tstackp; /* temporary stack pointer for free(3) */
   char ret = ( *stackp )->c;

   tstackp = *stackp;
   *stackp = ( *stackp )->next;

   free(tstackp);

   return ret;
} /* eof pop() */

/*
 * Push a value in top of the stack
*/
void push(Stack **stackp, char value)
{  
   Stack *newnode;

   if( (newnode = malloc( sizeof(Stack) )) == NULL ) {
      printf("push(): cannot allocate the memory\n");
      return;
   }
   newnode->c = value;
   newnode->next = NULL;

   newnode->next = *stackp,
   *stackp = newnode;

} /* eof push() */

/*
 * Convert from infix format to reverse polish suffix
 * E.g.:
 *
 *   The expression (1 + 5) * 9 - 2 / 6 
 *   will be equal to 1 5 + 9 * 2 6 / -
 *
*/
void topostfix(char infix[], char postfix[])
{
   Stack *stackp = NULL;
   int i = 0, j = 0;

   push(&stackp, '(');
   infix[ (int)strlen(infix) ] = ')';
   infix[ (int)strlen(infix) ] = '\0';

   while( ! isempty(stackp) ) {
      if( isspace( (int)infix[i] ) ) ;
      else if( infix[i] == '(' ) {
         push(&stackp, '(');
      }
      else if( isoper(infix[i]) ) {
         while( precedence(infix[i], stacktop(stackp)) != -1 ) {
            postfix[j++] = pop(&stackp);
            postfix[j++] = ' ';
         }

         push(&stackp, infix[i]);
      }
      else if( infix[i] == ')' ) {
         while( stacktop(stackp) != '(' && isoper(stacktop(stackp)) ) {
            postfix[j++] = pop(&stackp);
            postfix[j++] = ' ';
         }
         pop(&stackp); /* remove the '(' from the stack */
      }
      else {
         postfix[j++] = infix[i];
         postfix[j++] = ' ';
      }

      ++i;
   }
} /* eof topostfix() */

/*
 * Generate the Simpletron instructions from the
 * reverse polish suffix notation expressions
*/
void evalpfexp(char *expr, Table *stab, int *icount,
               int *t, int *emem, int *lmsmem)
{
   Stack *stackp;
   char *tokp;
   int i, x, y;

   expr[ (int)strlen(expr) + 1 ] = '\0';

   tokp = strtok(expr, " ");
   while( tokp != NULL ) {
      if( ! isoper( *tokp ) ) {

	 /* find the symbol in the table */
	 for(i = 0; i < BUF; i++) {
	    if( *tokp == stab[i].symbol )
	       break;
	 }

	 if( i == BUF ) { /* Not found */
            stab[*t].symbol = isdigit((int)*tokp) ? atoi(tokp) : *tokp;
            stab[*t].type = isdigit((int)*tokp) ? 'C' : 'V';
            stab[*t].location = *emem--;
	    i = *t;
	    ++*t;
	 }

	 push(&stackp, stab[i].location);
      }
      else {
         y = pop(&stackp);
         x = pop(&stackp);

	 /* Make the instructions */
	 lmsmem[(*icount)++] = 2000 + x;
	 lmsmem[(*icount)++] = 3000 + y;
	 lmsmem[(*icount)++] = 2100 + *emem;
	 lmsmem[(*icount)++] = 2000 + *emem;
	 lmsmem[(*icount)] = 2100 + x;

	 --*emem;

	 push(&stackp, lmsmem[*icount]);
      }

      tokp = strtok(NULL, " ");
   }

} /* eof evalpfexp() */

/*
 * Calculate the value of expression "op1 operator op2"
*/
int calculate(int op1, int op2, char operator)
{
   int i;

   switch(operator) {
      case '+':
         return op1 + op2;
      case '-':
         return op1 - op2;
      case '*':
         return op1 * op2;
      case '/':
         if( !op2 ) {
	    printf("calculate(): cannot divide for zero\n");
	    exit(-1);
	 }
         else
            return op1 / op2;
      case '^':
         for(i = op2, op2 = op1; i > 1; i--) {
            op1 *= op2;
         }

         return op1;
      case '%':
         return op1 % op2;
   }

   return -1;
} /* eof calculate() */

/* 
 * Check if 'c' is a valid operator
*/
int isoper(char c) 
{
   switch(c) {
      case '+':
      case '-':
      case '*': 
      case '/':
      case '^':
      case '%': 
	 return 1;
   }

   return 0;
} /* eof isoper() */

/*
 * Determine if the stack is empty this is a "predicate function"
*/
char isempty(Stack *stackp)
{    
   return stackp == NULL;
} /* eof isempty() */

/*
 * Determine if the priority of op1 is less then, equal to
 * or greter then op2 and return respectively, -1, 0 and 1.
*/
int precedence(char op1, char op2)
{
   int x = 2;
   char *p = &op1;

   while( x-- ) {
      if( !x )
         p = &op2;

      switch( *p ) {
         case '%':
         case '/':
         case '*':
            *p = '1';
            break;
         case '-':
         case '+':
            *p = '2';
            break;
         case '^':
            *p = '3';
            break;
         default:
            return -1;
      }

   }

   x = (op1 - '0') - (op2 - '0');

   if( x > 0 )
      return 1;
   else if( x < 0 )
      return -1;

   return 0; 
} /* eof precedence() */

/*
 * As pop() but don't extract the value from top of stack
 * This is a "predicate function"
*/
char stacktop(Stack *stackp)
{
   return stackp->c;
} /* eof stacktop() */

