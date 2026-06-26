#include <stdio.h>
#include <limits.h>

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Second largest element does not exist.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int first = INT_MIN, second = INT_MIN;

    for (i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        printf("Second largest element does not exist.\n");
    } else {
        printf("The second largest element is: %d\n", second);
    }

    return 0;
}
