#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to compress the string
void compressString(const char *input, char *output, size_t outSize) {
    if (!input || !output || outSize == 0) {
        fprintf(stderr, "Invalid parameters.\n");
        return;
    }

    size_t len = strlen(input);
    if (len == 0) {
        output[0] = '\0';
        return;
    }

    size_t outIndex = 0;
    for (size_t i = 0; i < len; ) {
        char currentChar = input[i];
        size_t count = 1;

        // Count consecutive occurrences
        while (i + count < len && input[i + count] == currentChar) {
            count++;
        }

        // Append character
        if (outIndex < outSize - 1) {
            output[outIndex++] = currentChar;
        } else {
            fprintf(stderr, "Output buffer too small.\n");
            output[0] = '\0';
            return;
        }

        // Append count if more than 1
        if (count > 1) {
            char countStr[20];
            snprintf(countStr, sizeof(countStr), "%zu", count);
            size_t countLen = strlen(countStr);

            if (outIndex + countLen < outSize) {
                memcpy(&output[outIndex], countStr, countLen);
                outIndex += countLen;
            } else {
                fprintf(stderr, "Output buffer too small.\n");
                output[0] = '\0';
                return;
            }
        }

        i += count; // Move to next different character
    }

    output[outIndex] = '\0'; // Null-terminate
}

int main() {
    char input[256];
    char output[512]; // Ensure enough space for compressed string

    printf("Enter a string to compress: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    compressString(input, output, sizeof(output));

    printf("Compressed string: %s\n", output);

    return 0;
}
