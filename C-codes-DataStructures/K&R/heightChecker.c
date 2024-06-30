#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        while (arr[j] > pivot) {
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
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

// Function to find the number of unusual instances
int findUnusualInstances(int* heights, int heightsSize) {
    int* expected = (int*)malloc(heightsSize * sizeof(int));
    int flagCount = 0;

    if (expected == NULL) {
        return -1;  // Memory allocation failed
    }

    for (int i = 0; i < heightsSize; i++) {
        expected[i] = heights[i];
    }

    quickSort(expected, 0, heightsSize - 1);

    for (int i = 0; i < heightsSize; i++) {
        if (expected[i] != heights[i]) {
            flagCount++;
        }
    }

    free(expected);
    return flagCount;
}
