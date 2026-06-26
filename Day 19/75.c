#include <stdio.h>
#include <stdlib.h>

#define MAX 50 // Maximum allowed rows/columns

// Function to read a matrix from user
void readMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                exit(1);
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find transpose of a matrix
void transposeMatrix(int rows, int cols, int matrix[MAX][MAX], int transpose[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX], transpose[MAX][MAX];

    // Input matrix dimensions
    printf("Enter number of rows and columns (max %d): ", MAX);
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0 || rows > MAX || cols > MAX) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    // Read matrix
    readMatrix(rows, cols, matrix);

    // Display original matrix
    printf("\nOriginal Matrix:\n");
    printMatrix(rows, cols, matrix);

    // Compute transpose
    transposeMatrix(rows, cols, matrix, transpose);

    // Display transpose
    printf("\nTranspose of the Matrix:\n");
    printMatrix(cols, rows, transpose);

    return 0;
}
