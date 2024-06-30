// Take number of blanks as input and fill those blanks with tabs and blanks.

#include <stdio.h>

#define TABSTOP 4 

void entab () ;

int main () {
    entab () ;

    return 0 ; 
}

void entab () {
    int c, i, nt, nb ;
    nb = nt = 0 ;
    int pos = 0 ;

    while ( (c = getchar()) != EOF) {
        if (c == ' '){
            nb++ ;        // counting the consecutive blanks
            if (pos % TABSTOP == TABSTOP - 1) {
                // Reached a tabstop, now print tab and reset blank counter
                nt++ ;
                nb = 0 ;
            }
        } else {
            // Print the tabs
            while (nt > 0) {
                putchar ('|') ;
                nt-- ;
            }
            while (nb > 0) {
                putchar ('.') ;
                nb-- ;
            }
            putchar (c) ;
            if (c == '\n') {
                pos = 0 ;
            } else {
                pos++ ;
            }
        }
    }
}