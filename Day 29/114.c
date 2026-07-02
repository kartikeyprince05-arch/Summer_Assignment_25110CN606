#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum array size

// Function prototypes
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void searchElement(int arr[], int size);
void displayArray(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0; // Current number of elements
    int choice;

    while (1) {
        // Menu
        printf("\n===== Array Operations Menu =====\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search Element\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                insertElement(arr, &size);
                break;
            case 2:
                deleteElement(arr, &size);
                break;
            case 3:
                searchElement(arr, size);
                break;
            case 4:
                displayArray(arr, size);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to insert an element
void insertElement(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("Array is full! Cannot insert more elements.\n");
        return;
    }

    int element, position;
    printf("Enter element to insert: ");
    if (scanf("%d", &element) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter position (1 to %d): ", *size + 1);
    if (scanf("%d", &position) != 1 || position < 1 || position > *size + 1) {
        printf("Invalid position!\n");
        while (getchar() != '\n');
        return;
    }

    // Shift elements to the right
    for (int i = *size; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

// Function to delete an element
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty! Nothing to delete.\n");
        return;
    }

    int position;
    printf("Enter position to delete (1 to %d): ", *size);
    if (scanf("%d", &position) != 1 || position < 1 || position > *size) {
        printf("Invalid position!\n");
        while (getchar() != '\n');
        return;
    }

    // Shift elements to the left
    for (int i = position - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted successfully.\n");
}

// Function to search for an element
void searchElement(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty! Nothing to search.\n");
        return;
    }

    int element, found = 0;
    printf("Enter element to search: ");
    if (scanf("%d", &element) != 1) {
        printf("Invalid input! Please enter an integer.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element found at position %d.\n", i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Element not found in the array.\n");
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
