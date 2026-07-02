#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000  // Maximum sentence length

int main() {
    char sentence[MAX_LEN];
    char longestWord[MAX_LEN] = "";
    char currentWord[MAX_LEN] = "";
    int maxLen = 0, currLen = 0;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Traverse each character in the sentence
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isalpha((unsigned char)sentence[i])) {
            // Build current word
            currentWord[currLen++] = sentence[i];
        } else {
            // End of a word
            if (currLen > 0) {
                currentWord[currLen] = '\0'; // Null-terminate
                if (currLen > maxLen) {
                    maxLen = currLen;
                    strcpy(longestWord, currentWord);
                }
                currLen = 0; // Reset for next word
            }
        }
    }

    // Check last word if sentence doesn't end with space/punctuation
    if (currLen > 0) {
        currentWord[currLen] = '\0';
        if (currLen > maxLen) {
            maxLen = currLen;
            strcpy(longestWord, currentWord);
        }
    }

    if (maxLen > 0) {
        printf("Longest word: %s\n", longestWord);
        printf("Length: %d\n", maxLen);
    } else {
        printf("No valid word found in the input.\n");
    }

    return 0;
}

