#include <stdio.h>
#include <ctype.h>   // For tolower() and isalpha()
#include <string.h>  // For strlen()

int main() {
    char str[1000];
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Loop through each character in the string
    for (int i = 0; i < strlen(str); i++) {
        char ch = tolower((unsigned char)str[i]); // Convert to lowercase for easy comparison

        if (isalpha(ch)) { // Check if character is a letter
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
