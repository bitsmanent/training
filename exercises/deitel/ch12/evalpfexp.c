/* Exercise 12.13 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack_t {
   int n;
   struct stack_t *next;
};
typedef struct stack_t Stack;

/*
 * Prototypes
*/
void push(Stack **stackp, char value);
char pop(Stack **stackp);
char isempty(Stack *stackp);
int calculate(int op1, int op2, char operator);
int evalpfexp(char *expr);
int isoper(char c);

/* main function */
int main(void)
{
   char string[] = { "6 2 + 5 * 8 4 / -" };

   printf("%s = %d\n", string, evalpfexp(string));

   return 0;
} /* E0F main */

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
   newnode->n = value;
   newnode->next = NULL;

   newnode->next = *stackp,
   *stackp = newnode;

} /* eof push() */

/*
 * Pop a value from top of the stack
*/
char pop(Stack **stackp)
{
   Stack *tstackp; /* temporary stack pointer for free(3) */
   int ret = ( *stackp )->n;

   tstackp = *stackp;
   *stackp = ( *stackp )->next;

   free(tstackp);

   return ret;
} /* eof pop() */

/*
 * Determine if the stack is empty this is a "predicate function"
*/
char isempty(Stack *stackp)
{
   if( stackp == NULL )
      return 1;

   return 0;
} /* eof isempty() */

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
	 if( !op2 ) 
	    return 0;
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
         break;
      default:
         return 0;
   }

   return 1;
} /* eof isoper() */

/*
 * Evalutate the expression in reverse polish notation
*/
int evalpfexp(char *expr)
{
   Stack *stackp;
   int i = -1;
   int x, y;

   expr[ (int)strlen(expr) ] = '\0';

   while( expr[++i] != '\0' ) {
      if( isdigit((int)expr[i]) ) {
	 push(&stackp, expr[i] - '0');
      }
      else if( isoper(expr[i]) ) {
	 x = pop(&stackp);
	 y = pop(&stackp);

	 push(&stackp, calculate(y, x, expr[i]));
      }
   }

   return pop(&stackp);

} /* eof evalpfexp() */

