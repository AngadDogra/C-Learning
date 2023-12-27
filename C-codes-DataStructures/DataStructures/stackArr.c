#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int stack_arr[MAX] ;
int top = -1 ;

void push(int data){
   
    if (top == MAX -1){
        printf("Stack Overflow !");
        return ;
    }
     top++ ;    
    stack_arr[top] = data ;
}

int pop(){
    int value ;
    if(top == -1){
        printf("Stack Underflow !");
        exit(1);
    }
    value = stack_arr[top];
    top-- ;
    return value ;
}

void print(){
    int i ;
    if(top == -1){
        printf("Stack Underflow!") ;
        return ;
    }    
    for (i = top ; i >= 0 ; i--){
        printf("%d\n",stack_arr[i]);
    }
}

void prime_fact(int num){
    int i = 2 ;
    while (num != 1){
        while(num % i == 0){
            push(i) ;
            num = num/i ;
        }
        i++ ;
    }
    printf("\nPrime factors of the number in descending order:\n ");
    while(top!= -1){
        printf("%d ", pop());
    }
}

void dec2bin(int dec){
    int rem ;
    while(dec != 1){
        rem = dec % 2 ;
        push(rem) ;
        dec = dec / 2 ;
    }

}

int main (){
    // int num ;
    // int choice , data ;
    // while(1){
    // printf("\n");
    // printf("1.Push\n2.Pop\n3.Print\n4.Exit");
    // printf("\nEnter your choice: ");
    // scanf("%d",&choice);

    // switch (choice){
    //     case 1 :
    //         printf("Enter the element to be pushed: ");
    //         scanf("%d",&data);
    //         push(data);
    //         break ;
    //     case 2 :
    //         data = pop() ;
    //         printf("Deleted element is %d\n",data) ;
    //         break ;
    //     case 3 :
    //         print();  
    //         break ;
    //     case 4 :
    //         exit(1);          

    // }
    // // }
    // printf("Please enter a positive number: ");
    // scanf("%d",&num) ;
    // prime_fact(num) ;
    int dec ;
    printf("Enter the decimal number: ");
    scanf("%d",&dec) ;
    dec2bin(dec) ;
    print();

    return 0 ;

    
}