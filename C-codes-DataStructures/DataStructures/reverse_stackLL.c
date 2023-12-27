#include <stdio.h>
#include <stdlib.h>

struct node{
    int data ;
    struct node* link ;
} ;

void push(int data , struct node** top1){
    struct node* newnode = malloc(sizeof(struct node)) ;
    if(newnode == NULL){
        printf("\nstack underflow!");
        exit(1);
    }
    newnode -> data = data ;
    newnode -> link = *top1 ;
    *top1 = newnode ;
}

int isEmpty(struct node* top){
    if(top == NULL)
        return 1 ;
    else 
        return 0 ;    

}        

int pop(struct node** top1){
    int value ;
    struct node* temp ;
    temp = *top1 ;
    value = temp -> data ;
    *top1 = (*top1) -> link ;
    free(temp) ;
    temp = NULL ;
    return value ;

}

void print(struct node** top){
    struct node* temp = *top ;
    
    printf("\nThe elements of the stack are: ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp -> link ;
    }
    printf("\n") ;
}

void reverse_stack(struct node** top){
    struct node* top1 = NULL ;
    struct node* top2 = NULL ;

    // Pushing onto temp stack 1
    while(*top != NULL){
        push(pop(top) , &top1) ;
    }
    // Pushing onto temp stack 2 
    while(top1 != NULL){
        push(pop(&top1) , &top2) ;
    }
    // Pushing onto original stack
    while(top2 != NULL){
        push(pop(&top2) , top) ;
    }
    
}

int main(){
    int choice , data  ;
    struct node* top = NULL ;
    while(1){
        printf("1.Push\n2.Print\n3.Reverse the stack\n4.Quit\n\nEnter your choice: ");
        scanf("%d",&choice) ;
        switch (choice) {
            case 1 :
            printf("Enter the element you want to push: ") ;
            scanf("%d",&data) ;
            push(data , &top) ;
            break ;

            case 2 :
            print(&top) ; break ;
            
            case 3 :
            reverse_stack(&top) ;
            printf("\nThe stack is reversed\n\n") ;
            break ;

            case 4 :
            exit(1) ;

            default :
            printf("Wrong choice\n") ;
        }
    }

    return 0 ;
}