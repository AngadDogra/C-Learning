#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

int minDays(int* bloomDay, int bloomDaySize, int m, int k) ;
bool isPossible(int *bloomDay, int bloomDaySize, int m, int k, int day) ;

int main ()
{
    int bloomDay[6] = {1, 10, 2, 10, 3, 10} ;
    int bloomDaySize = 6 ;
    int m = 3 ;                               // Number of bouquets
    int k = 1 ;                               // Number of flowers in each bouquet

    int result = minDays(bloomDay, bloomDaySize, m, k);

    printf("%d", result) ;   
}

int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    
    if (m*k > bloomDaySize) {
        return -1 ;
    }

    int low = 0 , high = bloomDay[0], mid ;
    for (int i = 1 ; i < bloomDaySize ; i++) {
        if (bloomDay[i] > high)
            high = bloomDay[i] ;
    }

    // Binary Search to search for the minimum no. of days
    while (low < high) {
        mid = (low + high)/2 ;
        
        if(isPossible(bloomDay, bloomDaySize, m, k, mid)) {
            high = mid ;
        }
        else {
            low = mid + 1 ;
        }
    }    

    return low ;              // Why return low ? 

}

bool isPossible(int *bloomDay, int bloomDaySize, int m, int k, int day) {
    int total = 0 ;

    for ( int i = 0; i < bloomDaySize ; i++) {
        int count = 0 ;
        while ( i < bloomDaySize && count < k && bloomDay[i] <= day) {
            count++ ; 
            i++ ;
        }

        if (count == k ) { 
            total++ ;
            i-- ;
        }

        if (total >= m) {
            return true ;
        }
    }
    return false ;
}
