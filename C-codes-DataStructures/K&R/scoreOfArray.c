#include <stdio.h>
#include <stdlib.h>

int main () {

    char *s = "hel" ;
    int sSize = 3 ;
 
    char *reverseS = malloc (sSize * sizeof(char));

    int j = 0 ; 

    for (int i = sSize - 1 ; i >= 0 ; i--) {
        reverseS[j] = s[i] ;
        j++ ; 
    }

    for (int i = 0 ; i < sSize ; i++) {
        printf("%c", reverseS[i]) ;
    }
}