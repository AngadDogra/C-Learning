#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int value ;
    struct Node* left ;
    struct Node* right ;

} typedef bstNode ;

bstNode* GetNewNode (int value) 
{
    bstNode* newNode = (bstNode* )malloc(sizeof(bstNode)) ;
    newNode -> value = value ;
    newNode -> left = NULL ;
    newNode -> right = NULL ;
    return newNode ;
}

bstNode* InsertNode (bstNode* rootPtr, int value)
{
    if (rootPtr == NULL) {      // empty value
        return GetNewNode(value) ;
    }
    else if( value <= rootPtr -> value) {
        rootPtr -> left = InsertNode(rootPtr -> left, value) ;
    }
    else {
        rootPtr -> right = InsertNode (rootPtr -> right, value) ;
    }
    return rootPtr ;
}

bool SearchNode (bstNode* rootPtr, int value)
{
    if (rootPtr == NULL ) return false ;
    else if (rootPtr -> value == value) return true ;
    else if (value < rootPtr -> value) {
        return SearchNode (rootPtr -> left, value) ;
    } 
    else{
    return SearchNode (rootPtr -> right, value) ;
    }
     
}

int main () 
{
    bstNode* rootPtr ;
    rootPtr = NULL ;
    rootPtr =  InsertNode(rootPtr, 15) ;
    rootPtr = InsertNode(rootPtr, 10) ;
    rootPtr = InsertNode(rootPtr, 20) ;
    rootPtr = InsertNode(rootPtr, 25) ;
    rootPtr = InsertNode(rootPtr, 8) ;
    rootPtr = InsertNode(rootPtr, 12) ;

    int number ;
    printf("Enter the number to be searched: ") ;
    scanf ("%d", &number) ;
    
    if (SearchNode(rootPtr, number)) {
        printf("\n The number has been found") ;
    } else {
        printf("\n Number not found") ;
    }
}

