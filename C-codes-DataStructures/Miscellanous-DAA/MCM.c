// OBJECTIVE : To determine the optimal parenthesize(ation) of product of n matrices.

#include <stdio.h>
#include <limits.h>



// Function to return the minimum number of operations for a given sequence
int matrixchainmultiplication(int p[] , int n){
    // p[] stores the dimensions of the matrices.
    // n is the number of matrices
    
    int m[n][n] , s[n][n] ;
    // m[p][q] stores the minimum cost of Matrix Chain Ap Ap+1 ... Aq.
    // s[p][q] will store the ' k ' value where we split/parenthize the chain Ap...Aq.
    
    int i , j , k , c ; // i = row iterator , j = column iterator , c = chainlength ( will start from 2 because only 1 matrix in chain is senseless).
    int currentsol ; // stores the minimum scalar multiplications or cost.
    
    
    for( i = 1 ; i <= n ; i++){
        m[i][i] = 0 ; // The cost of multipling nothing is 0.
    }
    
    for(c = 2 ; c <= n ; c++){
        for( i = 1 ; i <= n - c + 1 ; i++){
              j = i + c - 1 ; // for the condition where j is greater than i.
              m[i][j] = INT_MAX ;
              
              for( k = i ; k <= j - 1 ; k++){
                  currentsol = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j] ;
                  if(currentsol < m[i][j]){
                      m[i][j] = currentsol ;
                      s[i][j] = k ;
                  }
              }
            
        }
    }
return m[1][n-1] ;    
}


int main(){
    int n = 0 ; // number of matrices.
    printf("\nEnter the number of matrices: ") ;
    scanf("%d",&n) ;
    
    int p[n] ; // array that stores dimensions of the n matrices.

    // Taking input of the dimensions.
    printf("Enter the elements of the dimension array Ex : [2 3 4 5] : ") ;
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&p[i]) ;
    }
    
    // calling the function now that we have p[] and n.
    printf("\nThe minimum number of scalar operations are : %d", matrixchainmultiplication(p , n)) ;
}
