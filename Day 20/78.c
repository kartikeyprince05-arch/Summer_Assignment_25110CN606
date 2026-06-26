#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a matrix is symmetric
bool isSymmetric(int matrix[50][50], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false; // Found mismatch
            }
        }
    }
    return true;
}

int main() {
    int matrix[50][50];
    int n;

    printf("Enter the order of the square matrix (max 50): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 50) {
        printf("Invalid matrix size. Must be between 1 and 50.\n");
        return 1;
    }

    printf("Enter elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    // Check symmetry
    if (isSymmetric(matrix, n)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is NOT symmetric.\n");
    }

    return 0;
}
