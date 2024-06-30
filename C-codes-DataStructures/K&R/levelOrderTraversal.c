#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    char value ;
    struct node* left ;
    struct node* right ;
} typedef bstNode ;

bstNode* GetNewNode (int value)
{
    bstNode* newNode = malloc (sizeof (bstNode)) ;
    newNode -> value = value ;
    newNode -> left = newNode -> right = NULL ;
    return newNode ;
}

bstNode* Insert (bstNode* root, int value)
{
    if (root == NULL)                   // empty tree
        return GetNewNode(value); 
    else if(value <= root -> value){    // smaller than root, belongs to left
        root -> left = Insert (root -> left, value) ;
    }        
    else {
        root -> right = Insert (root -> right, value) ;
    }
}

void LevelOrderTraversal (bstNode* root)
{
    if (root == NULL) ;
}

int main ()
{
    bstNode* root = NULL ;
    root = Insert (root, 15) ;
    root = Insert (root, 30) ;
    root = Insert (root, 24) ;
    root = Insert (root, 4) ;
    root = Insert (root, 5) ;

}