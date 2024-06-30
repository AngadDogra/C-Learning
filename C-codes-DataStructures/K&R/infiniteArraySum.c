#include <stdio.h>
#include <stdlib.h>

int minSizeSubarray(int* nums, int numsSize, int target) ;

int main () {
    
    int numsSize, target ;
    printf("Enter the size of the array: ") ;
    scanf("%d", &numsSize) ;

    int *nums = malloc (numsSize * sizeof(int)) ;
    printf("\nEnter the elements of the array: ") ;
    for (int i = 0 ; i < numsSize ; i++) {
        scanf("%d", &nums[i]) ;
    }

    printf("\nEnter the target sum: ") ;
    scanf("%d",&target) ;

    int result = minSizeSubarray(nums , numsSize , target) ;
    printf("The length of minimum subarray with sum %d is %d ", target, result) ;

}

int minSizeSubarray(int* nums, int numsSize, int target) {
    int length=0;
    // int i=0;
    int max=0;
    while(target){
        max=0;
        for(int j=0;j<numsSize;j++){
            if(nums[j]>max && nums[j]<=target){
                max=nums[j];
            }
        }
        printf("current target: %d \tCurrent max: %d",target,max);
        printf("\n");
        if(target<max||max==0){
            break;
        }
        target-=max;
        length++;
    }
    if(target==0){
        return length;
    }else{
        return -1;
    }
}


