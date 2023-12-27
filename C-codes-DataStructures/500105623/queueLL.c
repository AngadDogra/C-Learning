#include <stdio.h> 
#include <stdlib.h> 

struct node{
    int data ;
    struct node* link ;
}*rear = NULL , *front = NULL ;


void enqueue(int) ;
int dequeue() ;
int isEmpty() ;
void print() ;


int main(){
}
void enqueue ( int data ){
    struct node* newnode = malloc(sizeof(struct node)) ;
    newnode -> data = data ;
    newnode -> link = NULL ;

    if(rear == NULL)
        front = rear = newnode ;
     
    else{
        rear -> link = newnode ;
        rear = newnode ; 
    }
}    
int dequeue(){
    int data ;
    struct node* temp ;

    temp = front ;
    data = temp -> data ;
    front = front -> link ;
    free(temp) ;
    temp = NULL ;
    return data ;
}        
int isEmpty(){
    if(front == NULL)
        return 1 ;
    else 
        return 0 ;    
}

void print(){
    struct node* temp ;
    temp = front ;
    if(isEmpty()){
        printf("Queue underflow!") ;
        exit(1) ;
    }
    printf("The queue is: ") ;
    while(temp -> link != NULL){
        printf("%d ", temp -> data) ;
        temp = temp -> link ;
    }
    printf("\n") ;
}

