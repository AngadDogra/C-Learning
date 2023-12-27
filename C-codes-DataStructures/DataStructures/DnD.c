#include <stdio.h>
#define EOF -1
int encrypt(int) ;
int main(){
    // int d1 , d2 , d3 , d4 ;
    // int arr[4] ;
    // printf("\nEnter the first digit: ") ;
    // scanf("%d",&d1) ;
    // printf("\nEnter the second digit: ") ;
    // scanf("%d",&d2) ;
    // printf("\nEnter the third digit: ") ;
    // scanf("%d",&d3) ;
    // printf("\nEnter the fourth digit: ") ;
    // scanf("%d",&d4) ;

    // d1 = encrypt(d1) ;
    // d2 = encrypt(d2) ;
    // d3 = encrypt(d3) ;
    // d4 = encrypt(d4) ;

    // arr[0] = d3 ;
    // arr[1] = d4 ;
    // arr[2] = d1 ;
    // arr[3] = d2 ;

    // printf("\nThe encrypted data is:") ;
    // for(int i = 0 ; i < 4 ; i++){
    //     printf("%d ",arr[i]) ;
    // }
    printf("The variable (%c) has the value %d" , 'a' , 'a') ;

    
}
int encrypt(int n){
    n = n + 7 ;
    n = n % 10 ;
    return n ;
}