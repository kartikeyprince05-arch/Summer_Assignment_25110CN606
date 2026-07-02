#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove duplicate characters from a string
void removeDuplicates(char *str) {
    int hash[256] = {0}; // ASCII character tracker
    int i, j = 0;
    char result[strlen(str) + 1]; // Temporary array for result

    for (i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];
        if (hash[ch] == 0) { // First occurrence
            hash[ch] = 1;
            result[j++] = str[i];
        }
    }
    result[j] = '\0'; // Null-terminate the result
    strcpy(str, result); // Copy back to original string
}

int main() {
    char str[256];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character from fgets
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    removeDuplicates(str);

    printf("String after removing duplicates: %s\n", str);

    return 0;
}
