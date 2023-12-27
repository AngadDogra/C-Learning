#include <stdio.h>
#include <stdlib.h>

// STRUCTURE DECLARATION
struct node{
    int data ;
    struct node* prev ;
    struct node* next ;
};

// THE FUNCTIONS
struct node* add_to_empty(struct node* head , int data ){
    struct node* temp = malloc(sizeof(struct node));
    temp -> prev = NULL ;
    temp -> data = data ;
    temp -> next = NULL ;

    head = temp ;
    return head ;
}
struct node* add_at_beg(struct node* head , int data){
    struct node* temp = malloc(sizeof(struct node));
    temp -> prev = NULL ;
    temp -> data = data ;
    temp -> next = NULL ;
    temp -> next = head ;
    head -> prev = temp ;
    head = temp ;
    return head ;
}

struct node* add_at_end(struct node* head , int data){
    struct node* temp , *tp ;
    temp = malloc(sizeof(struct node));
    temp -> prev = NULL ;
    temp -> data = data ;
    temp -> next = NULL ;

    tp = head ;
    while(tp -> next != NULL){
        tp = tp -> next;
    }
    tp -> next = temp ;
    temp -> prev = tp;
    return head ;
}

void del_first(struct node* head){
    struct node* temp = head ;
    head = head -> next ;
    free(temp);
    temp = NULL ;
    head -> prev = NULL ;
}

void del_last(struct node* head){
    struct node* temp , *temp2 ;
    temp = head ;
    while(temp -> next != NULL){
        temp = temp -> next ;
    }
    temp2 = temp -> prev ;
    temp2 -> next = NULL ;
    free(temp);
    temp = NULL ;
}

// CREATELIST FUNCTION
struct node* createlist(struct node* head){
    int n , data , i ;
    printf("Enter the number of nodes  :");
    scanf("%d",&n);

    if(n == 0)
        return head ;

    printf("Enter the element for node 1 :");
    scanf("%d",&data);
    head = add_to_empty(head , data);

    for(i=1 ; i<n ; i++){
        printf("Enter the data for node %d : ",i+1);
        scanf("%d", &data);
        head = add_at_end(head , data);
    }
    return head ;
}



int main(){
     struct node* head = NULL ;
     struct node* ptr ;
    // head = add_to_empty(head , 45);
    // head = add_at_beg(head , 26);
    // head = add_at_end(head , 9);

    head = createlist(head);
   
    ptr = head ;
    while(ptr!=NULL){
        printf("%d\n", ptr->data);
        ptr = ptr -> next ;
    }
    return 0 ;
}
