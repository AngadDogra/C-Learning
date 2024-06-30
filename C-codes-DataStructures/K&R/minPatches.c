/*  Aim: given sorted array and a target, 

    Find all the possible sums w/o patches and store in sumArray.
    From 1-target, find the sums that are not there by comparing with sumArray.
    We need to include those sums by adding the minimum number of numbers to complete the sum.
    Store the required sums in an requiredArray.
    Calculate the difference of requiredArray[0] with every element of sumArray.

*/

#include <stdio.h> 
#include <stdlib.h>

int minPatches (int *nums , int numsSize, int n) ;


int main () 
{
    int nums[] = {1, 2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int n = 5;
    
    int result = minPatches(nums, numsSize, n);
    printf("Minimum number of patches: %d\n", result);
    
    return 0;
}

int minPatches (int *nums , int numsSize, int n) {
    long maxReach = 0 ; 
    int patches = 0 ;
    int index = 0 ;

    while (maxReach < n) {
        if (index < numsSize && nums[index] <= maxReach + 1){
            maxReach += nums [index] ;
            index++ ;
        } else {
            maxReach += maxReach + 1 ;
            patches++ ; 
        }
    }
    return patches ;
}