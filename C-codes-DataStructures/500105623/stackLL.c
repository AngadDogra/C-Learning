#include <stdio.h>
#include <stdlib.h>

struct node{
    int data ;
    struct node* link ;
} *top = NULL ;

void push( int data ){
   
    struct node* newP = malloc(sizeof(struct node)) ;
    if(newP == NULL){
        printf("Stak Overflow !");
        exit(1);
    }
    
    newP -> data = data ;
    newP -> link = top ;
    top = newP ;
}

int isEmpty(){
    if(top == NULL)
        return 1 ;
    else 
        return 0 ;    
}

int pop(){
    int value ;
    struct node* temp ;
    temp = top ;
    if(isEmpty()){
        printf("Stack underflow!") ;
        exit(1) ;
    }
    value = temp -> data ;
    top = top -> link ;
    free(temp) ;
    temp = NULL ;

    return value ;
}

void print(){
    struct node* temp = top ;
    if(isEmpty()){
        printf("Stack Underflow!");
        exit(1);
    }
    printf("\nThe elements of the stack are: ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp -> link ;
    }
    printf("\n") ;
}
int main(){
    int choice , data ;
    while(1){
        printf("1.Push\n2.Print\n3.Pop\n4.Quit\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice){
        case 1 :
            printf("Enter the data: ");
            scanf("%d",&data) ;
            push(data) ;
            break ;
        case 2 : 
            print();
            break ;
        case 3 :
            data = pop() ;
            printf("%d value has been popped!",data) ;
            break ;  
        case 4 :
            exit(1);
            break ;
        default :
            printf("Wrong Choice\n") ;            

    }
    }

}