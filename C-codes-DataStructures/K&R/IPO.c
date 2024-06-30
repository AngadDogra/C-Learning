#include <stdio.h> 
#include <stdlib.h>

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) ;


int main () 
{
    int k,  w,  profitsSize,  capitalSize ;

    

    printf("Enter the k value: ") ;
    scanf("%d", &k) ;
    printf("\nEnter the start capital (w): ") ;
    scanf("%d", &w) ;
    printf("\nEnter the profit size: ") ;
    scanf("%d", &profitsSize) ;
    printf("\nEnter the capital size: ") ;
    scanf("%d", &capitalSize) ;

    int *profits = (int *) malloc (profitsSize * sizeof(int)) ;
    int *capital = (int *) malloc (capitalSize * sizeof(int)) ;

    printf("\nEnter the profit array: ") ;
    for (int i = 0 ; i < profitsSize ; i++) {
        scanf("%d", &profits[i]) ;
    }

    printf("\nEnter the capital array: ") ;
    for (int i = 0 ; i < capitalSize ; i++) {
        scanf("%d", &capital[i]) ;
    }    

    int result = findMaximizedCapital(k,w,profits,profitsSize,capital,capitalSize) ;
    printf("\nThe maximum profit is: %d",result) ;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) 
{
   
    int duplicate, numProjects = 0 ;

    if (k >= capitalSize) {
        for (int i = 0 ; i < profitsSize ; i++) {
            w += profits[i] ;
        }
    }else {
            for (int j = 0 ; j < capitalSize ; j++) {
                if (k > numProjects) {
                    duplicate = 0 ;
                    if (w == capital[j] || w > capital[j]){
                        for (int m = j + 1 ; m < capitalSize ; m++) {
                            if (capital[m] == capital[j]){
                                duplicate = 1 ;
                                if (profits[m] > profits[j]){
                                    w += profits[m] ;
                                    numProjects++ ;
                                }    
                            }
                        }
                        if (!duplicate) {
                            w += profits[j] ;
                            numProjects++ ;
                        } 
                    }   
                }    
            }
        

    }

    return w ;
}