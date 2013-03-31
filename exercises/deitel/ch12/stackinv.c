/* Exercise 12.10 */

#include <stdio.h>
#include <stdlib.h>

struct stack {
   char c;
   struct stack *next;
};

typedef struct stack Stack;

/* 
 * Prototype
*/
void reverse(char *s);
void push(Stack **sPtr, char val);
char pop(Stack **s);

int main(void)
{
   char *string;

   printf("Give me a string: ");
   scanf("%s", string);

   reverse(string);

   return 0;
} /* E0F main */

void reverse(char *s)
{
   int i;
   char c;
   Stack *mystack;

   if( (mystack = malloc( sizeof(Stack) )) == NULL ) {
      printf("Cannot allocate the memory\n");
      return;
   }
   mystack->next = NULL;

   for(i = 0; s[i] != '\0'; i++)
      push(&mystack, s[i]);

   while( (c = pop(&mystack)) != '\0' )
      printf("%c", c);

   putchar('\n');

} /* eof reverse() */

void push(Stack **sPtr, char val)
{
   Stack *newNode;

   if( (newNode = malloc( sizeof(Stack) )) == NULL ) {
      printf("Cannot allocate the memory\n");
      return;
   }

   newNode->c = val;
   newNode->next = *sPtr;

   *sPtr = newNode;

} /* eof push() */

char pop(Stack **s)
{
   char c;
   Stack *temp;

   temp = *s;

   c = ( *s )->c;
   *s = ( *s )->next;

   free(temp);

   return c;
} /* eof pop() */

