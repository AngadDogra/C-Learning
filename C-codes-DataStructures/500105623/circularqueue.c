#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int rear = -1 ;
int front = -1 ;
int cqueue[MAX] ;

void enqueue(int) ;
int dequeue() ;
int peek() ;
int isFull() ;
int isEmpty() ;
void print() ;

int main(){
    int data , choice ;
    while(1){
    printf("1.Insert\n2.Delete\n3.Peek\n4.Print\n5.Quit\nEnter your choice: ") ;
    scanf("%d" , &choice) ;

    switch(choice){
        case 1:
        printf("\nEnter the data: ") ;
        scanf("%d",&data) ;
        enqueue(data) ;
        break ;
        
        case 2:
        data = dequeue() ;
        printf("The element has been deleted!") ;
        break ;

        case 3:
        data = peek() ;
        printf("%d\n" , data) ;
        break ;

        case 4:
        print() ;
        break ;

        case 5:
        exit(1) ;
        break ;

    }

    }
    return 0 ;
}

void enqueue(int data){
    if(isFull()){
        printf("Queue overflow!\n") ;
        exit(1) ;
    }
    if(front = -1)
        front = 0 ;
    
    if(rear = MAX -1)
        rear = 0 ;
    else{
        rear = rear + 1 ;
        cqueue[rear] = data ;
    }
}

int dequeue(){
    int data ;
    if(isEmpty()){
        printf("Queue underflow!\n") ;
        exit(1) ;
    }
    data = cqueue[rear] ;
    if(front == rear)
        front = rear = -1 ;
    else if (front == MAX - 1)
        front = 0 ;
    else 
        front++ ;
    return data ;        
}

int isEmpty(){
    if(front == -1)
        return 1 ;
    else 
        return 0 ;    
}

int isFull(){
    if((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1 ;
    else 
        return 0 ;    
}


int peek(){
    if(isEmpty()){
        printf("Queue underflow!\n") ;
        exit(1) ;
    }
    return cqueue[front] ;
}

void print(){
    int temp ;
    if(isEmpty()){
        printf("Queue underflow!\n") ;
        exit(1) ;
    }
    temp = front ;
    if(front <= rear){
        while(temp <= rear){
            printf("%d",cqueue[temp]) ;
            temp++ ;
        }
    }
    else{
        while(temp <= MAX -1){
            printf("%d ",cqueue[temp]) ;
            temp++ ;
        }
        temp = 0 ;
        while (temp <= rear){
            printf("%d ",cqueue[temp]) ;
            temp++ ;
        }

    }
    printf("\n") ; 
}