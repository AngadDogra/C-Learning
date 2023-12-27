#include <stdio.h>
#include <stdlib.h>

struct snode{
    int data ;
    struct snode* next ;
};

struct dnode{
    struct dnode* prev ;
    int data ;
    struct dnode* next ;
};
// CIRCULAR SINGLY FUNCTIONS
struct snode* add_to_empty_single(int data){
    struct snode* temp = malloc(sizeof(struct snode));
    temp -> data = data ;
    temp -> next = temp ;
    return temp ;
}

struct snode* add_at_beg_single(struct snode* tail , int data){
    struct snode* newP = malloc(sizeof(struct snode));
    newP -> data = data ;
    newP -> next = tail -> next ;
    tail -> next = newP ;
    return tail;
}

struct snode* add_at_last_single(struct snode* tail , int data){
    struct snode* newP = malloc(sizeof(struct snode));
    newP -> data = data ;
    newP -> next = NULL ;
    newP -> next = tail -> next ;
    tail -> next = newP ;
    tail = tail -> next ;
    return tail ;
}

struct snode* del_first(struct snode* tail){
    struct snode* temp ;
    temp = tail -> next ;
    tail -> next = temp -> next ; 
    free(temp);
    temp = NULL ;
    return tail ;
}


void sprint(struct snode* tail){
    if(tail == NULL)
        printf("No node in the list");
    else{    
    struct snode* p = tail -> next ;
    // using do-while so that we can print the starting element
    do 
    {
        printf("%d  ",p->data);
        p = p -> next;
    }while(p!= tail->next);
    }
    printf("\n");
}
struct snode* createlist(struct snode* tail){
    int i , n , data ;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);

    if(n==0)
        return tail;
    printf("Enter the element of node 1 : ");
    scanf("%d",&data);
    tail = add_to_empty_single(data);

    for(i=1 ; i<n ; i++){
        printf("Enter the element of node %d : ",i+1);
        scanf("%d",&data);
        tail = add_at_last_single(tail , data);
    }    
    return tail ;
}

// CIRCULAR DOUBLY FUNCTIONS

struct dnode* add_to_empty_double( int data ) {
    struct dnode* temp = malloc(sizeof(struct dnode));
    temp -> data = data ;
    temp -> prev = temp ;
    temp -> next = temp ;
    return temp ;
}

struct dnode* add_at_beg_double(struct dnode* tail , int data){
    struct dnode* newP = add_to_empty_double(data);
    if(tail == NULL)
        return newP ;
    else {
        struct dnode* temp = tail -> next ;
        newP -> prev = tail ;
        newP -> next = temp ;
        temp -> prev = newP ;
        tail -> next = newP ;
        return tail ;
    }    
}

struct dnode* add_at_last_double(struct dnode* tail , int data){
    struct dnode* newP = add_to_empty_double(data);
    if (tail == NULL)
        return newP ;
    else{
        struct dnode* temp = tail -> next ;
        newP -> next = temp ;
        newP -> prev = tail ;
        tail -> next = newP ;
        temp -> prev = newP ;
        tail = newP ;
        return tail ;
    }    
}

struct dnode* del_first_double(struct dnode* tail){
    struct dnode* temp = tail -> next ;
    tail -> next = temp -> next ;
    temp -> next -> prev = tail ;
    free(temp);
    temp = NULL ;
    return tail ;
}


void dprint(struct dnode* tail){
    if(tail == NULL)
        printf("No node in the list");
    else{    
    struct dnode* p = tail -> next ;
    // using do-while so that we can print the starting element
    do 
    {
        printf("%d  ",p->data);
        p = p -> next;
    }while(p!= tail->next);
    }
    printf("\n");
}

int main(){
  struct dnode* tail = NULL ;
  tail = add_to_empty_double(89);
  tail = add_at_beg_double(tail , 45);
  tail = add_at_last_double(tail , 90);
  tail = del_first_double(tail);
  dprint(tail);

//   tail = createlist(tail);
//   print(tail);
  return 0 ;

}