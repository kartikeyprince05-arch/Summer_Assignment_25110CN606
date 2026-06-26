#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Input array size
    printf("Enter number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    int freq[n]; // Array to store frequency counts
    int visited = -1; // Marker for visited elements

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
        freq[i] = 0; // Initialize frequency array
    }

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        if (freq[i] == visited) {
            continue; // Skip already counted elements
        }
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = visited; // Mark as visited
            }
        }
        freq[i] = count;
    }

    // Display frequency of each unique element
    printf("\nFrequency of each element:\n");
    for (int i = 0; i < n; i++) {
        if (freq[i] != visited) {
            printf("%d occurs %d time(s)\n", arr[i], freq[i]);
        }
    }

    return 0;
}
