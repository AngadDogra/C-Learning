// ANGAD DOGRA AIML - H
// THIS IS A CODE FOR BELLMAN FORD ALGORITHM
// DATA STRUCTURES USED -
//      GRAPH - Represented using a linked list
#include <stdio.h> 
#include <stdlib.h>

struct Edge{ // the structure represents edges of the graph
    int source ;
    int destination ; 
    int weight ;
} ;

struct Graph{ // the structure represents the graph itself
    int V ; // vertices
    int E ; // edges
    struct Edge* edge ;   
} ;


// this function will generate/create a graph. WE DYNAMICALLY ALLOT MEMORY FOR IT BECAUSE WE
// OUR GRAPH IS A DATA STRUCTURE OF UNKNOWN SIZE.
struct Graph* generateGraph(int V , int E){
      struct Graph* graph = malloc(sizeof(struct Graph)) ; // memory allotted for graph node.
        graph -> V = V ; // vertex has been allotted its value.
        graph -> E = E ; // edge has been allotted its value.
          
        graph -> edge = (struct Edge*)malloc(sizeof(struct Edge)) ; //  
        return graph ;
}
int main (){
    
    int V,E,S ; // V = no. of vertices , E = no. of edges , S is the source vertex
    
    printf("Enter number of vertices in graph:\n ") ; //  input for vertices
    scanf("%d",&V) ;
    printf("Enter number of edges in graph: \n") ;     // input for graph
    scanf("%d",&E) ;
    printf("Enter the source vertex number:\n ") ;    // input for source
    scanf("%d",&S) ;
}
