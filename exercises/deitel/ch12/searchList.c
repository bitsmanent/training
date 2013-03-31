/* Exercise 12.21 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list_t {
   int data;
   struct list_t *next;
};
typedef struct list_t List;

void insert(List **listp, int value);
void printl(List *listp);
List *searchList(List *listp, int value);

int main(void)
{
   int number;
   List *mylist = NULL;
   List *myvalue = NULL;

   srand( time(NULL) );

   /* populate the list */
   for(number = 0; number < 10; number++) {
      insert(&mylist, 1 + rand() % 100);
   }

   printf("What value you are looking for? : ");
   scanf("%d", &number);

   myvalue = searchList(mylist, number);  

   printl(mylist);

   putchar('\n');

   if( myvalue != NULL ) {
      printf("Found %d to the list. Printing the remaining values..\n", number);
      printl(myvalue);
   }
   else {
      printf("Can't find %d to the list\n", number);
   }

   return 0;
} /* E0F main */

/* 
 * Insert a value to the list
*/
void insert(List **listp, int value)
{
   List *newptr;
   List *currentPtr;
   List *previousPtr = NULL;

   if( (newptr = malloc( sizeof(List) )) == NULL ) {
      printf("Cannot allocate the memory: %d not inserted\n", value);
      return;
   }
   newptr->data = value;
   newptr->next = NULL;

   currentPtr = *listp;

   while( currentPtr != NULL && value > currentPtr->data ) {
       previousPtr = currentPtr;
       currentPtr = currentPtr->next;
   }

   if( previousPtr == NULL ) {
      newptr->next = *listp;
      *listp = newptr;
   }
   else {
      previousPtr->next = newptr;
      newptr->next = currentPtr;
   }

} /* eof insert() */

/*
 * Print a the list values using '-->' as separator
*/
void printl(List *listp)
{
   List *currentPtr = listp;

   while( currentPtr != NULL ) {
      printf("%d --> ", currentPtr->data);
      currentPtr = currentPtr->next;
   }
   puts("NULL");

} /* eof printl() */

/*
 * Found a value to the list and returns a pointer to its position
*/
List *searchList(List *listp, int value)
{
   List *currentPtr = listp;

   while( currentPtr != NULL && currentPtr->data != value )
      currentPtr = currentPtr->next;

   return currentPtr;

} /* eof searchList() */

