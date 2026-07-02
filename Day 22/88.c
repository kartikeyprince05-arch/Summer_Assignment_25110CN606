#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000  // Maximum string length

// Function to remove spaces from a string in-place
void removeSpaces(char *str) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i])) { // Keep only non-space characters
            str[j++] = str[i];
        }
    }
    str[j] = '\0'; // Null-terminate the modified string
}

int main() {
    char str[MAX_LEN];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character from fgets if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    removeSpaces(str);

    printf("String without spaces: \"%s\"\n", str);

    return 0;
}
