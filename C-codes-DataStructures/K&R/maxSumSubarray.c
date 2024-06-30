#include <stdio.h>

int main ()
{
    // Max sum of subarray using sliding window:
    int length = 2 ;          // subrarray of length two ka sum

    int array[5] = {1, 4, 5, 3, 5} ;
    int arrayLength = 5 ;

    if (length > arrayLength) {
        printf("Cant find sum if subarray length greater than array") ;
    }

    int maxSum = 0 ;              // to hold the maximum sum

    // Computing the sum of the first window.
    for (int i = 0 ; i < length ; i++) {
        maxSum += array[i] ;
    }

    // Comparing the sum of the remaining windows.
    // For i to x, next windows sum will just be -arr[i] + arr[x + 1]
    int windowSum = maxSum ;
    for (int i = length ; i < arrayLength ; i++) {
        windowSum += array[i] - array[i - length] ;
        if (windowSum > maxSum) {
            maxSum = windowSum ;
        }
    }

    printf("\nThe maximum sum is: %d", maxSum);

}