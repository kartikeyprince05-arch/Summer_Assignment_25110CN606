#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define DATA_FILE "library.dat"

// Book structure
typedef struct {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int available; // 1 = available, 0 = issued
} Book;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void deleteBook();
void saveBook(Book b);
void loadBooks();

// Global array to store books in memory
Book books[100];
int bookCount = 0;

// Save a single book to file
void saveBook(Book b) {
    FILE *fp = fopen(DATA_FILE, "ab");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);
}

// Load all books from file
void loadBooks() {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) return; // No file yet
    bookCount = 0;
    while (fread(&books[bookCount], sizeof(Book), 1, fp)) {
        bookCount++;
    }
    fclose(fp);
}

// Add a new book
void addBook() {
    Book b;
    printf("Enter Book ID: ");
    if (scanf("%d", &b.id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }
    getchar(); // consume newline

    printf("Enter Book Title: ");
    fgets(b.title, MAX_TITLE, stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; // remove newline

    printf("Enter Author Name: ");
    fgets(b.author, MAX_AUTHOR, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    b.available = 1;

    books[bookCount++] = b;
    saveBook(b);

    printf("Book added successfully!\n");
}

// Display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books in library.\n");
        return;
    }
    printf("\n%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Status");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-5d %-30s %-20s %-10s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].available ? "Available" : "Issued");
    }
}

// Search for a book
void searchBook() {
    char keyword[MAX_TITLE];
    getchar(); // clear newline
    printf("Enter Book Title or ID to search: ");
    fgets(keyword, MAX_TITLE, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        char idStr[20];
        sprintf(idStr, "%d", books[i].id);
        if (strstr(books[i].title, keyword) || strcmp(idStr, keyword) == 0) {
            printf("Found: ID=%d, Title=%s, Author=%s, Status=%s\n",
                   books[i].id, books[i].title, books[i].author,
                   books[i].available ? "Available" : "Issued");
            found = 1;
        }
    }
    if (!found) printf("No matching book found.\n");
}

// Delete a book by ID
void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    int found = 0;
    FILE *fp = fopen(DATA_FILE, "wb");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id != id) {
            fwrite(&books[i], sizeof(Book), 1, fp);
        } else {
            found = 1;
        }
    }
    fclose(fp);

    if (found) {
        printf("Book deleted successfully.\n");
        loadBooks(); // reload updated list
    } else {
        printf("Book ID not found.\n");
    }
}

// Main menu
int main() {
    loadBooks();
    int choice;
    while (1) {
        printf("\n=== Mini Library Management System ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
