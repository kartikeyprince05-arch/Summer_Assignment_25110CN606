#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN   100

// Structure to hold a word and its original position
typedef struct {
    char word[MAX_LEN];
    int original_index;
} WordEntry;

// Comparator for qsort: sort by length, then by original index for stability
int compare_words(const void *a, const void *b) {
    const WordEntry *wa = (const WordEntry *)a;
    const WordEntry *wb = (const WordEntry *)b;

    size_t len_a = strlen(wa->word);
    size_t len_b = strlen(wb->word);

    if (len_a != len_b)
        return (len_a > len_b) - (len_a < len_b); // shorter first
    else
        return (wa->original_index > wb->original_index) - (wa->original_index < wb->original_index);
}

int main() {
    WordEntry words[MAX_WORDS];
    int n = 0;

    printf("Enter number of words (max %d): ", MAX_WORDS);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_WORDS) {
        printf("Invalid number of words.\n");
        return 1;
    }

    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%99s", words[i].word) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        words[i].original_index = i; // store original position
    }

    // Sort words by length (stable)
    qsort(words, n, sizeof(WordEntry), compare_words);

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i].word);
    }

    return 0;
}
