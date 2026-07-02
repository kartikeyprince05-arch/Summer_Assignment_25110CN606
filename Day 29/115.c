#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove newline character from fgets input
void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Function to reverse a string
void reverseString(char *str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// Function to convert string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    char str1[100], str2[100], temp[100];
    int choice;

    printf("Enter first string: ");
    if (!fgets(str1, sizeof(str1), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }
    removeNewline(str1);

    printf("Enter second string: ");
    if (!fgets(str2, sizeof(str2), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }
    removeNewline(str2);

    do {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf("1. Length of strings\n");
        printf("2. Compare strings\n");
        printf("3. Concatenate strings\n");
        printf("4. Reverse first string\n");
        printf("5. Convert first string to uppercase\n");
        printf("6. Convert first string to lowercase\n");
        printf("7. Copy first string to second\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }
        while (getchar() != '\n'); // clear buffer after number input

        switch (choice) {
            case 1:
                printf("Length of first string: %zu\n", strlen(str1));
                printf("Length of second string: %zu\n", strlen(str2));
                break;

            case 2:
                if (strcmp(str1, str2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal.\n");
                break;

            case 3:
                strcpy(temp, str1);
                strcat(temp, str2);
                printf("Concatenated string: %s\n", temp);
                break;

            case 4:
                strcpy(temp, str1);
                reverseString(temp);
                printf("Reversed first string: %s\n", temp);
                break;

            case 5:
                strcpy(temp, str1);
                toUpperCase(temp);
                printf("Uppercase: %s\n", temp);
                break;

            case 6:
                strcpy(temp, str1);
                toLowerCase(temp);
                printf("Lowercase: %s\n", temp);
                break;

            case 7:
                strcpy(str2, str1);
                printf("First string copied to second. Second string: %s\n", str2);
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
