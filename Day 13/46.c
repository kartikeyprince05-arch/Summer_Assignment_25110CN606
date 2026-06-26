#include <stdio.h>

#define MAX_SIZE 100  // Maximum allowed array size

int main() {
    int arr[MAX_SIZE];
    int n, i;

    // Input array size
    printf("Enter number of elements (1-%d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        printf("Invalid size. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1; // Exit with error
    }

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1; // Exit with error
        }
    }

    // Display array elements
    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
