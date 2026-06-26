#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;

    // Input array size
    printf("Enter number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
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

    bool foundDuplicate = false;

    printf("Duplicate elements: ");
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

        // Check if arr[i] appears again
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        // Ensure we haven't already printed this duplicate
        if (isDuplicate) {
            bool alreadyPrinted = false;
            for (int k = 0; k < i; k++) {
                if (arr[k] == arr[i]) {
                    alreadyPrinted = true;
                    break;
                }
            }
            if (!alreadyPrinted) {
                printf("%d ", arr[i]);
                foundDuplicate = true;
            }
        }
    }

    if (!foundDuplicate) {
        printf("None");
    }
    printf("\n");

    return 0;
}
