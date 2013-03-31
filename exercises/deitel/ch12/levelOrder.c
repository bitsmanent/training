/* Exercise 12.24 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Tree structure */
struct treeNode { 
   struct treeNode *leftPtr;
   int data;
   struct treeNode *rightPtr;
};
typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

/* Queue structure */
struct queue_t {
   TreeNodePtr data;
   struct queue_t *next;
};
typedef struct queue_t Queue;

/*
 * Prototypes
*/
void insertNode( TreeNodePtr *treePtr, int value );
int deleteNode( TreeNodePtr *treePtr, int value );

void enqueue(Queue **head, Queue **tail, TreeNodePtr value);
TreeNodePtr dequeue(Queue **head, Queue **tail);

void inOrder( TreeNodePtr treePtr );
void preOrder( TreeNodePtr treePtr );
void postOrder( TreeNodePtr treePtr );
void levelOrder(TreeNodePtr root);

/*
 * NOTE: this function returns the parent node, not the node in itself.
*/
TreeNodePtr searchTree( TreeNodePtr treePtr, int value );

/* function main begins program execution */
int main(void)
{ 
   int i; /* counter to loop from 1-10 */
   int item; /* variable to hold random values */
   TreeNodePtr rootPtr = NULL; /* tree initially empty */

   srand( time( NULL ) ); 
   printf( "The numbers being placed in the tree are:\n" );

   /* insert random values between 1 and 15 in the tree */
   for ( i = 1; i <= 10; i++ ) { 
      item = rand() % 15;
      printf( "%3d", item );
      insertNode( &rootPtr, item );
   } /* end for */

   printf("\n\nInsert the value to remove: ");
   scanf("%d", &item);

   if( deleteNode( &rootPtr, item ) ) {
      printf("Value not found or value is root: %d\n", item);
      return -1;
   }

   /* traverse the tree preOrder */
   printf( "\nThe preOrder traversal is:\n" );
   preOrder( rootPtr );

   /* traverse the tree inOrder */
   printf( "\n\nThe inOrder traversal is:\n" );
   inOrder( rootPtr );

   /* traverse the tree postOrder */
   printf( "\n\nThe postOrder traversal is:\n" );
   postOrder( rootPtr );

   /* traverse the tree levelOrder */
   printf( "\n\nThe levelOrder traversal is:\n" );
   levelOrder( rootPtr );

   putchar('\n');

   return 0; /* indicates successful termination */

} /* end main */

/* insert node into tree */
void insertNode( TreeNodePtr *treePtr, int value )
{ 
   
   /* if tree is empty */
   if ( *treePtr == NULL ) {   
      *treePtr = malloc( sizeof( TreeNode ) );

      /* if memory was allocated then assign data */
      if ( *treePtr != NULL ) { 
         ( *treePtr )->data = value;
         ( *treePtr )->leftPtr = NULL;
         ( *treePtr )->rightPtr = NULL;
      } /* end if */
      else {
         printf( "%d not inserted. No memory available.\n", value );
      } /* end else */

   } /* end if */
   else { /* tree is not empty */

      /* data to insert is less than data in current node */
      if ( value <= ( *treePtr )->data ) {
         insertNode( &( ( *treePtr )->leftPtr ), value );
      } /* end if */

      /* data to insert is greater than data in current node */
      else if ( value > ( *treePtr )->data ) {
         insertNode( &( ( *treePtr )->rightPtr ), value );
      } /* end else if */

   } /* end else */

} /* end function insertNode */

/* begin inorder traversal of tree */
void inOrder( TreeNodePtr treePtr )
{ 

   /* if tree is not empty then traverse */
   if ( treePtr != NULL ) { 
      inOrder( treePtr->leftPtr );
      printf( "%3d", treePtr->data );
      inOrder( treePtr->rightPtr );
   } /* end if */

} /* end function inOrder */

/* begin preorder traversal of tree */
void preOrder( TreeNodePtr treePtr )
{ 

   /* if tree is not empty then traverse */
   if ( treePtr != NULL ) { 
      printf( "%3d", treePtr->data );
      preOrder( treePtr->leftPtr );
      preOrder( treePtr->rightPtr );
   } /* end if */

} /* end function preOrder */

