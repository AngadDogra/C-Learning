#include <stdio.h>

#define TABSTOP 4  // Set the number of columns per tab stop

void detab () ; // Declaration

int main() {

    detab();  // Call the detab function to process input

    return 0;
}


void detab() {
    int c;
    int column = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TABSTOP - (column % TABSTOP);  // Calculate spaces to the next tab stop
            for (int i = 0; i < spaces; ++i) {
                putchar(' ');  // Output spaces
                column++;
            }
        } else {
            putchar(c);  // Output the character
            column++;
            if (c == '\n') {
                column = 0;  // Reset column position on new line
            }
        }
    }
}



