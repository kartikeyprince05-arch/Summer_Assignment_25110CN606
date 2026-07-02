#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "students.dat"

// Structure to store student details
typedef struct {
    int id;
    char name[50];
    int age;
    char gender;
    char className[20];
} Student;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
int isValidName(const char *name);
int isValidGender(char gender);

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Validate name (only letters and spaces)
int isValidName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ')
            return 0;
    }
    return 1;
}

// Validate gender (M/F)
int isValidGender(char gender) {
    gender = toupper(gender);
    return (gender == 'M' || gender == 'F');
}

// Add a new student record
void addStudent() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Student s;
    printf("Enter Student ID: ");
    if (scanf("%d", &s.id) != 1) {
        printf("Invalid ID.\n");
        fclose(fp);
        while (getchar() != '\n');
        return;
    }

    while (getchar() != '\n'); // clear buffer

    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    if (!isValidName(s.name)) {
        printf("Invalid name. Only letters and spaces allowed.\n");
        fclose(fp);
        return;
    }

    printf("Enter Age: ");
    if (scanf("%d", &s.age) != 1 || s.age <= 0) {
        printf("Invalid age.\n");
        fclose(fp);
        while (getchar() != '\n');
        return;
    }

    printf("Enter Gender (M/F): ");
    scanf(" %c", &s.gender);
    if (!isValidGender(s.gender)) {
        printf("Invalid gender.\n");
        fclose(fp);
        return;
    }

    while (getchar() != '\n'); // clear buffer

    printf("Enter Class Name: ");
    fgets(s.className, sizeof(s.className), stdin);
    s.className[strcspn(s.className, "\n")] = '\0';

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student record added successfully.\n");
}

// Display all student records
void displayStudents() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    Student s;
    printf("\n%-5s %-20s %-5s %-7s %-10s\n", "ID", "Name", "Age", "Gender", "Class");
    printf("------------------------------------------------------\n");

    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("%-5d %-20s %-5d %-7c %-10s\n", s.id, s.name, s.age, toupper(s.gender), s.className);
    }
    fclose(fp);
}

// Search for a student by ID
void searchStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Student ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        fclose(fp);
        while (getchar() != '\n');
        return;
    }

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGender: %c\nClass: %s\n",
                   s.id, s.name, s.age, toupper(s.gender), s.className);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No student found with ID %d.\n", id);
    }
    fclose(fp);
}

// Delete a student by ID
void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) {
        perror("Error creating temp file");
        fclose(fp);
        return;
    }

    int id, found = 0;
    printf("Enter Student ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        fclose(fp);
        fclose(temp);
        while (getchar() != '\n');
        return;
    }

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            found = 1;
            continue; // skip writing this record
        }
        fwrite(&s, sizeof(Student), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Student record deleted successfully.\n");
    } else {
        printf("No student found with ID %d.\n", id);
    }
}
