#include <stdio.h>
#include <stdlib.h>

// Function to left rotate the array by one position
void leftRotateByOne(int arr[], int n) {
    int first = arr[0];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = first;
}

// Function to left rotate the array by d positions
void leftRotate(int arr[], int n, int d) {
    if (n <= 0) return; // No rotation for empty array
    d = d % n;          // Handle rotations greater than array size
    if (d < 0) {        // Handle negative rotations (convert to equivalent positive)
        d = (d + n) % n;
    }
    for (int i = 0; i < d; i++) {
        leftRotateByOne(arr, n);
    }
}

int main() {
    int n, d;

    // Input array size
    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Must be a positive integer.\n");
        return 1;
    }

    int arr[n];

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    // Input number of rotations
    printf("Enter number of positions to rotate left: ");
    if (scanf("%d", &d) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // Perform rotation
    leftRotate(arr, n, d);

    // Output rotated array
    printf("Array after left rotation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
