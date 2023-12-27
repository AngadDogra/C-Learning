#include <stdio.h> 
#include <stdlib.h>
#define MAX 100

int queue[MAX] ;
int front = -1 ;
int rear = -1 ;

void enqueue(int) ;
int dequeue() ;
int peek() ;
void print() ;
int isFull() ;
int isEmpty() ;


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
}


void enqueue(int data){
    if(isFull()){
        printf("Queue overflow!\n") ;
        exit(1) ;
    }    
    if(front = -1)
        front = 0 ;
    rear++ ;
    queue[rear] = data ;    
}

int dequeue(){
    int value ;
    if(isEmpty()){
        printf("Queue underflow!\n");
        exit(1) ;
    }
    value = queue[front] ;
    front ++ ;
    return value ;
}


int isFull(){
    if(rear == MAX -1)
        return 1 ;
    else 
        return 0 ;    
}

int isEmpty(){
    if(front == -1 || front == rear + 1)
        return 1 ;
    else 
        return 0 ;    
}

int peek(){
    int data ;
    if(isEmpty()){
        printf("Queue underflow!\n") ;
        exit(1) ;
    }
    data = queue[rear] ;
    return data ;
}

void print(){
    int i ;
    if(isEmpty()){
        printf("Queue underflow!\n") ;
        exit(1) ;
    }
    printf("\nQueue: ") ;
    for(i = front ; i <= rear ; i++)
        printf("%d " , queue[i]) ;
    printf("\n") ;
}

