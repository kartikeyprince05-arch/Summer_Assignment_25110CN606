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
    if (scanf("%d", &n1) != 1 || n1 < 0) {
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
    if (scanf("%d", &n2) != 1 || n2 < 0) {
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

    // Union array (max possible size = n1 + n2)
    int unionArr[n1 + n2];
    int unionSize = 0;

    // Add elements from first array
    for (int i = 0; i < n1; i++) {
        if (!existsInArray(unionArr, unionSize, arr1[i])) {
            unionArr[unionSize++] = arr1[i];
        }
    }

    // Add elements from second array
    for (int i = 0; i < n2; i++) {
        if (!existsInArray(unionArr, unionSize, arr2[i])) {
            unionArr[unionSize++] = arr2[i];
        }
    }

    // Display union
    printf("Union of arrays: ");
    for (int i = 0; i < unionSize; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}
