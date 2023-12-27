// ANGAD DOGRA AIML-H BATCH-1

#include <stdio.h> 
#include <stdlib.h>

int main(){
    // Counting sort will require 3 arrays. 
    // Inputs : 
    //     Range of numbers ('k' value).
    //     Number in the original value.
    //     Array of size 'k' to store the frequency.


    int arraySize , k  ; // Storing array size and the k value.
    int count = 0 ; // counter used for finding frequency.
    printf("Enter the size of the array : ") ;
    scanf("%d" , &arraySize) ; 
    printf("\nEnter the maximum value the numbers can take(k value): ") ;
    scanf("%d" , &k) ; 
    int userInput[arraySize] , frequencyArray[k] , sortedArray[arraySize];

    // Taking user input for userInput array. 
    // Input can't exceed the k value.
    for(int i = 0 ; i < arraySize  ; i++){
        printf("\nEnter the %d element: " , i) ;
        scanf("%d" , &userInput[i]) ;
        if(userInput[i] > k ){
            printf("\nThe entered value exceeds the range.") ;
            exit(1) ;
        }    
    }

    // Printing the user array in the original order.
    printf("\nThe array you entered is: ") ;
    for(int i = 0 ; i < arraySize  ; i++){
        printf("%d  " , userInput[i]) ;
    }

    // Initializing frequency to 0.
    for(int i = 0 ; i <= k ; i++){
        frequencyArray[i] = 0 ;  
    }

    
    for(int i = 0 ; i < arraySize ; i++){
        // If the element is not visited
        if(userInput[i] == 0){
            frequencyArray[0] = frequencyArray[0] + 1 ;
        }
        if(userInput[i] == 1){
            frequencyArray[1] = frequencyArray[1] + 1 ;
        }
        if(userInput[i] == 2){
            frequencyArray[2] = frequencyArray[2] + 1 ;
        }
        if(userInput[i] == 3){
            frequencyArray[3] = frequencyArray[3] + 1 ;
        } 
        
    }
    // printing the frequency array.
    printf("\n\nThe frequency array is : ") ;
    for(int i = 0 ; i <= k ; i++){
        printf("%d  " , frequencyArray[i]) ;
    }


    // Adding the values accumutatively.
    for(int i = 1 ; i <= k ; i++){
        frequencyArray[i] = frequencyArray[i] + frequencyArray[i-1] ; 
    }
    // Printing the array again.
    printf("\n\nThe frequency array after adding is : ") ;
    for(int i = 0 ; i <= k ; i++){
        printf("%d  " , frequencyArray[i]) ;
    }

   for(int j = arraySize ;  j > 0 ; j--){
       sortedArray[frequencyArray[userInput[j - 1]]] = userInput[j-1] ;
       frequencyArray[userInput[j - 1]] = frequencyArray[userInput[j-1]] - 1 ;
   }

    // Printing the output array.
    printf("\n\nThe sorted array is: ") ;
    for (int i = 0 ; i < arraySize ; i++){
        printf("%d  " , sortedArray[i]) ;
    }
}