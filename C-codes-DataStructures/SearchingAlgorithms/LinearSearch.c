//ANGAD DOGRA LINEAR SEARCH AIML-H-B1

#include <stdio.h>

int main(){
  
  int size ; // stores the size of the array
  printf("Enter the size of the array\n");
  scanf("%d",&size);
  
  int array[size] ; // declaring array of user-defined size
  
  for(int i = 0 ; i < size ; i++){
    printf("Enter the %d element of the array(in ascending order)\n",i+1) ;
    scanf("%d",&array[i]) ;
  }
  
  int target ; // declaring the target element
  printf("Enter the element to find\n") ;
  scanf("%d",&target) ;
  
  for(int i = 0 ; i < size ; i++){
    if(array[i] == target) // compares the target element with array iterator.
      printf("%d element found in %d position!",target , i+1) ;
  
  }
  
  return 0 ;
}
