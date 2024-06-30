#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

int main ()
{   
    char s[MAXLEN] ;
    int i, j, diff, countA, countB, currentPassSum = 0, result = 0 ;

    printf("Enter the string (A/B): ");
    // Use fgets to read a line of input and store it in s
    if (fgets(s, MAXLEN, stdin) != NULL) {
        // Remove the newline character if it is present
        size_t len = strlen(s);
        if (len > 0 && s[len - 1] == '\n') {
            s[len - 1] = '\0';
        }
        printf("\nYou entered: %s\n", s);
    } else {
        printf("Error reading input.\n");
    }
    size_t len = strlen(s) ;
    printf("%d", len) ;

    diff = 'B' - 'A' ;
    // Okay now the input is in s.

    for ( i = 0 ; i < len ; i++){

        if (s[i] == 'A')
            countA++ ;
        else
            countB++ ; 

        for ( j = i + 1 ; j < len ; j++) {
            countA, countB = 0 ;
            if (s[j] == 'A')
                countA++ ;
            else
                countB++ ;    

            currentPassSum = countA + countB ;    
            if (currentPassSum % diff == 0)
                result++ ;
            printf    
            printf("\nThis number of A in this pass are %d and B are %d", countA, countB) ;    
        }
    }

}