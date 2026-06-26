#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    long long expected_sum = 0, actual_sum = 0;

    printf("Enter the value of n (total numbers including the missing one): ");
    if (scanf("%d", &n) != 1 || n <= 1) {
        printf("Invalid input. n must be an integer greater than 1.\n");
        return 1;
    }

    int *arr = (int *)malloc((n - 1) * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d unique integers from 1 to %d (one number missing):\n", n - 1, n);
    for (i = 0; i < n - 1; i++) {
        if (scanf("%d", &arr[i]) != 1 || arr[i] < 1 || arr[i] > n) {
            printf("Invalid input. Numbers must be between 1 and %d.\n", n);
            free(arr);
            return 1;
        }
        actual_sum += arr[i];
    }

    // Formula for sum of first n natural numbers
    expected_sum = (long long)n * (n + 1) / 2;

    printf("The missing number is: %lld\n", expected_sum - actual_sum);

    free(arr);
    return 0;
}
