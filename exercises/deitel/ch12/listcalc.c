/* Exercise 12.8 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list {
   int n;
   struct list *next;
};

typedef struct list List;

void insert(List **list, int value);
void showlist(List *list);

int main(void)
{
   List *mylist = NULL;
   int i, sum = 0;
   double media = 0;

   srand( time(NULL) );

   for(i = 0; i < 25; i++)
      insert(&mylist, 1 + rand() % 100);

   showlist(mylist);

   /* calculate the sum */
   while( mylist != NULL ) {
      sum += mylist->n;
      ++media;

      mylist = mylist->next;
   }

   media = sum / media;

   printf("Sum: %d\nMedia: %.2f\n", sum, media);

   return 0;
} /* E0F main */

void showlist(List *list)
{
   List *currentPtr = list;

   while( currentPtr != NULL ) {
      printf("%d --> ", currentPtr->n);
      currentPtr = currentPtr->next;
   }

   printf("NULL\n");

} /* eof showlist() */

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

