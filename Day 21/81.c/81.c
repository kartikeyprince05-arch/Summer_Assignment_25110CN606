#include <stdio.h>

// Function to calculate string length without using strlen()
int stringLength(const char *str) {
    int length = 0;

    // Null pointer check
    if (str == NULL) {
        return -1; // Indicate invalid input
    }

    // Count characters until null terminator '\0'
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    char str[1000]; // Buffer for input string

    printf("Enter a string: ");

    // Read input safely (including spaces)
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    int length = stringLength(str);

    if (length == -1) {
        printf("Invalid string.\n");
    } else {
        printf("Length of the string: %d\n", length);
    }

    return 0;
}
