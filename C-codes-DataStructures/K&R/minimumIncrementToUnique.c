#include <stdio.h>
#include <stdlib.h>

int minIncrementForUnique(int* nums, int numsSize) ;

int main () 
{
    int numsSize ;
    int count = 0 ;
    printf("Enter the zise of the array: ") ;
    scanf("%d", &numsSize) ;

    int *nums = (int *) malloc (numsSize * sizeof(int)) ;
    printf("\nEnter the elements of the array: ") ;
    for (int i = 0 ; i < numsSize ; i++) {
        scanf("%d",&nums[i]) ;
    }

    count = minIncrementForUnique(nums, numsSize) ;

    printf("\nThe minimum number of moves is %d", count) ;
}

int minIncrementForUnique(int *nums, int numsSize) 
{
    int result = 0 ;
    int max = nums[0] ;
    for (int i = 1 ; i < numsSize ; i++) {
        if (nums[i] > max) 
            max = nums[i] ;
    }

    int freqSize = numsSize + max ;

    int *freq = (int *) calloc(freqSize , sizeof(int)) ;

    for (int i = 0 ; i < numsSize ; i++) {
        freq[nums[i]] ++ ;
    }

    for (int i = 0 ; i < freqSize ; i++) {
        if (freq[i] > 1 ) {
            int excess = freq[i] - 1 ;
            freq[i + 1] += excess ;
            result += excess ;
        }
    }
    free(freq) ;
    return result ;
}