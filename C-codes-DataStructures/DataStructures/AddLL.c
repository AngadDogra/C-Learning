#include <stdio.h>
#include <stdlib.h>

struct node{
    int number ;
    struct node* link ;
};

struct node* add_node(struct node* head , int number){
    struct node* newP = malloc(sizeof(struct node));
    newP -> number = number ;
    newP -> link = NULL ;

    newP -> link = head ;
    head = newP ;
    return head ;
}
struct node* createLL(struct node* head , int n ){

    while(n != 0){
        head = add_node(head , n%10) ;
        n = n/10 ;
    }
    return head ;
}

struct node* reverseLL(struct node* head){
    
    if (head == NULL)
        return head ;

    struct node* current = NULL ;
    struct node* next = head -> link ;
    head -> link = NULL ;

    while(next != NULL){
        current = next ;
        next = next -> link ;
        current -> link = head ;
        head = current ;
    }
    return head ;
}

struct node* push(struct node* head , int sum){
    struct node* newP = malloc(sizeof(struct node));
    newP -> number = sum ;
    newP -> link = head ;
    head = newP ;
    return head ;
}

struct node* add(struct node* head1 , struct node* head2){
    struct node* ptr1 = head1 ;
    struct node* ptr2 = head2 ;
    struct node* head3 = NULL ;
    int carry = 0 , sum = 0 ;
    while(ptr1 || ptr2){
        sum = 0 ;
        if(ptr1)
            sum += ptr1 -> number ;
        if(ptr2)
            sum += ptr2 -> number ;
        sum += carry ;
        carry = sum/10 ;
        sum = sum%10 ;

        head3 = push(head3 , sum);
        if(ptr1)
            ptr1 = ptr1 -> link ;
        if(ptr2)
            ptr2 = ptr2 -> link ;
        }
    if(carry)
        head3 = push(head3 , carry);

    return head3 ;    
}
void print(struct node* head){
    struct node* temp = head ;
    if(head == NULL)
        printf("No number present!");
    else{
        while(temp -> link != NULL){
            printf("%d -> ", temp -> number);
            temp = temp -> link ;
        }
        printf("%d",temp -> number);
    }    
}

void back2num(struct node* head){
    struct node* temp = head ;
    while(temp)
    {
        printf("%d",temp->number);
        temp = temp -> link ;
    }
    return ;
}

int main(){
    int a , b ;
    printf("Enter the two numbers : ");
    scanf("%d %d" , &a , &b);
    printf("\n Linked list representaion of first number : \n");
    struct node* head1 = NULL ;
    head1 = createLL(head1 , a);
    print(head1);

    struct node* head2 = NULL ;
    printf("\nLinked list representation of second number : \n");
    head2 = createLL(head2 , b);
    print(head2);

    head1 = reverseLL(head1) ;
    head2 = reverseLL(head2) ;

    printf("\nReversed linked lists are : \n") ;
    print(head1) ;
    printf("\n") ;
    print(head2) ;

    struct node* head3 = NULL ;
    head3 = add(head1 , head2) ;
    printf("\nResultant linked list after addition: \n") ;
    print(head3) ;
    
    back2num(head3);

    return 0 ;
}