/* begin postorder traversal of tree */
void postOrder( TreeNodePtr treePtr )
{ 

   /* if tree is not empty then traverse */
   if ( treePtr != NULL ) { 
      postOrder( treePtr->leftPtr );
      postOrder( treePtr->rightPtr );
      printf( "%3d", treePtr->data );
   } /* end if */

} /* end function postOrder */

/* 
 * Delete a node from the tree
*/
int deleteNode( TreeNodePtr *treePtr, int value )
{
   TreeNodePtr rm_parentp = searchTree( *treePtr, value );
   TreeNodePtr *rm_childp;
   TreeNodePtr currentPtr;

   /* a simple check */
   if( rm_parentp == NULL || *treePtr == NULL )
      return 1;

   /* set the "parent" pointer */
   if( rm_parentp->leftPtr != NULL && rm_parentp->leftPtr->data == value )
      rm_childp = &rm_parentp->leftPtr;
   else
      rm_childp = &rm_parentp->rightPtr;

   /* remove a leaf node */
   if( ( *rm_childp )->leftPtr == NULL && ( *rm_childp )->rightPtr == NULL ) {

      *rm_childp = NULL;
      free( *rm_childp );
   }
   /* remove a one-child node: is this code unreadable? :| */ 
   else if(((*rm_childp)->leftPtr != NULL) ^ ((*rm_childp)->rightPtr != NULL)) {

      rm_parentp = *rm_childp;

      if( ( *rm_childp )->leftPtr != NULL )
         *rm_childp = ( *rm_childp )->leftPtr;
      else
         *rm_childp = ( *rm_childp )->rightPtr;

      free( rm_parentp );
   }
   /* remove a two-children node */
   else {
      currentPtr = ( *rm_childp )->leftPtr;
      while( currentPtr->rightPtr != NULL ) {
	 currentPtr = currentPtr->rightPtr;
      }

      rm_parentp = *rm_childp; /* will be freed */

      currentPtr->rightPtr = ( *rm_childp )->rightPtr;
      ( *rm_childp )->rightPtr = NULL;
      *rm_childp = ( *rm_childp )->leftPtr;

      free( rm_parentp );
   }

   return 0;
} /* eof deleteNode()*/

/*
 * Find a node and returns its daddy 
*/
TreeNodePtr searchTree( TreeNodePtr treePtr, int value )
{  
   TreeNodePtr retp = treePtr;

   if( retp != NULL ) {
      if( (retp->leftPtr != NULL && retp->leftPtr->data == value) ||
	  (retp->rightPtr != NULL && retp->rightPtr->data == value)
      ) return retp;

      if( retp->data > value )
	 return searchTree( retp->leftPtr, value );
      else
	 return searchTree( retp->rightPtr, value );
   }
 
   return NULL;

} /* eof searchTree() */

/*
 * Insert a "value" to the queue
*/
void enqueue(Queue **head, Queue **tail, TreeNodePtr value)
{
   Queue *newqueue;

   if( (newqueue = malloc( sizeof(Queue) )) == NULL ) {
      printf("Cannot allocate the memory\n");
      return;
   }
   newqueue->data = value;
   newqueue->next = NULL;

   /* if the queue is empty */
   if( *head == NULL ) {
      *head = newqueue;
   }
   else {
      ( *tail )->next = newqueue;
   }

   *tail = newqueue;

} /* eof enqueue() */

/*
 * Remove an element from the queue and return its value
*/
TreeNodePtr dequeue(Queue **head, Queue **tail)
{
   TreeNodePtr value;
   Queue *temp = *head;

   value = ( *head )->data;
   *head = ( *head )->next;

   /* if the queue is empty */
   if( *head == NULL ) {
      *tail = NULL;
   }

   free( temp );

   return value;
} /* eof dequeue() */

/*
 * Begin levelorder traversal of tree
*/
void levelOrder(TreeNodePtr root)
{
   Queue *head = NULL, *tail = NULL;
   TreeNodePtr currentNode;

   enqueue( &head, &tail, root );

   while( head != NULL && (currentNode = dequeue(&head, &tail)) != NULL ) {
      printf("%3d", currentNode->data); 

      if( currentNode->leftPtr != NULL )
	 enqueue(&head, &tail, currentNode->leftPtr);

      if( currentNode->rightPtr != NULL )
	 enqueue(&head, &tail, currentNode->rightPtr);
   }
} /* eof levelOrder() */

