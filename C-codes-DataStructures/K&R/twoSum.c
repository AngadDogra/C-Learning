#include <stdio.h>

#define ARRAY_LENGTH 5

int main () {
    // Declare the array
    // Declare the sum
    // unsigned ? no because unsigned int means positive numbers only

    int i, j, sum, res ;
    int found = 0 ;                 // flag to check if found or not
    int array[ARRAY_LENGTH] ;

    printf("Enter the elements of the array (below): \n") ;
    for (i = 0 ; i < ARRAY_LENGTH; i++) {
        scanf("%d",&array[i]) ;
    }
    // we have the array now, printing the array for checking
    printf("The elements of the array are:\n") ;
    for (i = 0 ; i < ARRAY_LENGTH ; i++) {
        printf("%2d\n",array[i]) ;
    }
    
    printf("Enter the sum to be checked: ") ;
    scanf("%d",&sum) ;
    printf("The sum is: %d\n",sum) ;

    for(i=0 ; i < ARRAY_LENGTH - 1 ; i++){
        for (j = i + 1 ; j < ARRAY_LENGTH ; j++) {
            if (array[i] + array[j] == sum) {
               printf ("\nPair has been found %d and %d", array[i], array[j]) ;
               found = 1 ;
            }
        }
    }

    if (!found) {
        printf("\nNo pair exists.") ;
    }
    return 0 ;

}