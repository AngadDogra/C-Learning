#include <stdio.h>

int main(){

    int rows1 , rows2 , columns1 , columns2 ;
    printf("rows in first matrix: ") ;
    scanf("%d",&rows1) ;
    printf("\ncolumns in first matrix: ") ;
    scanf("%d",&columns1) ;
    printf("\nrows in second matrix: ") ;
    scanf("%d",&rows2) ;
    printf("\ncolumns in second matrix: ") ;
    scanf("%d",&columns2) ;

    int arr1[rows1][columns1] , arr2[rows2][columns2] , arr3[rows1][columns2] ;

    (columns1 == rows2)?printf("\nmatrix multiplication possible!"):printf("\nmultiplication not possible :(") ;


    for(int i = 1 ; i < rows1 ; i++){
        printf("enter the %d row elements: ",i);
        for(int j = 1 ; j < columns1 ; j++){
            scanf("%d",&arr1[i][j]) ;
        }
        printf("\n") ;
    }

    for(int i = 1 ; i < rows2 ; i++){
        printf("enter the %d row elements: ",i);
        for(int j = 1 ; j < columns2 ; j++){
            scanf("%d",&arr2[i][j]) ;
        }
        printf("\n") ;
    }
    
    
    for(int i = 1 ; i < rows1 ; i++){
        for(int j = 1 ; j < columns2 ; j++){
            for(int k = 0 ; k < rows1 ; k++){
                arr3[i][j] += arr1[i][k]*arr2[k][j] ;
            }
        }
    }

    for(int i = 1 ; i < rows1 ; i++){
        for(int j = 1 ; j < columns2 ; j++){
            printf("%d ",arr3[i][j]) ;
        }
        printf("\n") ;
    }



}