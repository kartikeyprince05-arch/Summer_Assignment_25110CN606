#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"

// Structure to store employee details
typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Delete Employee by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Add a new employee
void addEmployee() {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", emp.name); // read string with spaces
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);
    printf("Employee added successfully!\n");
}

// Display all employees
void displayEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    Employee emp;
    printf("\n%-10s %-20s %-10s\n", "ID", "Name", "Salary");
    printf("-------------------------------------------\n");
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        printf("%-10d %-20s %-10.2f\n", emp.id, emp.name, emp.salary);
    }
    fclose(fp);
}

// Search employee by ID
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id == id) {
            printf("Record Found:\n");
            printf("ID: %d\nName: %s\nSalary: %.2f\n", emp.id, emp.name, emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
    fclose(fp);
}

// Delete employee by ID
void deleteEmployee() {
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
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
        if (emp.id != id) {
            fwrite(&emp, sizeof(Employee), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Employee deleted successfully.\n");
    } else {
        printf("Employee with ID %d not found.\n", id);
    }
}
