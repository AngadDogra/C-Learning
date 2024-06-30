#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) ;
void swap(int* xp , int* yp) ;
void BubbleSort(int arr[] , int n ) ;

int main ()
{   
    int difficultySize = 5, profitSize = 5, workerSize = 4 ;

    int difficulty[5] = {2, 4, 6, 8, 10} ;
    int profit[5] = {10, 20, 30, 40, 50} ;
    int worker[4] = {4, 5, 6, 7};

    int result = maxProfitAssignment(difficulty, difficultySize, profit, profitSize, worker, workerSize) ;
    printf("%d", result); 


}
int compareJobs(const void *a, const void *b) {
    return ((int *)a)[0] - ((int *)b)[0];
}

// Comparator function for sorting worker abilities
int compareWorkers(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    // Create a 2D array to store jobs with their difficulties and profits
    int jobs[difficultySize][2];
    for (int i = 0; i < difficultySize; i++) {
        jobs[i][0] = difficulty[i];
        jobs[i][1] = profit[i];
    }

    // Sort jobs by difficulty
    qsort(jobs, difficultySize, sizeof(jobs[0]), compareJobs);

    // Sort worker abilities
    qsort(worker, workerSize, sizeof(int), compareWorkers);

    int maxProfit = 0;
    int jobIndex = 0;
    int bestProfit = 0;

    for (int i = 0; i < workerSize; i++) {
        int ability = worker[i];

        // Find the best profit for the current worker's ability
        while (jobIndex < difficultySize && jobs[jobIndex][0] <= ability) {
            if (jobs[jobIndex][1] > bestProfit) {
                bestProfit = jobs[jobIndex][1];
            }
            jobIndex++;
        }

        // Add the best profit to the total profit
        maxProfit += bestProfit;
    }

    return maxProfit;

}