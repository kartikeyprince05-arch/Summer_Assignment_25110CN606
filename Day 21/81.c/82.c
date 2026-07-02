#include <stdio.h>
#include <string.h>

// Function to reverse a string in place
void reverseString(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    // Swap characters from both ends moving towards the center
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[1000]; // Buffer for input string

    printf("Enter a string: ");
    // Read a line of input safely
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
