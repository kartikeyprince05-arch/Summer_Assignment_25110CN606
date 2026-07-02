#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store employee details
typedef struct {
    int id;
    char name[50];
    char department[30];
    float salary;
} Employee;

const char *FILENAME = "employees.dat";

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();

int main() {
    int choice;

    while (1) {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
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
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Add a new employee
void addEmployee() {
    FILE *fp = fopen(FILENAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", emp.name);
    printf("Enter Department: ");
    scanf(" %[^\n]", emp.department);
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, fp);
    fclose(fp);
    printf("Employee added successfully!\n");
}

// Display all employees
void displayEmployees() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    Employee emp;
    printf("\n%-5s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("------------------------------------------------------\n");
    while (fread(&emp, sizeof(Employee), 1, fp)) {
        printf("%-5d %-20s %-15s %-10.2f\n", emp.id, emp.name, emp.department, emp.salary);
    }
    fclose(fp);
}

// Search employee by ID
void searchEmployee() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    Employee emp;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            printf("Record Found:\n");
            printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\n",
                   emp.id, emp.name, emp.department, emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) printf("Employee with ID %d not found.\n", id);
    fclose(fp);
}

// Update employee details
void updateEmployee() {
    FILE *fp = fopen(FILENAME, "rb+");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    Employee emp;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", emp.name);
            printf("Enter new Department: ");
            scanf(" %[^\n]", emp.department);
            printf("Enter new Salary: ");
            scanf("%f", &emp.salary);

            fseek(fp, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, fp);
            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Employee with ID %d not found.\n", id);
    fclose(fp);
}

// Delete employee record
void deleteEmployee() {
    FILE *fp = fopen(FILENAME, "rb");
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
    Employee emp;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(Employee), 1, fp)) {
        if (emp.id == id) {
            found = 1;
            continue; // skip writing this record
        }
        fwrite(&emp, sizeof(Employee), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.dat", FILENAME);

    if (found) printf("Record deleted successfully!\n");
    else printf("Employee with ID %d not found.\n", id);
}
