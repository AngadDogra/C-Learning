// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int arr1[3][3] = {{1 , 2 , 3},{4 , 5 ,6},{5 , 9 ,10}} ;
    int arr2[3][3] = {{1 , 2 , 3},{4 , 5 , 6} ,{5 , 9 , 10}} ;
    int arr3[3][3] ;
    
    int i , j , k ; 
    
    for(i = 0 ; i < 3 ; i++){
        for(j = 0 ; j < 3 ; j++){
            for(k = 0 ; k < 3 ; k++ ){
                // printf("the value of arr1 is: %d\n" , arr1[k][j]);
                // printf("the value of arr2 is: %d\n")
                arr3[i][j] += arr1[i][k] * arr2[k][j] ;
            }
        }
    }
    
    for(i = 0 ;i < 3 ; i++){
        for(j = 0 ; j < 3 ; j++){
            printf("%d " , arr3[i][j]) ;
        }
        printf("\n") ;
    }

    return 0;
}