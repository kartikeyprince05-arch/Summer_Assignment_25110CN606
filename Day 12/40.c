#include<stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(const char *str) {
    if (str == NULL) {
        return 0; // Null input is not a palindrome
    }

    int left = 0;
    int right = strlen(str) - 1;

    // Compare characters from both ends
    while (left < right) {

        // Skip non‑alphanumeric characters
        while (left < right && !isalnum((unsigned char)str[left])) left++;
        while (left < right && !isalnum((unsigned char)str[right])) right--;

        // Case‑insensitive comparison
        if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])) {
            return 0; // Not a palindrome
        }

        left++;
        right--;
    }

    return 1; // It is a palindrome
}

int main() {
    char input[200];

    printf("Enter a string: ");

    // Safely read input
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if exists
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Handle empty input
    if (strlen(input) == 0) {
        printf("Empty string cannot be checked.\n");
        return 1;
    }

    // Check and display result
    if (isPalindrome(input)) {
        printf("\"%s\" is a palindrome.\n", input);
    } else {
        printf("\"%s\" is not a palindrome.\n", input);
    }

    return 0;
}


