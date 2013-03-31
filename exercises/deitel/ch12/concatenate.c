/* Exercise 12.6 */

#include <stdio.h>
#include <stdlib.h>

struct list {
   char c;
   struct list *next;
};

typedef struct list List;
typedef List * ListPtr;

/*
 * Prototypes 
*/
ListPtr createlist(int x);
void showlist(ListPtr startPtr);
void concatenate(ListPtr list1, ListPtr list2);

int main(void)
{
   ListPtr list1 = createlist('0');
   ListPtr list2 = createlist('A');

   showlist(list1);
   showlist(list2);

   concatenate(list1, list2);

   showlist(list1);

   return 0;
} /* E0F main */

ListPtr createlist(int x)
{
   ListPtr newList;
   ListPtr currentPtr;
   int i = 0;

   newList = malloc( sizeof(List) );
   currentPtr = newList;

   while(1) {
      currentPtr->c = x + i++;

      if(i < 10) {
	 currentPtr->next = malloc( sizeof(List) );
	 currentPtr = currentPtr->next;
      }
      else
	 break;
   }
   currentPtr->next = NULL; /* close the list */

   return newList;
} /* end of createlist() */

void showlist(ListPtr startPtr)
{
   ListPtr currentPtr;

   if( startPtr != NULL) {

      currentPtr = startPtr;

      while( currentPtr != NULL ) {
         printf("%c --> ", currentPtr->c);
         currentPtr = currentPtr->next;
      }
   }
   printf("NULL\n");

} /* eof showlist() */

void concatenate(ListPtr list1, ListPtr list2)
{
   ListPtr l1 = list1;

   while( l1->next != NULL )
      l1 = l1->next;

   l1->next = list2;

} /* eof contatenate() */

