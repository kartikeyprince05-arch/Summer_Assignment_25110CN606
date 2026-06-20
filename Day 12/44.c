#include <stdio.h>
#include <stdlib.h>

// Function to print Fibonacci series up to n terms
void printFibonacci(int n) {
    // Handle edge cases
    if (n <= 0) {
        printf("Number of terms must be positive.\n");
        return;
    }

    long long a = 0, b = 1;  // Using long long for safety on larger values

    printf("Fibonacci Series: ");

    if (n >= 1) printf("%lld ", a);
    if (n >= 2) printf("%lld ", b);

    // Generate remaining terms
    for (int i = 3; i <= n; i++) {
        long long c = a + b;
        printf("%lld ", c);
        a = b;
        b = c;
    }

    printf("\n");
}

int main() {
    int n;

    printf("Enter number of Fibonacci terms: ");

    // Robust input validation
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    printFibonacci(n);

    return 0;
}