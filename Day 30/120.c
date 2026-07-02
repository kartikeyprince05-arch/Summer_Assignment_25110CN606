#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

// Structure to store student details
typedef struct {
    int rollNo;
    char name[NAME_LEN];
    float marks;
} Student;

// Function prototypes
void addStudent(Student students[], int *count);
void displayStudents(const Student students[], int count);
void searchStudent(const Student students[], int count);
void sortStudents(Student students[], int count);
void clearInputBuffer();

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Sort Students by Marks (Descending)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                sortStudents(students, count);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to clear leftover input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add a student
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached.\n");
        return;
    }

    Student s;
    printf("Enter Roll No: ");
    if (scanf("%d", &s.rollNo) != 1) {
        printf("Invalid roll number!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer(); // clear newline

    printf("Enter Name: ");
    fgets(s.name, NAME_LEN, stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    printf("Enter Marks: ");
    if (scanf("%f", &s.marks) != 1) {
        printf("Invalid marks!\n");
        clearInputBuffer();
        return;
    }

    students[*count] = s;
    (*count)++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(const Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }
}

// Function to search for a student by roll number
void searchStudent(const Student students[], int count) {
    if (count == 0) {
        printf("No students to search.\n");
        return;
    }

    int roll;
    printf("Enter Roll No to search: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number!\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("Student Found: %s, Marks: %.2f\n", students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student with Roll No %d not found.\n", roll);
}

// Function to sort students by marks in descending order
void sortStudents(Student students[], int count) {
    if (count < 2) {
        printf("Not enough students to sort.\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].marks < students[j].marks) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by marks in descending order.\n");
}
