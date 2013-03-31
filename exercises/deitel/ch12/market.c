/* Exercise 12.15 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HOURS 12
#define INTER 4

struct queue_t {
   int client;
   struct queue_t *next;
};
typedef struct queue_t Queue;

void enqueue(Queue **hqueuep, Queue **tqueuep, int value);
int dequeue(Queue **hqueuep, Queue **tqueuep);
char isempty(Queue *queuep);

/* main function */
int main(void)
{
   int c_time; /* current client */
   int s_time; /* service time */
   int i, client;

   Queue *hqueue = NULL, *tqueue = NULL;

   srand( time(NULL ) );

   c_time = 1 + rand() % INTER;

   s_time = 1 + rand() % INTER;
   c_time += 1 + rand() % INTER;

   /* For each minute of the work day (HOURS hours) */
   for(i = client = 0; i < 60 * HOURS; i++) {
      
      if( ! --c_time ) {
	 printf("[+]: %d\n", ++client);
         enqueue(&hqueue, &tqueue, client);
	 c_time = 1 + rand() % INTER;

         if( ! --s_time ) {
	    printf("[-]: %d\n", dequeue(&hqueue, &tqueue));
	    s_time = 1 + rand() % INTER;
         }
      }
   }

   return 0;
} /* E0F main */

/*
 * Determine if the stack is empty this is a "predicate function"
*/
char isempty(Queue *queuep)
{
   if( queuep == NULL )
      return 1;

   return 0;
} /* eof isempty() */

/* 
 * Put another value in queue
*/
void enqueue(Queue **hqueuep, Queue **tqueuep, int value)
{
   Queue *newqueue;

   if( (newqueue = malloc(sizeof(Queue))) == NULL) {
      printf("Cannot allocate the memory\n");
      return;
   }
   newqueue->client = value;
   newqueue->next = NULL;

   if( isempty( *hqueuep ) ) {
      *hqueuep = newqueue;
   }
   else {
      ( *tqueuep )->next = newqueue;
   }

   *tqueuep = newqueue;

} /* eof enqueue() */

/* 
 * Show and remove a value from the top of queue
*/
int dequeue(Queue **hqueuep, Queue **tqueuep)
{
   Queue *tmpqueuep;
   int ret;

   ret = ( *hqueuep )->client;
   tmpqueuep = *hqueuep;
   *hqueuep = ( *hqueuep )->next;

   if( *hqueuep == NULL ) {
      *tqueuep = NULL;
   }

   free( tmpqueuep );

   return ret;
} /* eof dequeue() */

