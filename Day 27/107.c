#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LEN 50

// Structure to store employee details
typedef struct {
    int id;
    char name[NAME_LEN];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int empCount = 0;

// Function to add a new employee
void addEmployee() {
    if (empCount >= MAX_EMPLOYEES) {
        printf("Error: Employee limit reached.\n");
        return;
    }

    Employee e;
    printf("Enter Employee ID: ");
    if (scanf("%d", &e.id) != 1) {
        printf("Invalid input. ID must be an integer.\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }

    // Check for duplicate ID
    for (int i = 0; i < empCount; i++) {
        if (employees[i].id == e.id) {
            printf("Error: Employee ID already exists.\n");
            return;
        }
    }

    printf("Enter Employee Name: ");
    while (getchar() != '\n'); // clear buffer
    fgets(e.name, NAME_LEN, stdin);
    e.name[strcspn(e.name, "\n")] = '\0'; // remove newline

    printf("Enter Salary: ");
    if (scanf("%f", &e.salary) != 1 || e.salary < 0) {
        printf("Invalid salary. Must be a positive number.\n");
        while (getchar() != '\n');
        return;
    }

    employees[empCount++] = e;
    printf("Employee added successfully.\n");
}

// Function to display all employees
void displayEmployees() {
    if (empCount == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("\n%-5s %-20s %-10s\n", "ID", "Name", "Salary");
    printf("----------------------------------------\n");
    for (int i = 0; i < empCount; i++) {
        printf("%-5d %-20s %-10.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

// Function to update salary by ID
void updateSalary() {
    if (empCount == 0) {
        printf("No employees available.\n");
        return;
    }

    int id;
    printf("Enter Employee ID to update salary: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < empCount; i++) {
        if (employees[i].id == id) {
            float newSalary;
            printf("Enter new salary: ");
            if (scanf("%f", &newSalary) != 1 || newSalary < 0) {
                printf("Invalid salary.\n");
                while (getchar() != '\n');
                return;
            }
            employees[i].salary = newSalary;
            printf("Salary updated successfully.\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

// Function to calculate total payroll
void totalPayroll() {
    if (empCount == 0) {
        printf("No employees available.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < empCount; i++) {
        total += employees[i].salary;
    }
    printf("Total Payroll: %.2f\n", total);
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Salary Management System ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Update Salary\n");
        printf("4. Total Payroll\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: updateSalary(); break;
            case 4: totalPayroll(); break;
            case 5: printf("Exiting program.\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
