#include <stdio.h>
#include <stdlib.h>

// Structure to store element and its frequency
typedef struct {
    int value;
    int count;
} ElementFreq;

// Function to find the element with maximum frequency
int findMaxFrequencyElement(int arr[], int n) {
    if (n <= 0) {
        printf("Array is empty.\n");
        return 0;
    }

    ElementFreq freq[n];
    int freqSize = 0;

    // Count frequencies
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < freqSize; j++) {
            if (freq[j].value == arr[i]) {
                freq[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            freq[freqSize].value = arr[i];
            freq[freqSize].count = 1;
            freqSize++;
        }
    }

    // Find element with maximum frequency
    int maxCount = freq[0].count;
    int maxElement = freq[0].value;
    for (int i = 1; i < freqSize; i++) {
        if (freq[i].count > maxCount) {
            maxCount = freq[i].count;
            maxElement = freq[i].value;
        }
    }

    printf("Element with maximum frequency: %d (Frequency: %d)\n", maxElement, maxCount);
    return maxElement;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    findMaxFrequencyElement(arr, n);
    return 0;
}
