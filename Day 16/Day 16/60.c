#include <stdio.h>
#include <stdlib.h>

// Structure for hash table node
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Hash table size (should be prime for better distribution)
#define TABLE_SIZE 101

// Hash function
int hash(int key) {
    if (key < 0) key = -key; // Handle negative numbers
    return key % TABLE_SIZE;
}

// Insert into hash table
void insert(Node *table[], int value) {
    int idx = hash(value);
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = table[idx];
    table[idx] = newNode;
}

// Search in hash table
int search(Node *table[], int value) {
    int idx = hash(value);
    Node *curr = table[idx];
    while (curr) {
        if (curr->value == value) return 1;
        curr = curr->next;
    }
    return 0;
}

// Free hash table memory
void freeTable(Node *table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = table[i];
        while (curr) {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int main() {
    int n, target;

    // Input array size
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int arr[n];

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    // Input target sum
    printf("Enter target sum: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid target.\n");
        return 1;
    }

    // Initialize hash table
    Node *hashTable[TABLE_SIZE] = {NULL};

    printf("Pairs with sum %d:\n", target);
    int found = 0;

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        if (search(hashTable, complement)) {
            printf("(%d, %d)\n", complement, arr[i]);
            found = 1;
        }
        insert(hashTable, arr[i]);
    }

    if (!found) {
        printf("No pairs found.\n");
    }

    // Free memory
    freeTable(hashTable);

    return 0;
}
