#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int value ;
    struct Node* left ;
    struct Node* right ;
} typedef bstNode ;

// GetNewNode function : returns the address of created node.
bstNode* GetNewNode (int value) 
{
    bstNode* newNode = malloc (sizeof(bstNode)) ;
    newNode -> value = value ;
    newNode -> left = newNode -> right = NULL ;
    return newNode ;
}

// Insert Function : Inserts node acc to value and returns root.
bstNode* Insert (bstNode* root, int value)
{
    if (root == NULL) {    // The first node, an empty tree
        return GetNewNode(value) ;
    } 
    else if (value > root -> value) {
        root -> right =  Insert (root -> right, value) ;
    }
    else {
        root -> left = Insert (root -> left, value) ;
    }
    return root ;
}

int getMin (bstNode* root) 
{
    /* Search till you find the leftest node */
    if (root -> left != NULL) {
        return getMin (root -> left) ;
    }
    else {
        return root -> value ;
    }
}

int getMax (bstNode* root) 
{
    /* Search till you find the rightest node */
    if (root -> right != NULL) {
        return getMin (root -> right) ;
    }
    else {
        return root -> value ;
    }    
}

int main ()
{
    bstNode* root = NULL ;
    root = Insert (root, 15) ;
    root = Insert (root, 20) ;
    root = Insert (root, 9) ;
    root = Insert (root, 5) ;

    // Finding the min and max of the tree
    printf("\nThe minimum node is: %d", getMin(root)) ;
    printf("\nThe maximum node is: %d", getMax(root)) ;
}