#include <stdio.h>

#define WEEK_DAYS 7

int main () {

    int i, pos, buy, sell, flag ;
    int stockArr[WEEK_DAYS] ;

    for ( i = 0 ; i < WEEK_DAYS ; i++) {
        stockArr[i] = 0 ; 
    }

    printf("Enter stockprices for each day of the week:\n") ;
    for ( i = 0 ; i < WEEK_DAYS ; i++) {
        scanf("%d\n",&stockArr[i]) ;
    }    

    // now we find the lowest number and after it's position find the max difference
    buy = stockArr[0] ;
    for ( i = 1 ; i < WEEK_DAYS ; i++) {
        if(stockArr[i] < buy)
            buy = stockArr[i] ;
    }
    pos = i ; 
    
    sell = stockArr[i] ; 

    for (int j = pos ; j < WEEK_DAYS - 1 ; j++){
        for (int k = j + 1 ; k < WEEK_DAYS ; k++) {
            stockArr[j] - stockArr[i] ;
        }
    }

}