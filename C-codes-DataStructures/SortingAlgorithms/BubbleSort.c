//ANGAD DOGRA AIML-H-B1 BUBBLE SORT

#include <stdio.h>
#include <stdbool.h>

void swap(int* xp , int* yp){// function to swap numbers after comparison
    int temp = *xp ; 
    *xp = *yp ;
    *yp = temp ;

}

void BubbleSort(int arr[] , int n ) {

        int i , j , temp ; // i and j are iterators , temp is used to swap numbers after comparison
        bool swapped ; // has value 0 if not swapped and 1 if swapped

        for( i = 0 ; i < n - 1 ; i++){
            swapped = false ;
            for( j = 0 ; j < n - i - 1 ; j++){

                    if(arr[j] > arr[j+1]) {
                        swap(&arr[j] , &arr[j + 1]) ;
                        swapped = true ;
                    }
           
            }

            if(swapped == false)
                break ;
        }
}

void printArray( int arr[] , int size) { // function to print the array

    int i ;
    for(int i = 0 ; i < size ; i++)
        printf("%d " , arr[i]) ;
}

int main() {
    int arr[] = {8 , 5 , 3 , 9  ,  4 , 1 } ; // input array 
    int n = sizeof(arr)/sizeof(arr[0]) ; // calculating the size of the array
    BubbleSort(arr , n) ; // calling respective functions
    printf("Sorted array: \n") ;
    printArray(arr , n) ;
    
    return 0 ;
}
