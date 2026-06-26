#include <stdio.h>

int main() {
    int n, i;
    double sum = 0.0, average = 0.0;

    // Ask for number of elements
    printf("Enter number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1; // Exit with error
    }

    double arr[n]; // Variable Length Array (C99 feature)

    // Input array elements
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%lf", &arr[i]) != 1) {
            printf("Invalid input. Please enter numeric values only.\n");
            return 1;
        }
        sum += arr[i]; // Add to sum
    }

    // Calculate average
    average = sum / n;

    // Display results
    printf("\nSum of array elements = %.2lf\n", sum);
    printf("Average of array elements = %.2lf\n", average);

    return 0;
}
