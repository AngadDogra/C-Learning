#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do {
        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi; // index of pivot after partition
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // sort left sub-array
        quickSort(arr, pi + 1, high); // sort right sub-array
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    print(arr, n);

    clock_t start_time = clock();
    quickSort(arr, 0, n - 1);
    clock_t end_time = clock();

    printf("Sorted elements:\n");
    print(arr, n);

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken for Quicksort: %f seconds\n", time_taken);

    free(arr);
    return 0;
}
