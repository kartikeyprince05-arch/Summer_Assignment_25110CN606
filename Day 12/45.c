#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int n) {
    if (n <= 0) {
        // Perfect numbers are positive integers only
        return 0;
    }

    int sum = 0;

    // Find divisors up to n/2
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum == n;  // Return 1 if perfect, else 0
}

int main() {
    int num;

    printf("Enter a positive integer: ");

    // Validate input
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (isPerfect(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;}