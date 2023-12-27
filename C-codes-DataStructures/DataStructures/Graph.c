// ANGAD DOGRA - AIML-H BATCH-1
// Adjacency list is used to represent a graph when it is sparse(E << V^2). It is an array of linked lists.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list.
struct Node {
    int data ;
    struct Node* next ;
} ;

// Structure to represent a vertex of the graph.
struct Vertex {
    struct Node* head ; // Points to the first node in the adjacency list.
} ;

// Structure to represent the graph.
struct Graph {
    int V ;                // Number of vertices.
    struct Vertex* array ; // Array of vertices.
}

// Function to create a graph with " V " vertices.
struct Graph* createGraph(int V){
    struct Graph* graph = malloc(sizeof(struct Graph)) ;
    graph -> V = V ;
    
    // Create an array of vertices.
    graph -> array = (struct Vertex*)malloc(sizeof(struct Vertex)) ;
    
    // Initialize each adjacency list as empty.
    for (int i = 0 ; i < V ; i++){
        graph -> array[i].head = NULL ;
    }
    
    return graph ;
}

// Function to add edge between source node and destination node.
void addEdge(struct Graph* graph , int source , int destination) {
      // Create a new node for the destination vertex
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)) ;
      newNode -> data = destination ;
      newNode -> next = NULL ;
      
      // adding new node to the source vertex adjacency list , for un-directed graphs
      newNode -> next = graph -> array[src].head ;
      graph -> array[src].head = newNode ;
      
}
