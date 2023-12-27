// ANGAD DOGRA AIML-H BATCH -1
#include <stdio.h>
#include <math.h>

int main() {
    int arraySize ;
    printf("\nEnter the size of the array : ") ;
    scanf("%d" , &arraySize) ;

    // Asking the base of the numbers(radix)
    int radix ;
    printf("\nEnter the base of the numbers: ") ;
    scanf("%d",&radix) ;

    // Declaring input array. 
    int userInput[arraySize] ;
    
    // Taking user input.
    for(int i = 0 ; i < arraySize ; i++) {
        printf("\nEnter the %d element : " , i + 1) ;
        scanf("%d", &userInput[i]) ;
        // if(userInput[i] >= radix){
        //     printf("\nNumber you entered is greater than the base please restart") ;
        //     break ;
        // }    
    }

    // Finding the maximum number.
    int max = userInput[0];
    for(int i = 0 ; i < arraySize ; i++){
        if(userInput[i] > max)
            max = userInput[i] ;
    }
    printf("\nThe maximum element is : %d" , max) ;

    // Finding the digits of the max number.
    int rem = 0 , count = 0 ;
    while(max > 0 ){    
        count = count + 1 ;
        max = max/10 ;
    }
    printf("\n\n\tThe digits are: %d\n" , count) ;

    // Creating the bins array.
    int Bins[radix][radix] ; // if base = decimal then numbers are 0 , 1 , 2 ... 9 
    for(int i = 0 ; i < radix ; i++){
        for(int j = 0 ; j < radix ; j++){
            Bins[i][j] = 0 ;
        }
    }
    int exp = 1 ;

    for(int i = 0 ; i < arraySize ; i++){
        while(exp <= count){
            if(rem == 0 ){
                
                Bins[0][rem] = userInput[i] ;
            }
            else{
            Bins[i+1][rem] = userInput[i] ;
            }
        }
    }
    for(int i = 0 ; i < radix ; i++){
        for(int j = 0 ; j < radix ; j++){
            printf("%d  " , Bins[i][j]) ;
        }
        
    }

}
