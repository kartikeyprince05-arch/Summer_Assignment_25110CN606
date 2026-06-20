#include <stdio.h>
#include <math.h>

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    if (num < 0) {
        return 0; // Negative numbers cannot be Armstrong numbers
    }

    int original = num;
    int digits = 0;
    int sum = 0;

    // Count digits
    int temp = num;
    while (temp > 0) {
        temp /= 10;
        digits++;
    }

    // Calculate sum of digits^digits
    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += (int)pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

int main() {
    int number;

    printf("Enter an integer: ");

    // Input validation
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer only.\n");
        return 1;
    }

    // Check Armstrong
    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}