#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "inventory.dat"
#define NAME_LEN 50

// Structure to store inventory item details
typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    float price;
} Item;

// Function prototypes
void addItem();
void displayItems();
void searchItem();
void updateItem();
void deleteItem();
int getNextID();

int main() {
    int choice;

    while (1) {
        printf("\n===== Inventory Management System =====\n");
        printf("1. Add Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: searchItem(); break;
            case 4: updateItem(); break;
            case 5: deleteItem(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to get the next available ID
int getNextID() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 1; // If file doesn't exist, start from ID 1

    Item temp;
    int maxID = 0;
    while (fread(&temp, sizeof(Item), 1, fp)) {
        if (temp.id > maxID) maxID = temp.id;
    }
    fclose(fp);
    return maxID + 1;
}

// Add a new item
void addItem() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    Item newItem;
    newItem.id = getNextID();

    printf("Enter item name: ");
    while (getchar() != '\n'); // clear buffer
    fgets(newItem.name, NAME_LEN, stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // remove newline

    printf("Enter quantity: ");
    if (scanf("%d", &newItem.quantity) != 1 || newItem.quantity < 0) {
        printf("Invalid quantity!\n");
        fclose(fp);
        return;
    }

    printf("Enter price: ");
    if (scanf("%f", &newItem.price) != 1 || newItem.price < 0) {
        printf("Invalid price!\n");
        fclose(fp);
        return;
    }

    fwrite(&newItem, sizeof(Item), 1, fp);
    fclose(fp);
    printf("Item added successfully with ID %d!\n", newItem.id);
}

// Display all items
void displayItems() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No inventory found.\n");
        return;
    }

    Item item;
    printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("--------------------------------------------------\n");
    while (fread(&item, sizeof(Item), 1, fp)) {
        printf("%-5d %-20s %-10d %-10.2f\n", item.id, item.name, item.quantity, item.price);
    }
    fclose(fp);
}

// Search item by ID
void searchItem() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No inventory found.\n");
        return;
    }

    int id;
    printf("Enter item ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        fclose(fp);
        return;
    }

    Item item;
    int found = 0;
    while (fread(&item, sizeof(Item), 1, fp)) {
        if (item.id == id) {
            printf("Item found: ID=%d, Name=%s, Quantity=%d, Price=%.2f\n",
                   item.id, item.name, item.quantity, item.price);
            found = 1;
            break;
        }
    }
    if (!found) printf("Item with ID %d not found.\n", id);
    fclose(fp);
}

// Update item details
void updateItem() {
    FILE *fp = fopen(FILE_NAME, "rb+");
    if (!fp) {
        printf("No inventory found.\n");
        return;
    }

    int id;
    printf("Enter item ID to update: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        fclose(fp);
        return;
    }

    Item item;
    int found = 0;
    while (fread(&item, sizeof(Item), 1, fp)) {
        if (item.id == id) {
            found = 1;
            printf("Enter new name: ");
            while (getchar() != '\n');
            fgets(item.name, NAME_LEN, stdin);
            item.name[strcspn(item.name, "\n")] = '\0';

            printf("Enter new quantity: ");
            if (scanf("%d", &item.quantity) != 1 || item.quantity < 0) {
                printf("Invalid quantity!\n");
                fclose(fp);
                return;
            }

            printf("Enter new price: ");
            if (scanf("%f", &item.price) != 1 || item.price < 0) {
                printf("Invalid price!\n");
                fclose(fp);
                return;
            }

            fseek(fp, -sizeof(Item), SEEK_CUR);
            fwrite(&item, sizeof(Item), 1, fp);
            printf("Item updated successfully!\n");
            break;
        }
    }
    if (!found) printf("Item with ID %d not found.\n", id);
    fclose(fp);
}

// Delete an item
void deleteItem() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No inventory found.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        printf("Error creating temp file!\n");
        fclose(fp);
        return;
    }

    int id;
    printf("Enter item ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        fclose(fp);
        fclose(temp);
        return;
    }

    Item item;
    int found = 0;
    while (fread(&item, sizeof(Item), 1, fp)) {
        if (item.id == id) {
            found = 1;
            continue; // skip writing this item
        }
        fwrite(&item, sizeof(Item), 1, temp);
    }
    if (!found) printf("Item with ID %d not found.\n", id);

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);
}