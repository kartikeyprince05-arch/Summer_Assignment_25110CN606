#include <stdio.h>
#include <stdlib.h>

// Function to safely read an integer
int readInt(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n'); // clear input buffer
    }
    return value;
}

int main() {
    int rows, cols;

    // Read matrix dimensions
    rows = readInt("Enter number of rows (1-50): ");
    cols = readInt("Enter number of columns (1-50): ");

    // Validate dimensions
    if (rows <= 0 || cols <= 0 || rows > 50 || cols > 50) {
        printf("Error: Rows and columns must be between 1 and 50.\n");
        return 1;
    }

    int mat1[50][50], mat2[50][50], sum[50][50];

    // Input first matrix
    printf("\nEnter elements of first matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat1[i][j] = readInt("");
        }
    }

    // Input second matrix
    printf("\nEnter elements of second matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat2[i][j] = readInt("");
        }
    }

    // Calculate sum of matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    // Display result
    printf("\nSum of the two matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
