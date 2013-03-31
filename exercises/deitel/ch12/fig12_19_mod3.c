/* Exercise 12.22 */

/* Fig. 12.19: fig12_19.c
   Create a binary tree and traverse it 
   preorder, inorder, and postorder */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* self-referential structure */
struct treeNode { 
   struct treeNode *leftPtr;  /* pointer to left subtree */
   int data; /* node value */
   struct treeNode *rightPtr; /* pointer to right subtree */
}; /* end structure treeNode */

typedef struct treeNode TreeNode; /* synonym for struct treeNode */
typedef TreeNode *TreeNodePtr; /* synonym for TreeNode* */

/* prototypes */
void insertNode( TreeNodePtr *treePtr, int value );
void inOrder( TreeNodePtr treePtr );
void preOrder( TreeNodePtr treePtr );
void postOrder( TreeNodePtr treePtr );
int deleteNode( TreeNodePtr *treePtr, int value );

/*
 * NOTE: this function returns the daddy of
 *       the node, not the node in itself.
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

