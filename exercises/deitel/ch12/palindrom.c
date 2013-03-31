/* Exercise 12.11 */

#include <stdio.h>
#include <stdlib.h>

struct stack_t {
   char c;
   struct stack_t *next;
};

typedef struct stack_t Stack;

int palindrom(char *s);
void push(Stack **stack, char value);
char pop(Stack **stack);

int main(void)
{
   char *string;

   printf("Give me a string: ");
   scanf("%s", string);

   printf("The string is ");
   if( palindrom(string) ) {
      putchar('a');
   }
   else {
      printf("NOT a");
   }
   printf(" palindrom\n");

   return 0;
} /* E0F main */

void push(Stack **stack, char value)
{
   Stack *newnode;

   if( (newnode = malloc( sizeof(Stack) )) == NULL ) {
      printf("Cannot allocate the memory\n");
      return;
   }
   newnode->c = value;
   newnode->next = *stack;

   *stack = newnode;

} /* eof push() */

char pop(Stack **stack)
{
   Stack *stackp;
   char ret;

   ret = ( *stack )->c;

   stackp = *stack;
   *stack = ( *stack )->next;

   free(stackp);

   return ret;
} /* eof pop() */

int palindrom(char *s)
{
   Stack *stackp = NULL;
   int i = 0;

   /* push the string */
   while( s[i] != '\0' ) {
      push(&stackp, s[i++]);
   }

   /* pop the string and check the order */
   i = 0;
   while( stackp != NULL ) {
      if( pop(&stackp) != s[i++] )
	 return 0;
   }

   return 1;
} /* eof palindrom() */

