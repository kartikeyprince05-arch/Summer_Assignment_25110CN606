#include <stdio.h>
#include <stdlib.h>

// Function to multiply two matrices
void multiplyMatrices(int rowsA, int colsA, int A[rowsA][colsA],
                      int rowsB, int colsB, int B[rowsB][colsB],
                      int result[rowsA][colsB]) {
    // Initialize result matrix to 0
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }

    // Perform multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Input dimensions for first matrix
    printf("Enter rows and columns for first matrix: ");
    if (scanf("%d %d", &rowsA, &colsA) != 2 || rowsA <= 0 || colsA <= 0) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    // Input dimensions for second matrix
    printf("Enter rows and columns for second matrix: ");
    if (scanf("%d %d", &rowsB, &colsB) != 2 || rowsB <= 0 || colsB <= 0) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    // Check if multiplication is possible
    if (colsA != rowsB) {
        printf("Matrix multiplication not possible. Columns of first matrix must equal rows of second matrix.\n");
        return 1;
    }

    int A[rowsA][colsA], B[rowsB][colsB], result[rowsA][colsB];

    // Input first matrix
    printf("Enter elements of first matrix (%d x %d):\n", rowsA, colsA);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            if (scanf("%d", &A[i][j]) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
        }
    }

    // Input second matrix
    printf("Enter elements of second matrix (%d x %d):\n", rowsB, colsB);
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            if (scanf("%d", &B[i][j]) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
        }
    }

    // Multiply matrices
    multiplyMatrices(rowsA, colsA, A, rowsB, colsB, B, result);

    // Display result
    printf("Resultant Matrix (%d x %d):\n", rowsA, colsB);
    printMatrix(rowsA, colsB, result);

    return 0;
}