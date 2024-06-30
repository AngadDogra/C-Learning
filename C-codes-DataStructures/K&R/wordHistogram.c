#include <stdio.h>  

#define MAXLEN 30


int main () {

    int c, i, j, count, max ;
    int array[MAXLEN], array2[MAXLEN] ;
    i = 0 ;
    max = 0 ;

    for (j = 0; j < MAXLEN ; j++){
        array[j] = 0 ;
        array2[j] = 0 ;
    }


    while ( (c = getchar()) != EOF ){
        if ((c != ' ') && (c != '\n')) {
            count++ ;
        } else {
            if (count > 0){
                    array[i] = count ;
                    i++ ; 
                    count = 0 ;
            }

            if ( c == '\n') {
                max = array[0] ;
                for (j = 1 ; j < i  ; j++) {
                    if (array[j] > max){
                        max = array[j] ;
                    } 
                }
                for (j = 0 ; j < i  ; j++) {
                    array2[j] =  (array[j] * 15 ) /  max ; 
                    for (int k = 0 ; k < array2[j] ; k++) {
                        printf("* ") ;
                    }
                    printf("\n") ;
                }

                // Reset for the next line
                for (j = 0 ; j < MAXLEN ; j++) {
                    array[j] = 0 ;
                    array2[j] = 0 ;
                }
                i = 0 ;
            }
        }   
    }
}