#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear input buffer in case of invalid input
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int secretNumber, guess, attempts = 0, maxAttempts = 10;

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Generate a random number between 1 and 100
    secretNumber = (rand() % 100) + 1;

    printf("=== Number Guessing Game ===\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n\n", maxAttempts);

    while (attempts < maxAttempts) {
        printf("Attempt %d: Enter your guess: ", attempts + 1);

        // Validate input
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            clearInputBuffer();
            continue;
        }

        attempts++;

        if (guess == secretNumber) {
            printf("🎉 Congratulations! You guessed the number in %d attempts.\n", attempts);
            return 0;
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }

    printf("\n❌ Sorry! You've used all %d attempts. The number was %d.\n", maxAttempts, secretNumber);
    return 0;
}
