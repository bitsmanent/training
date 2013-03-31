/* Exercise 12.7 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list {
   int n;
   struct list *next;
};

typedef struct list List;

/*
 * Prorotype
*/
void insert(List **list, int value);
void showlist(List *list);
List *merge(List *list, List *append);

int main(void)
{
   List *list1 = NULL, *list2 = NULL;
   List *list3;
   int i;

   srand( time(NULL) );

   for(i = 0; i < 10; i++) {
      insert(&list1, 1 + rand() % 99);
      insert(&list2, 1 + rand() % 99);
   }

   list3 = merge(list1, list2);

   showlist(list1);
   showlist(list2);
   showlist(list3);

   return 0;
} /* E0F main */

void insert(List **list, int value)
{
   List *newPtr;
   List *previousPtr = NULL, *currentPtr = *list;;

   if( (newPtr = malloc( sizeof(List) )) == NULL) {
      printf("Cannot allocate the memory\n");
      return;
   }
   newPtr->n = value;
   newPtr->next = NULL;

   while( currentPtr != NULL && value > currentPtr->n) {
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

void showlist(List *list)
{
   List *currentPtr = list;

   while( currentPtr != NULL ) {
      printf("%d --> ", currentPtr->n);
      currentPtr = currentPtr->next;
   }

   printf("NULL\n");

} /* eof showlist() */

List *merge(List *list, List *append)
{
   List *currentPtr = list;
   List *newPtr;

   if( (newPtr = malloc( sizeof(List) )) == NULL ) {
      printf("Cannot allocate memory\n");
      return NULL;
   }
   newPtr = newPtr->next;

   /* insert list1 */
   while( currentPtr != NULL ) {
      insert(&newPtr, currentPtr->n);
      currentPtr = currentPtr->next;
   }

   currentPtr = append;

   /* insert list2 */
   while( currentPtr != NULL ) {
      insert(&newPtr, currentPtr->n);
      currentPtr = currentPtr->next;
   }

   return newPtr;
} /* eof merge() */

