#include <stdio.h>
#include <stdlib.h>

// Function to merge two arrays
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    // Copy elements of first array
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    // Copy elements of second array
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }
}

int main() {
    int size1, size2;

    // Input size of first array
    printf("Enter size of first array: ");
    if (scanf("%d", &size1) != 1 || size1 < 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // Input size of second array
    printf("Enter size of second array: ");
    if (scanf("%d", &size2) != 1 || size2 < 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // Allocate memory for arrays
    int arr1[size1], arr2[size2], merged[size1 + size2];

    // Input elements of first array
    printf("Enter %d elements for first array:\n", size1);
    for (int i = 0; i < size1; i++) {
        if (scanf("%d", &arr1[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Input elements of second array
    printf("Enter %d elements for second array:\n", size2);
    for (int i = 0; i < size2; i++) {
        if (scanf("%d", &arr2[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Merge arrays
    mergeArrays(arr1, size1, arr2, size2, merged);

    // Display merged array
    printf("Merged array:\n");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
