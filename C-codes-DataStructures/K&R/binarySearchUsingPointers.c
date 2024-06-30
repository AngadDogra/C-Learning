#include <stdio.h>
#include <stdlib.h> 

int binarySearch (int *nums, int numsSize) ;


int main ()
{
    /* In the pointer approach, maintain two pointers for start and end*/
    int numsSize, target ;
    int *nums = (int *) malloc(numsSize * sizeof(int)) ;

    printf("Enter the size of the array: ") ;
    scanf("%d", &numsSize) ;

    printf("\nEnter the elements of the array: ") ;
    for (int i = 0 ; i < numsSize ; i++) {
        scanf("%d",&nums[i]) ;
    }

    printf("\nThe elements of the array are: ") ;
    for (int i = 0 ; i < numsSize ; i++) {
        printf("%d",nums[i]) ;
    }

    printf("\nEnter the element to be searched: ") ;
    scanf("%d", &target) ;

    
}

int binarySearch (int *nums, int numsSize)
{
    int *high, *low, mid ;

    high = &nums[0], low = &nums[numsSize - 1] ;

    while ( *high > *low ) {     // The value of high pointer > low pointer
        mid = (high + low) / 2 ; 
    }
}