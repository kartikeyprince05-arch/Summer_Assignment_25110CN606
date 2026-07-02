#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if str2 is a rotation of str1
int isRotation(const char *str1, const char *str2) {
    // Check for NULL pointers
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // If lengths differ, they cannot be rotations
    if (len1 != len2) {
        return 0;
    }

    // If both are empty strings, they are rotations
    if (len1 == 0) {
        return 1;
    }

    // Allocate memory for concatenated string
    char *concat = (char *)malloc((len1 * 2 + 1) * sizeof(char));
    if (!concat) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Concatenate str1 with itself
    strcpy(concat, str1);
    strcat(concat, str1);

    // Check if str2 is a substring of concat
    int result = (strstr(concat, str2) != NULL);

    // Free allocated memory
    free(concat);

    return result;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    if (scanf("%99s", str1) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter second string: ");
    if (scanf("%99s", str2) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isRotation(str1, str2)) {
        printf("\"%s\" is a rotation of \"%s\".\n", str2, str1);
    } else {
        printf("\"%s\" is NOT a rotation of \"%s\".\n", str2, str1);
    }

    return 0;
}
