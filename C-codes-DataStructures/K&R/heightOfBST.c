#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int value ;
    struct node* left ;
    struct node* right ;
} typedef bstNode ;

int getHeight (bstNode* root) 
{
    if (root == NULL) return -1 ; // empty tree
    int leftHeight = getHeight (root -> left) ;
    int rightHeight = getHeight (root -> right) ;
    return ( leftHeight > rightHeight ? leftHeight : rightHeight) + 1 ;
}

bstNode* GetNewNode (int value) 
{
    bstNode* newNode = malloc (sizeof (bstNode)) ;
    newNode -> value = value ;
    newNode -> right = newNode -> left = NULL ;
    return newNode ;
}

bstNode* Insert (bstNode* root, int value)
{
    if (root == NULL)
        return GetNewNode(value) ;
    else if (value <= root -> value) {
        root -> left = Insert (root -> left, value) ;
    }    
    else {
        root -> right = Insert (root -> right, value) ;
    }
    return root ;
}

int main ()
{
    bstNode* root = NULL ;
    root = Insert (root, 15) ;
    root = Insert (root, 20) ;
    root = Insert (root, 9) ;
    root = Insert (root, 5) ;

    printf("\nThe height of the tree is : %d", getHeight(root)) ;
    return 0 ;
}