#include <stdio.h>
#include <stdlib.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b, int *errorFlag);

int main() {
    int choice;
    double num1, num2, result;
    int errorFlag;

    while (1) {
        // Display menu
        printf("\n===== Simple Calculator =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

        // Validate menu choice input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice == 5) {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please select between 1 and 5.\n");
            continue;
        }

        // Get numbers from user
        printf("Enter first number: ");
        if (scanf("%lf", &num1) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter second number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        // Perform operation based on choice
        errorFlag = 0;
        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                result = divide(num1, num2, &errorFlag);
                if (!errorFlag)
                    printf("Result: %.2lf\n", result);
                break;
        }
    }

    return 0;
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b, int *errorFlag) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        *errorFlag = 1;
        return 0;
    }
    return a / b;
}
