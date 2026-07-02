#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "contacts.dat"
#define NAME_LEN 50
#define PHONE_LEN 15
#define EMAIL_LEN 50

// Structure to store contact details
typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
    char email[EMAIL_LEN];
} Contact;

// Function prototypes
void addContact();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();
int isValidPhone(const char *phone);
int isValidEmail(const char *email);

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Add a new contact
void addContact() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Contact c;
    printf("Enter name: ");
    while (getchar() != '\n'); // clear buffer
    fgets(c.name, NAME_LEN, stdin);
    c.name[strcspn(c.name, "\n")] = '\0';

    do {
        printf("Enter phone number: ");
        fgets(c.phone, PHONE_LEN, stdin);
        c.phone[strcspn(c.phone, "\n")] = '\0';
        if (!isValidPhone(c.phone))
            printf("Invalid phone number. Try again.\n");
    } while (!isValidPhone(c.phone));

    do {
        printf("Enter email: ");
        fgets(c.email, EMAIL_LEN, stdin);
        c.email[strcspn(c.email, "\n")] = '\0';
        if (!isValidEmail(c.email))
            printf("Invalid email format. Try again.\n");
    } while (!isValidEmail(c.email));

    fwrite(&c, sizeof(Contact), 1, fp);
    fclose(fp);
    printf("Contact added successfully!\n");
}

// View all contacts
void viewContacts() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No contacts found.\n");
        return;
    }

    Contact c;
    int count = 0;
    printf("\n--- Contact List ---\n");
    while (fread(&c, sizeof(Contact), 1, fp)) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n-------------------\n",
               c.name, c.phone, c.email);
        count++;
    }
    if (count == 0) printf("No contacts available.\n");
    fclose(fp);
}

// Search contact by name
void searchContact() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No contacts found.\n");
        return;
    }

    char searchName[NAME_LEN];
    printf("Enter name to search: ");
    while (getchar() != '\n');
    fgets(searchName, NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    Contact c;
    int found = 0;
    while (fread(&c, sizeof(Contact), 1, fp)) {
        if (strcasecmp(c.name, searchName) == 0) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n", c.name, c.phone, c.email);
            found = 1;
            break;
        }
    }
    if (!found) printf("Contact not found.\n");
    fclose(fp);
}

// Edit contact
void editContact() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No contacts found.\n");
        return;
    }

    char searchName[NAME_LEN];
    printf("Enter name to edit: ");
    while (getchar() != '\n');
    fgets(searchName, NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    Contact c;
    int found = 0;
    long pos;
    while ((pos = ftell(fp)), fread(&c, sizeof(Contact), 1, fp)) {
        if (strcasecmp(c.name, searchName) == 0) {
            printf("Editing contact: %s\n", c.name);

            printf("Enter new name: ");
            fgets(c.name, NAME_LEN, stdin);
            c.name[strcspn(c.name, "\n")] = '\0';

            do {
                printf("Enter new phone: ");
                fgets(c.phone, PHONE_LEN, stdin);
                c.phone[strcspn(c.phone, "\n")] = '\0';
            } while (!isValidPhone(c.phone));

            do {
                printf("Enter new email: ");
                fgets(c.email, EMAIL_LEN, stdin);
                c.email[strcspn(c.email, "\n")] = '\0';
            } while (!isValidEmail(c.email));

            fseek(fp, pos, SEEK_SET);
            fwrite(&c, sizeof(Contact), 1, fp);
            printf("Contact updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Contact not found.\n");
    fclose(fp);
}

// Delete contact
void deleteContact() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No contacts found.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        perror("Error creating temp file");
        fclose(fp);
        return;
    }

    char searchName[NAME_LEN];
    printf("Enter name to delete: ");
    while (getchar() != '\n');
    fgets(searchName, NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    Contact c;
    int found = 0;
    while (fread(&c, sizeof(Contact), 1, fp)) {
        if (strcasecmp(c.name, searchName) != 0) {
            fwrite(&c, sizeof(Contact), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) printf("Contact deleted successfully!\n");
    else{ printf("Contact not found.\n"); }