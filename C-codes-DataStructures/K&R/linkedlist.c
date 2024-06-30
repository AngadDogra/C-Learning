#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node { 
    int value ;
    struct node* next ;
} typedef linkedlistNode ;

linkedlistNode* GetNewNode (int value)
{
    linkedlistNode* newNode = malloc (sizeof (linkedlistNode)) ;
    newNode -> value = value ;
    newNode -> next = NULL ;
    return newNode ;
}

linkedlistNode* InsertAtLast ( linkedlistNode* head, int value)
{
    if (head == NULL)       // The first node of the list
        return GetNewNode(value) ;
    
    linkedlistNode* temp = head ;
    while (temp -> next != NULL)
        temp = temp -> next ;

    temp -> next = GetNewNode (value) ;   
    return head ;
}

linkedlistNode* InsertAtBeginning (linkedlistNode* head, int value) 
{
    linkedlistNode* newNode = GetNewNode (value)  ;
    newNode -> next = head ;
    head = newNode ;
    return head ;   
}

void printList (linkedlistNode* head)
{
    linkedlistNode* temp = head ;
    while (temp != NULL) {
        printf("%d ",temp -> value) ;
        temp = temp -> next ;
    }
}

linkedlistNode* InsertAtNthPosition (linkedlistNode* head, int value, int position)
{
    // Insert at Nth position.
    // Traverse till the position - 1 (if 13 then 12).
    // Change newNode -> next to 12 -> next, then 12 -> next to newNode.
    linkedlistNode* temp = head ;
    int i = 1 ;                          // not moving according to the index but position.
    linkedlistNode* newNode = GetNewNode (value) ;
    while (i < position) { // should stop at the previous position
        temp = temp -> next ;
        i++ ; 
    }
    newNode -> next = temp -> next ;
    temp -> next = newNode ; 

    return head ;
}

linkedlistNode* deleteFromMiddle (linkedlistNode* head)
{
  // even = n/2 + 1, odd = n/2 
  // position = index - 1

    if (head == NULL || head -> next == NULL)
        return head ;

    linkedlistNode* traversalNode = head ;
    int count = 0 ;

    // Count the number of nodes
    while (traversalNode != NULL) {
        traversalNode = traversalNode -> next ;
        count++ ;
    }

    printf("\nThe linked list has %d number of nodes", count); 

    int middle = count / 2 ; 

    if (count % 2 == 0)
        middle -= 1 ;

    linkedlistNode* temp = head ;
    for (int i = 0 ; i < middle - 1 ; i++) {
        temp = temp -> next ;
    }
    
    // Now we are at the previous element.
    linkedlistNode* nodeToBeDeleted = temp -> next ;
    temp -> next = nodeToBeDeleted -> next ;
    free (nodeToBeDeleted) ;

    return head ;
}

bool IsEven(int num) {
    if (num % 2 == 0) {
        return true ;
    }
    else {
        return false ;
    }
}

void DeleteFromNthPosition (linkedlistNode* head, int position)
{
    // position = index + 1 ;
    int index = position - 1 ;
    int i = 0 ;
    linkedlistNode* temp = head ;
    while (i <= index) {
        temp = temp -> next ;
    }
    temp -> next = (temp -> next) -> next ;
    free(temp) ;
    printf("\n The node has been deleted. Updated list is : "); 
    printList(head) ;
}

int main ()
{
    linkedlistNode* head = NULL ;
    head = InsertAtLast (head, 15) ;
    head = InsertAtLast (head, 20) ; 
    head = InsertAtBeginning (head, 30) ;
    head = InsertAtNthPosition (head, 50, 2) ;
    // printList (head) ;
    // DeleteFromNthPosition (head, 2) ;
    head = deleteFromMiddle (head) ;
    printList(head) ;

    return 0 ;
}