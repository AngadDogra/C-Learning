#include <stdio.h>
#include <stdlib.h>

struct node {
    char value ;
    struct node* left ;
    struct node* right ;
} typedef bstnode ;

void PreOrderTraversal( bstnode* root ) 
{
    // visit the root, then left subtree, then right subtree
    if (root == NULL) return ;
    printf("%c", root->value) ;
    PreOrderTraversal(root->left) ;
    PreOrderTraversal(root->right) ;
}

void InOrderTraversal (bstnode* root)
{   
    // left subtree, root, right subtree
    if (root == NULL) return ;
    InOrderTraversal(root -> left) ;
    printf("%c", root -> value) ;
    InOrderTraversal(root -> right) ;
}

void PostOrderTraversal (bstnode* root)
{
    // left subtree, right subtree, root
    if (root == NULL) return ;
    PostOrderTraversal (root -> left) ;
    PostOrderTraversal (root -> right) ;
    printf("%c", root -> value) ;
}

bstnode* GetNewNode (char value) 
{
    bstnode* root = malloc (sizeof (bstnode)) ;
    root -> value = value ;
    root -> left = NULL ;
    root -> right = NULL ;
    return root ;
}

bstnode* Insert (bstnode* root, char value) 
{
    // Inserting the nodes in the tree
    if (root == NULL) {                 // empty tree
        return GetNewNode(value) ;
    }
    else if(value <= root -> value) {
        root -> left = Insert (root -> left, value) ;
    }
    else {
        root -> right = Insert (root -> right, value) ;
    }
    return root ;
}

int main () 
{
    bstnode* root = NULL ;
    root = Insert (root, 'F') ;
    root = Insert (root, 'D') ;
    root = Insert (root, 'J') ;
    root = Insert (root, 'B') ;
    root = Insert (root, 'E') ;
    root = Insert (root, 'G') ;
    root = Insert (root, 'K') ;
    root = Insert (root, 'A') ;
    root = Insert (root, 'C') ;
    root = Insert (root, 'I') ;

    printf("The preorder traversal is: ") ;
    PreOrderTraversal(root) ;
    printf("\nThe inorder traversal is: ") ;
    InOrderTraversal(root) ;
    printf("\nThe postorder traversal is: ") ;
    PostOrderTraversal(root) ;    

    return 0 ;
}
