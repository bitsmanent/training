/* Exercise 12.12 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUF 50

struct stack_t {
   char c;
   struct stack_t *next;
};
typedef struct stack_t Stack;

/*
 * Prototypes
*/
int isoper(char c);
int precedence(char op1, char op2);
void push(Stack **stackp, char value);
char pop(Stack **stackp);
char stacktop(Stack *stackp);
char isempty(Stack *stackp);
void topostfix(char infix[], char postfix[]);

/* main function */
int main(void)
{
   char string1[BUF] = { 0 };
   char string2[BUF] = { 0 };

   printf("Insert an expression: ");
   fgets(string1, BUF, stdin);

   topostfix(string1, string2);

   printf("To polish infix notation: %s\n", string2);

   return 0;
} /* E0F main */

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
   newnode->next = *stackp,

   *stackp = newnode;

} /* eof push() */

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
 * As pop() but don't extract the value from top of stack
 * This is a "predicate function"
*/
char stacktop(Stack *stackp)
{
   return stackp->c;
} /* eof stacktop() */

/*
 * Determine if the stack is empty
 * This is a "predicate function"
*/
char isempty(Stack *stackp)
{
   if( stackp == NULL )
      return 1;

   return 0;
} /* eof isempty() */

/*
 * Convert from infix format to reverse polish suffix
 * E.g.:
 *
 *   The expression (1 + 5) * 9 - 2 / 6 
 *   is equivalent to 1 5 + 9 * 2 6 / -
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
      if( isspace( (int)infix[i] ) ) ; /* ignore the blank spaces */

      else if( isdigit((int)infix[i]) ) {
	 postfix[j++] = infix[i];
      }
      else if( infix[i] == '(' ) {
	 push(&stackp, '(');
      }
      else if( isoper(infix[i]) ) {
	 postfix[j++] = ' ';

	 while( precedence(infix[i], stacktop(stackp)) != -1 ) {
	    postfix[j++] = pop(&stackp);
	 }

	 push(&stackp, infix[i]);
	 postfix[j++] = ' ';
      }
      else if( infix[i] == ')' ) {
	 postfix[j++] = ' ';
	 while( stacktop(stackp) != '(' && isoper(stacktop(stackp)) ) {
	    postfix[j++] = pop(&stackp);
	 }
	 pop(&stackp); /* remove the '(' from the stack */
      }

      ++i;
   }
} /* eof topostfix() */

