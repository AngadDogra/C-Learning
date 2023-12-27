// ANGAD DOGRA AIML-H BATCH 1
// THIS IS THE CODE FOR THE KRUSKAL ALGORITHM 
// OBJECTIVE - FINDS THE MINIMUM SPANNING TREE OF A CONNECTED UNDIRECTED GRAPH

// ALGORITHM WORKS ON THE GREEDY METHOD - making a locally optimal choice in the hope of finding a globally optimal solution  

// SPANNING TREE : A spanning tree is a subset of a weighted connected graph.
// PROPERTIES : 
//            A minimum spanning tree has precisely n-1 edges for n edges in the graph.
//            The edge connecting two nodes which make a loop should not be added to the tree.

// DATA-STRUCTURES REQUIRED:
//            1 Two arrays for maintaining RANK VALUE and PARENT VALUE. 
//            2 One structure for keeping the edges of the graph.

                      
#include <stdio.h>
#include <stdlib.h>

int main(){

    // structure denotes a WEIGHTED edge of the graph.
    struct Edge{
          int source , destination , weight ;
    }
    
    // structure denotes a CONNECTED UNDIRECTED WEIGHTED graph.
    // basically the graph as a whole.
    struct Graph{
            int V , E ; // vertices and edges of the graph.
            struct Edge* edge ; // POINTER edge that points to STRUCTURE EDGE
    }
    
    // this function will generate/create a graph. WE DYNAMICALLY ALLOT MEMORY FOR IT BECAUSE WE
    // OUR GRAPH IS A DATA STRUCTURE OF UNKNOWN SIZE.
    struct Graph* generateGraph(int V , int E){
          struct Graph* graph = malloc(sizeof(struct Graph)) ; // memory allotted for graph node.
          graph -> V = V ; // vertex has been allotted its value.
          graph -> E = E ; // edge has been allotted its value.
          
          graph -> edge = (struct Edge*)malloc(sizeof(struct Edge)) ; //  
          return graph ;
    }
    
    // UNION-FIND ALGORITHM ????? 
    // How to divide set of vertices into disjoint sets in c ??

}
