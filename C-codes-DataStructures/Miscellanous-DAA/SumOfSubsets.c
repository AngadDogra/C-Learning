#include <stdio.h>

#define MAX 10

void displaySubset(int subset[], int size) {
    printf("Subset: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

// Function to find all subsets with the given sum
void subsetSum(int set[], int subset[], int n, int sum, int currentSum, int start) {
    if (currentSum == sum) {
        displaySubset(subset, start);
        return;
    }

    for (int i = start; i < n; i++) {
        if (currentSum + set[i] <= sum) {
            subset[start] = set[i];
            subsetSum(set, subset, n, sum, currentSum + set[i], start + 1);
        }
    }
}

int main() {
    int set[MAX];
    int subset[MAX];
    int n, sum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: \n");
    scanf("%d", &sum);

    printf("Subsets with sum %d are:\n", sum);
    subsetSum(set, subset, n, sum, 0, 0);

    return 0;
}
