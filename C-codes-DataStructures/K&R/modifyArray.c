#include <stdio.h>

void modifyArray (char arr[], int size) ;

int main ()
{
    int array[5] = {0} ;
    int i = 0 ; 

    printf("Array before modification: ") ;

    for ( ; i < 5 ; i++) {
        printf(" %d ", array[i]) ;
    }

}