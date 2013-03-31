/* Exercise 12.19 */

#include <stdio.h>
#include <stdlib.h>

struct tree {
   struct tree *left;
   int data;
   struct tree *right;
};
typedef struct tree Node;

void insnode(Node **nodep, int value);
int depth(Node *nodep);
void showtree(Node *nodep);

int main(void)
{
   Node *root = NULL;
   int i;

   for(i = 0; i < 20; i++) {
      insnode(&root, i);
   }

   printf("The tree have %d levels which are:\n", depth(root));
   showtree(root);

   putchar('\n');

   return 0;
} /* E0F main */

/*
 * Insert an ordered value in the tree 
*/
void insnode(Node **nodep, int value)
{
   if( *nodep == NULL ) {

      if( (*nodep = malloc( sizeof(Node) )) == NULL ) {
         printf("Cannot allocate the memory");
         return;
      }

      ( *nodep )->data = value;
      ( *nodep )->left = NULL;
      ( *nodep )->right = NULL;
   }
   else {

      if( value <= ( *nodep )->data ) {
         insnode( &( ( *nodep )->left ), value );
      }
      else if( value > ( *nodep )->data ) {
         insnode( &( ( *nodep )->right ), value );
      }
   }

} /* eof insnode() */

/*
 * Returns the number of tree levels
*/
int depth(Node *nodep)
{
   Node *currentPtr = nodep;
   static int count = 0;
 
   if( nodep != NULL ) {
      ++count;
      depth(currentPtr->left);
      depth(currentPtr->right);
   }

   return count;

} /* eof depth() */

/* 
 * Show the whole tree
*/
void showtree(Node *nodep)
{
   Node *currentPtr = nodep;
 
   if( nodep != NULL ) {
      printf("%d ", currentPtr->data);
      showtree(currentPtr->left);
      showtree(currentPtr->right);
   }

} /* eof showtree() */

