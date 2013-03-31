/* Exercise 12.17 */

/* Fig. 12.19: fig12_19.c
   Create a binary tree and traverse it 
   preorder, inorder, and postorder */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

/* self-referential structure */
struct treeNode { 
   struct treeNode *leftPtr;  /* pointer to left subtree */
   char data[SIZE]; /* node value */
   struct treeNode *rightPtr; /* pointer to right subtree */
}; /* end structure treeNode */

typedef struct treeNode TreeNode; /* synonym for struct treeNode */
typedef TreeNode *TreeNodePtr; /* synonym for TreeNode* */

/* prototypes */
void insertNode( TreeNodePtr *treePtr, char *string );
void inOrder( TreeNodePtr treePtr );
void preOrder( TreeNodePtr treePtr );
void postOrder( TreeNodePtr treePtr );

/* function main begins program execution */
int main(void)
{ 
   TreeNodePtr rootPtr = NULL; /* tree initially empty */
   char string[SIZE], *tokp;

   printf("Insert a phrase: ");
   fgets(string, SIZE, stdin);
   printf( "The current string being placed in the tree are:\n" );
   printf("%s\n", string);

   tokp = strtok(string, " ");
   while( tokp != NULL ) {
      insertNode( &rootPtr, tokp );
      tokp = strtok(NULL, " ");
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
void insertNode( TreeNodePtr *treePtr, char *string )
{ 
   
   /* if tree is empty */
   if ( *treePtr == NULL ) {   
      *treePtr = malloc( sizeof( TreeNode ) );

      /* if memory was allocated then assign data */
      if ( *treePtr != NULL ) { 
	 strncpy( ( *treePtr )->data, string, SIZE );
         ( *treePtr )->leftPtr = NULL;
         ( *treePtr )->rightPtr = NULL;
      } /* end if */
      else {
         printf( "%s not inserted. No memory available.\n", string );
      } /* end else */

   } /* end if */
   else { /* tree is not empty */

      /* data to insert is less than data in current node */
      if ( memcmp(string, ( *treePtr )->data, SIZE) <= 0 ) {
         insertNode( &( ( *treePtr )->leftPtr ), string );
      } /* end if */

      /* data to insert is greater than data in current node */
      else {
         insertNode( &( ( *treePtr )->rightPtr ), string );
      } /* end else if */

   } /* end else */

} /* end function insertNode */

/* begin inorder traversal of tree */
void inOrder( TreeNodePtr treePtr )
{ 

   /* if tree is not empty then traverse */
   if ( treePtr != NULL ) { 
      inOrder( treePtr->leftPtr );
      printf( "%s ", treePtr->data );
      inOrder( treePtr->rightPtr );
   } /* end if */

} /* end function inOrder */

/* begin preorder traversal of tree */
void preOrder( TreeNodePtr treePtr )
{ 

   /* if tree is not empty then traverse */
   if ( treePtr != NULL ) { 
      printf( "%s ", treePtr->data );
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
      printf( "%s ", treePtr->data );
   } /* end if */

} /* end function postOrder */

