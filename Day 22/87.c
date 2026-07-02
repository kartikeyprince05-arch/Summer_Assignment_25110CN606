#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000   // Maximum string length
#define ASCII_SIZE 256 // Total possible ASCII characters

int main() {
    char str[MAX_LEN];
    int freq[ASCII_SIZE] = {0}; // Frequency array initialized to 0

    printf("Enter a string: ");

    // Read input safely (including spaces)
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Count frequency of each character
    for (size_t i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];
        freq[ch]++;
    }

    // Display frequencies
    printf("\nCharacter frequencies:\n");
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (freq[i] > 0) {
            if (isprint(i)) {
                printf("'%c' : %d\n", i, freq[i]);
            } else {
                printf("'0x%02X' : %d\n", i, freq[i]); // Non-printable chars in hex
            }
        }
    }

    return 0;
}
