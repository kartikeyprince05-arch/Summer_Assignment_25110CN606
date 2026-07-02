#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 100

// Structure to store book details
typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int available; // 1 = available, 0 = issued
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void deleteBook();
int findBookIndexById(int id);

int main() {
    int choice;

    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Delete Book by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: printf("Exiting program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Add a new book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book newBook;
    printf("Enter Book ID: ");
    if (scanf("%d", &newBook.id) != 1) {
        printf("Invalid input! ID must be a number.\n");
        while (getchar() != '\n');
        return;
    }

    // Check for duplicate ID
    if (findBookIndexById(newBook.id) != -1) {
        printf("Book with ID %d already exists!\n", newBook.id);
        return;
    }

    while (getchar() != '\n'); // clear buffer
    printf("Enter Book Title: ");
    fgets(newBook.title, TITLE_LEN, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // remove newline

    printf("Enter Author Name: ");
    fgets(newBook.author, AUTHOR_LEN, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    newBook.available = 1; // default available
    library[bookCount++] = newBook;

    printf("Book added successfully!\n");
}

// Display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n%-5s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Status");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-5d %-30s %-20s %-10s\n",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].available ? "Available" : "Issued");
    }
}

// Search for a book by ID
void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input! ID must be a number.\n");
        while (getchar() != '\n');
        return;
    }

    int index = findBookIndexById(id);
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }

    printf("Book Found:\n");
    printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
           library[index].id,
           library[index].title,
           library[index].author,
           library[index].available ? "Available" : "Issued");
}

// Delete a book by ID
void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input! ID must be a number.\n");
        while (getchar() != '\n');
        return;
    }

    int index = findBookIndexById(id);
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }

    // Shift books left
    for (int i = index; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
    }
    bookCount--;

    printf("Book deleted successfully!\n");
}

// Find book index by ID
int findBookIndexById(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            return i;
        }
    }
    return -1;
}
