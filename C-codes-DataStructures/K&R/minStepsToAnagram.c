#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_COUNT 26

void countFrequency(const char *str, int *freq)
{
    while (*str) {
        freq[*str - 'a']++ ;
        str++ ;
    }
}

/* calculating the minimum number of steps to make two strings anagram */
int minStepsToAnagram(const char *str1, const char *str2) 
{
    


}