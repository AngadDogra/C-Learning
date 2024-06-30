#include <stdio.h>

#define MAXLEN 100 

int main () 
{
    int arr1[11] = {2,3,1,3,2,4,6,7,9,2,19} ; 
    int arr2[6] = {2,1,4,3,9,6} ;
    int arr3[MAXLEN] ;                       // To store the relative sorted array

    int arr1Size = sizeof(arr1) / sizeof(arr1[0]) ;
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]) ;

    int i, j, k ;                            // iterators

    /*Logic : 

        Outer loop i for arr2[] (acts as index)
            Inner loop j for arr1[] (compares each element)
    */
   k = 0 ; 
   int n = arr1Size ;

   // A boolean array to mark visited elements in arr1
   int visited[arr1Size] ;
   for (i = 0 ; i < arr1Size ; i++) {
        visited[i] = 0 ;
   }

   for (i = 0 ; i < arr2Size ; i++){
        for (j = 0 ; j < arr1Size ; j++){
            if (arr2[i] == arr1[j]) {
                arr3[k] = arr1[j] ;
                k++ ;
                visited[j] = 1 ;
            }
        }
   }

   // Remaining elements to the end of arr3
   for (j = 0 ; j < arr1Size ; j++) {
        if (!visited[j]){
            arr3[k] = arr1[j] ;
            k++ ;   
        }
   }

   for (i = 0 ; i < arr1Size ; i++) {
        printf("%d ", arr3[i]) ;
   }

   return 0 ;
}


#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int* arr3 = (int*)malloc(arr1Size * sizeof(int)); // Dynamically allocate memory for arr3
    int visited[arr1Size]; // To mark visited elements
    int i, j, k = 0;

    // Initialize visited array to 0
    for (i = 0; i < arr1Size; i++) {
        visited[i] = 0;
    }

    // First, place elements from arr1 that are in arr2 in the correct order
    for (i = 0; i < arr2Size; i++) {
        for (j = 0; j < arr1Size; j++) {
            if (arr2[i] == arr1[j] && !visited[j]) {
                arr3[k++] = arr1[j];
                visited[j] = 1;
            }
        }
    }

    // Then, place remaining elements from arr1 not in arr2 in ascending order
    for (i = 0; i < arr1Size; i++) {
        if (!visited[i]) {
            arr3[k++] = arr1[i];
        }
    }

    // Sort the remaining elements
    for (i = arr2Size; i < k - 1; i++) {
        for (j = arr2Size; j < k - 1 - i + arr2Size; j++) {
            if (arr3[j] > arr3[j + 1]) {
                int temp = arr3[j];
                arr3[j] = arr3[j + 1];
                arr3[j + 1] = temp;
            }
        }
    }

    *returnSize = arr1Size;
    return arr3;
}

int main() {
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    int arr2[] = {2, 1, 4, 3, 9, 6};
    int returnSize;
    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);

    int* sortedArray = relativeSortArray(arr1, arr1Size, arr2, arr2Size, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", sortedArray[i]);
    }

    free(sortedArray); // Free the allocated memory

    return 0;
}
