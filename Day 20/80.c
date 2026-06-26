#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    // Input matrix dimensions
    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Invalid input. Rows and columns must be positive integers.\n");
        return 1;
    }

    int matrix[rows][cols];

    // Input matrix elements
    printf("Enter %d elements of the matrix:\n", rows * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    // Calculate and display column-wise sum
    printf("\nColumn-wise sum:\n");
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += matrix[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, colSum);
    }

    return 0;
}
