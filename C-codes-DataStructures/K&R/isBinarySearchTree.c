#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value ; // can be any datatype
    struct node* left ;
    struct node* right ;    
}   typedef bstnode ;

bool IsSubtreeLesser (bstnode* root, int value) 
{

}

bool IsSubtreeGreater (bstnode* root, int value) 
{
    
}

bool IsBinarySearchTree (bstnode* root)
{
    // Everything in left must be smaller, and everything in right must be greater
    // How should you traverse the tree then ? 
    // Postorder ?
    if (root == NULL) return true ;

    if (IsSubtreeLesser(root -> left, root -> value) && IsSubtreeGreater(root -> right, root -> value) && IsBinarySearchTree(root -> left) && IsBinarySearchTree(root -> right))
        return true ;
    else
        return false  ;   
}