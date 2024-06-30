#include <stdio.h> 
#define SIZE 10

int main () {

    int n , array[SIZE], getInt (int *) ;

    for (n = 0 ; n < SIZE && getInt(&array[n]) != EOF ; n++)
        ;
}