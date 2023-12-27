//ANGAD DOGRA BATCH 1 - AIML - H 
#include  <stdio.h>

void dijkstraAlgorithm(int graph[6][6] , int src ){
      
      int distance[6] ;
      bool visited[6] ;
      
      for (int k = 0 ; k < 6 ; k++){
              distance[k] = INT_MAX ;
                visited[k] = false ;
      }
      
      distance[src] = 0 ;
      for(int k = 0 ; k < 6 ; k++){
          int m = miniDist(distance,visited) ;
          visited[m] = true ;
          for(int k = 0 ; k < 6 ; k++){
              //updating the distance of neighboring values
              if(!visited[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k] )
                    distance[k] = distance [m] + graph[m][k] ;
          }
      }
  

}
