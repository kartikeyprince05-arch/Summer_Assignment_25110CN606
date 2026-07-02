#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRINGS 50
#define MAX_LEN 100

// Function to find common characters in all strings
void findCommonChars(char strings[][MAX_LEN], int n) {
    int freq[256]; // Frequency array for ASCII characters
    int i, j;

    // Initialize frequency with 1 for all characters
    for (i = 0; i < 256; i++) {
        freq[i] = 1;
    }

    // Process each string
    for (i = 0; i < n; i++) {
        int temp[256] = {0}; // Temporary array for current string

        for (j = 0; strings[i][j] != '\0'; j++) {
            unsigned char ch = (unsigned char)tolower(strings[i][j]); // Case-insensitive
            temp[ch] = 1; // Mark presence in current string
        }

        // Update main frequency array
        for (j = 0; j < 256; j++) {
            freq[j] &= temp[j]; // Keep only characters present in all strings so far
        }
    }

    // Print common characters
    printf("Common characters: ");
    int found = 0;
    for (i = 0; i < 256; i++) {
        if (freq[i]) {
            printf("%c ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int n, i;
    char strings[MAX_STRINGS][MAX_LEN];

    printf("Enter number of strings: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_STRINGS) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    getchar(); // Clear newline from buffer

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        if (!fgets(strings[i], sizeof(strings[i]), stdin)) {
            printf("Error reading string.\n");
            return 1;
        }
        strings[i][strcspn(strings[i], "\n")] = '\0'; // Remove newline
    }

    findCommonChars(strings, n);

    return 0;
}
