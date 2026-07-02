#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ASCII_SIZE 256  // Total possible ASCII characters

// Function to find the maximum occurring character
char getMaxOccurringChar(const char *str) {
    int freq[ASCII_SIZE] = {0}; // Frequency array
    int maxFreq = 0;
    char maxChar = '\0';

    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];
        freq[ch]++;
        if (freq[ch] > maxFreq) {
            maxFreq = freq[ch];
            maxChar = ch;
        }
    }

    return maxChar;
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Handle empty string case
    if (strlen(str) == 0) {
        printf("Empty string entered.\n");
        return 0;
    }

    char result = getMaxOccurringChar(str);
    printf("Maximum occurring character: '%c'\n", result);

    return 0;
}
