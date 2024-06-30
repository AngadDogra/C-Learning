#include <stdio.h>

struct node {
    int value ; 
    struct node* next ;
} ;
typedef struct node node_t ;

void printList (node_t *head){
    node_t *temp = head ;

    while (temp != NULL){
        printf("%d ", temp->value) ;
        temp = temp -> next ;   
    }
    printf("\n") ;
}


int main () {

    node_t n1, n2, n3 ;
    node_t *head ;

    n1.value = 10 ;
    n2.value = 20 ;
    n3.value = 30 ;

    /* Linking them up*/
    head = &n3 ;
    n3.next = &n2 ;
    n2.next = &n1 ; 
    n1.next = NULL ;  // last pointer

    printList(head) ;

}