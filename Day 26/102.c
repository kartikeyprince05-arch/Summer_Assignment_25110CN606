#include <stdio.h>
#include <stdlib.h>

// Function to check voting eligibility
void checkVotingEligibility(int age) {
    if (age >= 18) {
        printf("✅ You are eligible to vote.\n");
    } else {
        printf("❌ You are NOT eligible to vote. You need to wait %d more year(s).\n", 18 - age);
    }
}

int main() {
    int age;
    char ch;

    printf("=== Voting Eligibility System ===\n");

    // Input loop to ensure valid age
    while (1) {
        printf("Enter your age: ");
        if (scanf("%d", &age) != 1) {
            // Clear invalid input
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Invalid input. Please enter a valid integer.\n");
            continue;
        }

        if (age < 0 || age > 150) {
            printf("Invalid age. Please enter an age between 0 and 150.\n");
            continue;
        }

        // Valid age entered, break loop
        break;
    }

    // Check eligibility
    checkVotingEligibility(age);

    return 0;
}
