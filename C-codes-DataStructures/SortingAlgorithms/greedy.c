#include <stdio.h>


void swap(float *a, float *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(float array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}


int main(){

    int n , bound ;
    printf("enter the number of objects: ") ;
    scanf("%d",&n) ;
    printf("\nenter the bound(capacity of the bag): ") ;
    scanf("%d",&bound) ;
    float obj[n] , profit[n] , weight[n] , profitByWeight[n] ;


    // input the profit array
    for(int i = 0 ; i < n ; i++){
        printf("\nenter the profit of object %d: ",i+1) ;
        scanf("%f",&profit[i]) ;
    }
    // print the profit array
    printf("\nthe profit array is : ");
    for(int i = 0 ; i < n ; i++){
            printf("%.2f " , profit[i]) ;
    }

    // input the weight array
    for(int i = 0 ; i < n ; i++){
        printf("\nenter the weight of object %d: ",i+1) ;
        scanf("%f",&weight[i]) ;
    }
    // print the weight array
    printf("\nthe weight array is: ") ;
    for(int i = 0 ; i < n ; i++){
        printf("%.2f " , weight[i]) ;
    }  

    // initialising the profitByWeight array

    for(int i = 0 ; i < n ; i++){
        profitByWeight[i] = profit[i]/weight[i] ;
    } 

    for(int i = 0 ; i < n ; i++){
        printf("\n%.2f",profitByWeight[i]) ;
    }

    for(int   i = 0 ; i < n ; i++){

    }


}