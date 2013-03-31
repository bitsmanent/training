/* Exercise 12.23 */

Tree binarySearchTree( Tree *treePtr, int value )
{  
   Tree *retp = treePtr;

   if( retp != NULL ) {
      if( (retp->left != NULL && retp->data == value) ||
          (retp->right != NULL && retp->data == value)
      ) return retp;

      if( retp->data > value )
         return binarySearchTree( retp->left, value );
      else
         return binarySearchTree( retp->rightr, value );
   }
 
   return NULL;

} /* eof searchTree() */

