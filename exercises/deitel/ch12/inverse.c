/* Exercise 12.9 */

#include <stdio.h>
#include <stdlib.h>

struct list {
   char c;
   struct list *next;
};
typedef struct list List;

void showlist(List *list);
void r_showlist(List *list);
void insert(List **list, char value);

int main(void)
{
   List *mylist = NULL;
   int i;

   for(i = 0; i < 10; i++)
      insert(&mylist, 65 + i);

   showlist(mylist);
   r_showlist(mylist);
   putchar('\n');

   return 0;
} /* E0F main */

void showlist(List *list)
{  
   List *currentPtr = list;

   if(currentPtr != NULL) {
      printf("%c --> ", currentPtr->c);
      showlist(currentPtr->next);
   }
   else {
      printf("NULL\n");
   }

} /* eof showlist() */

void r_showlist(List *list)
{  
   List *currentPtr = list;

   if(currentPtr != NULL) {
      r_showlist(currentPtr->next);
      printf(" --> %c", currentPtr->c);
   }
   else {
      printf("NULL");
   }

} /* eof r_showlist() */

void insert(List **list, char value)
{  
   List *newPtr;
   List *previousPtr = NULL, *currentPtr = *list;;

   if( (newPtr = malloc( sizeof(List) )) == NULL) {
      printf("Cannot allocate the memory\n");
      return;
   }
   newPtr->c = value;
   newPtr->next = NULL;

   while( currentPtr != NULL && value > currentPtr->c) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->next;
   }

   if( previousPtr == NULL ) {
      newPtr->next = *list;
      *list = newPtr;
   }
   else {
      previousPtr->next = newPtr;
      newPtr->next = currentPtr;
   }

} /* eof insert() */

