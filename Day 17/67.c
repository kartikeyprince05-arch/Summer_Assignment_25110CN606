#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if an element exists in an array
bool existsInArray(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}

int main() {
    int n1, n2;

    // Input size of first array
    printf("Enter size of first array: ");
    if (scanf("%d", &n1) != 1 || n1 <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int arr1[n1];
    printf("Enter %d elements for first array: ", n1);
    for (int i = 0; i < n1; i++) {
        if (scanf("%d", &arr1[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Input size of second array
    printf("Enter size of second array: ");
    if (scanf("%d", &n2) != 1 || n2 <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int arr2[n2];
    printf("Enter %d elements for second array: ", n2);
    for (int i = 0; i < n2; i++) {
        if (scanf("%d", &arr2[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Array to store intersection
    int intersection[(n1 < n2) ? n1 : n2];
    int k = 0;

    // Find intersection without duplicates
    for (int i = 0; i < n1; i++) {
        if (existsInArray(arr2, n2, arr1[i]) && !existsInArray(intersection, k, arr1[i])) {
            intersection[k++] = arr1[i];
        }
    }

    // Display result
    if (k == 0) {
        printf("No common elements found.\n");
    } else {
        printf("Intersection of arrays: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");
    }

    return 0;
}
