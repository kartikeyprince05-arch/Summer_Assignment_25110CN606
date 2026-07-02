#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays into a single sorted array
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Merge elements until one array is exhausted
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from arr1
    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements from arr2
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;

    // Input size of first array
    printf("Enter size of first sorted array: ");
    if (scanf("%d", &size1) != 1 || size1 < 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int arr1[size1];
    printf("Enter %d sorted elements for first array: ", size1);
    for (int i = 0; i < size1; i++) {
        if (scanf("%d", &arr1[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Input size of second array
    printf("Enter size of second sorted array: ");
    if (scanf("%d", &size2) != 1 || size2 < 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int arr2[size2];
    printf("Enter %d sorted elements for second array: ", size2);
    for (int i = 0; i < size2; i++) {
        if (scanf("%d", &arr2[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Merged array
    int merged[size1 + size2];
    mergeSortedArrays(arr1, size1, arr2, size2, merged);

    // Output merged array
    printf("Merged sorted array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
