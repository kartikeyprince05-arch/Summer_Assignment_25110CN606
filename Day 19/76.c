#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Input size of square matrix
    printf("Enter the size of the square matrix (n x n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int matrix[n][n];
    int primarySum = 0, secondarySum = 0;

    // Input matrix elements
    printf("Enter %d elements of the matrix:\n", n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    // Calculate sums of diagonals
    for (int i = 0; i < n; i++) {
        primarySum += matrix[i][i];           // Primary diagonal
        secondarySum += matrix[i][n - i - 1]; // Secondary diagonal
    }

    // If n is odd, subtract the middle element once (it was counted twice)
    int totalDiagonalSum = primarySum + secondarySum;
    if (n % 2 == 1) {
        totalDiagonalSum -= matrix[n / 2][n / 2];
    }

    // Output results
    printf("Primary diagonal sum: %d\n", primarySum);
    printf("Secondary diagonal sum: %d\n", secondarySum);
    printf("Total diagonal sum (without double counting middle element): %d\n", totalDiagonalSum);

    return 0;
}
