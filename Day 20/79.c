#include <stdio.h>

int main() {
    int rows, cols;

    // Input matrix dimensions
    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Invalid input. Rows and columns must be positive integers.\n");
        return 1;
    }

    int matrix[100][100]; // Limit to avoid overflow
    if (rows > 100 || cols > 100) {
        printf("Matrix size too large. Max 100x100 allowed.\n");
        return 1;
    }

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

    // Calculate and display row-wise sum
    printf("\nRow-wise sums:\n");
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, sum);
    }

    return 0;
}