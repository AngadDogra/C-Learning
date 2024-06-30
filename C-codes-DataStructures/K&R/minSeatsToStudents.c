#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

void swap(int* a, int* b) ;
int partition(int arr[], int low, int high) ;
void quickSort(int arr[], int low, int high) ;


int main () 
{
   
    /* Sort both the arrays, calculate difference of each element and sum it up*/
    
    int n  ;
    printf("Enter the number of students and seats: ") ;
    scanf("%d",&n) ;
    int *seats = (int *) malloc(n * sizeof(int)) ;
    int *students = (int *) malloc(n * sizeof(int)) ;

    printf("\nEnter the positions of the seats: ") ;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d",&seats[i]);
    }

    printf("\nEnter the positions of the students: ") ;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d",&students[i]);
    }

    quickSort (seats, 0, n-1) ;
    quickSort (students, 0, n-1) ;

    int result = 0 ;
    for (int i = 0 ; i < n ; i++) {
        result += abs(seats[i] - students[i]) ;
    }

    printf("\nThe result is : %d", result) ;
}

// Function to swap two elements 
void swap(int* a, int* b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

// Partition function 
int partition(int arr[], int low, int high) 
{ 

	// initialize pivot to be the first element 
	int pivot = arr[low]; 
	int i = low; 
	int j = high; 

	while (i < j) { 

		// condition 1: find the first element greater than 
		// the pivot (from starting) 
		while (arr[i] <= pivot && i <= high - 1) { 
			i++; 
		} 

		// condition 2: find the first element smaller than 
		// the pivot (from last) 
		while (arr[j] > pivot && j >= low + 1) { 
			j--; 
		} 
		if (i < j) { 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[low], &arr[j]); 
	return j; 
} 

// QuickSort function 
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) { 

		// call Partition function to find Partition Index 
		int partitionIndex = partition(arr, low, high); 

		// Recursively call quickSort() for left and right 
		// half based on partition Index 
		quickSort(arr, low, partitionIndex - 1); 
		quickSort(arr, partitionIndex + 1, high); 
	} 
} 
int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    
    int n  ;
    printf("Enter the number of students and seats: ") ;
    scanf("%d",&n) ;
    int *seats = (int *) malloc(n * sizeof(int)) ;
    int *students = (int *) malloc(n * sizeof(int)) ;

    printf("\nEnter the positions of the seats: ") ;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d",&seats[i]);
    }

    printf("\nEnter the positions of the students: ") ;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d",&students[i]);
    }

    quickSort (seats, 0, n-1) ;
    quickSort (students, 0, n-1) ;

    int result = 0 ;
    for (int i = 0 ; i < n ; i++) {
        result += abs(seats[i] - students[i]) ;
    }

   return result ;
}
// // driver code 
// int main() 
// { 
// 	int arr[] = { 19, 17, 15, 12, 16, 18, 4, 11, 13 }; 
// 	int n = sizeof(arr) / sizeof(arr[0]); 

// 	// printing the original array 
// 	printf("Original array: "); 
// 	for (int i = 0; i < n; i++) { 
// 		printf("%d ", arr[i]); 
// 	} 

// 	// calling quickSort() to sort the given array 
// 	quickSort(arr, 0, n - 1); 

// 	// printing the sorted array 
// 	printf("\nSorted array: "); 
// 	for (int i = 0; i < n; i++) { 
// 		printf("%d ", arr[i]); 
// 	} 

// 	return 0; 
// }
