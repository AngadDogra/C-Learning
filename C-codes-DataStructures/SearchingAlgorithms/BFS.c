// ANGAD DOGRA AIML-H BATCH 1
// BREADTH FIRST SEARCH
// OBJECTIVE : To search/traverse a tree data structure in the order of exploring all same level nodes first.
// DATA STRUCTURES USED : 
//            1) Queue : For enqueue and dequeue operations on source and following vertices.
//            2) Graph : The graph we wish to traverse/search in. (Represented using adjacency list(array of linked lists)).

#include <stdio.h>   // For basic printing and scanning functions.
#include <stdlib.h>  // For making structures.
#include <stdbool.h> // For TRUE and FALSE values.

#define WHITE 1
#define GREY 2
#define BLACK 3

// this structure represents a vertex of the graph.
struct Vertex{
    int data ;
    struct Vertex* next ;
}
// this structure represents the graph.
struct Graph{
    int numNodes ; //number of nodes
    struct Vertex* adjList[50] ; //adjacency list to represent a graph.
}

// function to create a new vertex of the graph.
struct Graph* 
int main(){




}
