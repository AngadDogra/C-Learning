#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



#define V 4



// Function to check if a vertex v can be added at the current index in the path
int isFeasible(int v, int path[], int pos, int graph[V][V]) {
if (!graph[path[pos - 1]][v])
return 0;



for (int i = 0; i < pos; i++)
if (path[i] == v)
return 0;



return 1;
}



// Recursive function to solve the Traveling Salesman Problem using Branch and Bound
void tspBranchAndBoundUtil(int graph[V][V], int path[], int bound, int cost, int pos, int *minCost) {
if (pos == V) {
// If all cities are visited, update the minimum cost
*minCost = cost + graph[path[pos - 1]][path[0]];
return;
}



for (int v = 1; v < V; v++) {
if (isFeasible(v, path, pos, graph)) {
int newBound = bound - graph[path[pos - 1]][path[pos]] + graph[path[pos - 1]][v];
int newCost = cost + graph[path[pos - 1]][v];



path[pos] = v;
tspBranchAndBoundUtil(graph, path, newBound, newCost, pos + 1, minCost);



// Reset the path and continue to the next iteration
path[pos] = -1;
}
}
}



// Wrapper function to solve the Traveling Salesman Problem using Branch and Bound
void tspBranchAndBound(int graph[V][V]) {
int path[V];
path[0] = 0;
for (int i = 1; i < V; i++)
path[i] = -1;



int minCost = INT_MAX;



// Calculate the initial lower bound for the root node
int bound = 0;
for (int i = 0; i < V; i++)
bound += (graph[i][0] != 0) ? graph[i][0] : INT_MAX;



tspBranchAndBoundUtil(graph, path, bound, 0, 1, &minCost);



printf("Minimum Cost: %d\n", minCost);
}



int main() {
int graph[V][V] = {
{0, 10, 15, 20},
{10, 0, 35, 25},
{15, 35, 0, 30},
{20, 25, 30, 0}
};



tspBranchAndBound(graph);



return 0;
}
