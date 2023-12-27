#include <stdio.h>

// Function to find the length of Longest Common Subsequence
int lcs_length(char X[], char Y[]) {
    int m = 0, n = 0;
    while (X[m] != '\0') {
        m++;
    }
    while (Y[n] != '\0') {
        n++;
    }

    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    return L[m][n];
}

int main() {
    char X[100], Y[100];

    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    int length = lcs_length(X, Y);

    printf("Length of Longest Common Subsequence: %d\n", length);

    return 0;
}
