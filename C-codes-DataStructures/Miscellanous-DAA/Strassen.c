// ANGAD DOGRA - BATCH 1 AIML - H

#include <stdio.h>
// Function to print a matrix
void printMatrix(int mat[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
// Function to multiply two matrices using the standard method
void multiplyMatrix(int matA[4][4], int matB[4][4], int result[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}
// Function to add two matrices
void addMatrix(int matA[4][4], int matB[4][4], int result[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}
// Function to subtract two matrices
void subtractMatrix(int matA[4][4], int matB[4][4], int result[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = matA[i][j] - matB[i][j];
        }
    }
}
// Function to perform Strassen's matrix multiplication
void strassenMatrixMultiplication(int matA[4][4], int matB[4][4], int result[4][4]) {
    if (sizeof(matA) / sizeof(matA[0]) == 1) {
        result[0][0] = matA[0][0] * matB[0][0];
        return;
    }

    int n = sizeof(matA) / sizeof(matA[0]);
    int newSize = n / 2;

    int A11[4][4], A12[4][4], A21[4][4], A22[4][4];
    int B11[4][4], B12[4][4], B21[4][4], B22[4][4];
    int C11[4][4], C12[4][4], C21[4][4], C22[4][4];
    int P1[4][4], P2[4][4], P3[4][4], P4[4][4], P5[4][4], P6[4][4], P7[4][4];
    // Divide matrices A and B into 4 submatrices each
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = matA[i][j];
            A12[i][j] = matA[i][j + newSize];
            A21[i][j] = matA[i + newSize][j];
            A22[i][j] = matA[i + newSize][j + newSize];

            B11[i][j] = matB[i][j];
            B12[i][j] = matB[i][j + newSize];
            B21[i][j] = matB[i + newSize][j];
            B22[i][j] = matB[i + newSize][j + newSize];
        }
    }
    // Calculate 7 products recursively
    multiplyMatrix(A11, B11, P1);
    multiplyMatrix(A12, B21, P2);
    multiplyMatrix(A11, B12, P3);
    multiplyMatrix(A12, B22, P4);
    multiplyMatrix(A21, B11, P5);
    multiplyMatrix(A22, B21, P6);
    multiplyMatrix(A21, B12, P7);

    // Calculate submatrices of C
    addMatrix(P1, P2, C11);
    subtractMatrix(C11, P4, C11);
    addMatrix(C11, P7, C11);

    addMatrix(P3, P4, C12);

    addMatrix(P5, P6, C21);

    addMatrix(P1, P5, C22);
    subtractMatrix(C22, P2, C22);
    subtractMatrix(C22, P3, C22);

    // Combine submatrices into the result matrix
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            result[i][j] = C11[i][j];
            result[i][j + newSize] = C12[i][j];
            result[i + newSize][j] = C21[i][j];
            result[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int matA[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int matB[4][4] = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};
    int result[4][4];

    printf("Matrix A:\n");
    printMatrix(matA);
    printf("\nMatrix B:\n");
    printMatrix(matB);
    // Normal Matrix Multiplication
    multiplyMatrix(matA, matB, result);
    printf("\nResult of Normal Matrix Multiplication:\n");
    printMatrix(result);
    // Strassen's Matrix Multiplication
    strassenMatrixMultiplication(matA, matB, result);
    printf("\nResult of Strassen's Matrix Multiplication:\n");
    printMatrix(result);

    return 0;
}
