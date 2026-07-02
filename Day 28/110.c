#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "bank_accounts.dat"

// Structure to store account details
typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} Account;

// Function prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void displayAccount();
Account* findAccount(int accNo, FILE *fp);
void saveAccount(Account acc, FILE *fp);

int main() {
    int choice;

    while (1) {
        printf("\n===== BANK ACCOUNT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: displayAccount(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Create a new account
void createAccount() {
    FILE *fp = fopen(FILENAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Account acc;
    printf("Enter account number: ");
    scanf("%d", &acc.accountNumber);
    printf("Enter name: ");
    getchar(); // clear newline
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0'; // remove newline
    printf("Enter initial deposit: ");
    scanf("%lf", &acc.balance);

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);
    printf("Account created successfully!\n");
}

// Deposit money into an account
void depositMoney() {
    int accNo;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);

    FILE *fp = fopen(FILENAME, "rb+");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Account *acc = findAccount(accNo, fp);
    if (!acc) {
        printf("Account not found.\n");
        fclose(fp);
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Invalid amount.\n");
        free(acc);
        fclose(fp);
        return;
    }

    acc->balance += amount;
    saveAccount(*acc, fp);
    printf("Deposit successful! New balance: %.2f\n", acc->balance);

    free(acc);
    fclose(fp);
}

// Withdraw money from an account
void withdrawMoney() {
    int accNo;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);

    FILE *fp = fopen(FILENAME, "rb+");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Account *acc = findAccount(accNo, fp);
    if (!acc) {
        printf("Account not found.\n");
        fclose(fp);
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    if (amount <= 0 || amount > acc->balance) {
        printf("Invalid amount or insufficient balance.\n");
        free(acc);
        fclose(fp);
        return;
    }

    acc->balance -= amount;
    saveAccount(*acc, fp);
    printf("Withdrawal successful! New balance: %.2f\n", acc->balance);

    free(acc);
    fclose(fp);
}

// Display account details
void displayAccount() {
    int accNo;
    printf("Enter account number: ");
    scanf("%d", &accNo);

    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Account acc;
    int found = 0;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.accountNumber == accNo) {
            printf("\nAccount Number: %d\n", acc.accountNumber);
            printf("Name: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }

    fclose(fp);
}

// Find account in file and return a copy
Account* findAccount(int accNo, FILE *fp) {
    rewind(fp);
    Account acc;
    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.accountNumber == accNo) {
            Account *found = malloc(sizeof(Account));
            if (!found) {
                printf("Memory allocation failed.\n");
                return NULL;
            }
            *found = acc;
            return found;
        }
    }
    return NULL;
}

// Save updated account back to file
void saveAccount(Account acc, FILE *fp) {
    rewind(fp);
    Account temp;
    while (fread(&temp, sizeof(Account), 1, fp)) {
        if (temp.accountNumber == acc.accountNumber) {
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, fp);
            fflush(fp);
            return;
        }
    }
}
