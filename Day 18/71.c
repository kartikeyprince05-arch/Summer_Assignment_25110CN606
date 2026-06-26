#include <stdio.h>
#include <stdlib.h>

// Recursive Binary Search function
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // Element found

        if (arr[mid] > target)
            return binarySearchRecursive(arr, left, mid - 1, target);

        return binarySearchRecursive(arr, mid + 1, right, target);
    }
    return -1; // Element not found
}

// Iterative Binary Search function
int binarySearchIterative(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // Element found

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Element not found
}

int main() {
    int n, target, choice;

    printf("Enter number of elements in sorted array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d sorted integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
        if (i > 0 && arr[i] < arr[i - 1]) {
            printf("Error: Array must be sorted in ascending order.\n");
            return 1;
        }
    }

    printf("Enter element to search: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Choose search method:\n1. Iterative\n2. Recursive\nEnter choice: ");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice.\n");
        return 1;
    }

    int result;
    if (choice == 1)
        result = binarySearchIterative(arr, n, target);
    else
        result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element found at index %d (0-based indexing).\n", result);
    else
        printf("Element not found in the array.\n");

    return 0;
}
