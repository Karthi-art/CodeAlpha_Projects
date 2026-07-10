/* FEATURES:
 * - Add new student records
 * - Search student by roll number
 * - Update student information
 * - Delete student records
 * - Display all students
 * - File I/O for persistent storage
 * - Structures for data organization
 * 
 * COMPILATION:
 * gcc student_management.c -o student_mgmt
 * 
 * EXECUTION:
 * ./student_mgmt (Linux/macOS)
 * student_mgmt.exe (Windows)
 * 
 * DATA FILE: students.dat (generated at runtime)
 * ====================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "students.dat"
#define NAME_SIZE 50
#define EMAIL_SIZE 50
#define DEPT_SIZE 30

// Structure to store student data
struct Student {
    int roll_number;
    char name[NAME_SIZE];
    char email[EMAIL_SIZE];
    float gpa;
    char department[DEPT_SIZE];
};

// Function to display menu
void displayMenu() {
    printf("\n========================================\n");
    printf("  STUDENT MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add New Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Save and Exit\n");
    printf("========================================\n");
}

// Function to add a new student
void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nERROR: Cannot add more students. Database full!\n");
        printf("Maximum capacity: %d students\n", MAX_STUDENTS);
        return;
    }

    printf("\n========== ADD NEW STUDENT ==========\n");

    printf("Enter Roll Number: ");
    scanf("%d", &students[*count].roll_number);

    // Check for duplicate roll number
    for (int i = 0; i < *count; i++) {
        if (students[i].roll_number == students[*count].roll_number) {
            printf("ERROR: Student with this roll number already exists!\n");
            return;
        }
    }

    getchar(); // Clear newline from buffer

    printf("Enter Name: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = 0;

    printf("Enter Email: ");
    fgets(students[*count].email, sizeof(students[*count].email), stdin);
    students[*count].email[strcspn(students[*count].email, "\n")] = 0;

    printf("Enter GPA: ");
    scanf("%f", &students[*count].gpa);

    // Validate GPA
    if (students[*count].gpa < 0.0 || students[*count].gpa > 4.0) {
        printf("ERROR: GPA must be between 0.0 and 4.0\n");
        return;
    }

    getchar();

    printf("Enter Department: ");
    fgets(students[*count].department, sizeof(students[*count].department), stdin);
    students[*count].department[strcspn(students[*count].department, "\n")] = 0;

    (*count)++;
    printf("\n✓ Student added successfully!\n");
    printf("Total students: %d\n", *count);
}

// Function to display all students
void displayAllStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("\n⚠ No students in database!\n");
        return;
    }

    printf("\n=========== ALL STUDENTS ===========\n");
    printf("%-6s %-20s %-25s %-6s %-15s\n",
           "Roll", "Name", "Email", "GPA", "Department");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-25s %-6.2f %-15s\n",
               students[i].roll_number,
               students[i].name,
               students[i].email,
               students[i].gpa,
               students[i].department);
    }
    printf("-----------------------------------------------------------\n");
    printf("Total Records: %d\n", count);
}

// Function to search student by roll number
void searchStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("\n⚠ No students in database!\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll_number == roll) {
            printf("\n========== STUDENT FOUND ==========\n");
            printf("Roll Number: %d\n", students[i].roll_number);
            printf("Name: %s\n", students[i].name);
            printf("Email: %s\n", students[i].email);
            printf("GPA: %.2f\n", students[i].gpa);
            printf("Department: %s\n", students[i].department);
            printf("===================================\n");
            return;
        }
    }
    printf("\n✗ Student not found!\n");
}

// Function to update student record
void updateStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("\n⚠ No students in database!\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll_number == roll) {
            printf("\n========== UPDATE STUDENT ==========\n");
            printf("Current Details:\n");
            printf("Name: %s\n", students[i].name);
            printf("Email: %s\n", students[i].email);
            printf("GPA: %.2f\n", students[i].gpa);
            printf("Department: %s\n", students[i].department);
            printf("\nEnter new GPA: ");
            scanf("%f", &students[i].gpa);

            // Validate GPA
            if (students[i].gpa < 0.0 || students[i].gpa > 4.0) {
                printf("ERROR: GPA must be between 0.0 and 4.0\n");
                return;
            }

            getchar();
            printf("Enter new Department: ");
            fgets(students[i].department, sizeof(students[i].department), stdin);
            students[i].department[strcspn(students[i].department, "\n")] = 0;

            printf("\n✓ Record updated successfully!\n");
            return;
        }
    }
    printf("\n✗ Student not found!\n");
}

// Function to delete student record
void deleteStudent(struct Student students[], int *count) {
    if (*count == 0) {
        printf("\n⚠ No students in database!\n");
        return;
    }

    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < *count; i++) {
        if (students[i].roll_number == roll) {
            // Shift remaining records
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("\n✓ Student deleted successfully!\n");
            printf("Total students: %d\n", *count);
            return;
        }
    }
    printf("\n✗ Student not found!\n");
}

// Function to save data to file (Binary)
void saveToFile(struct Student students[], int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("\nERROR: Cannot open file for writing!\n");
        return;
    }

    // Write count first
    fwrite(&count, sizeof(int), 1, file);

    // Write student records
    fwrite(students, sizeof(struct Student), count, file);

    fclose(file);
    printf("\n✓ Data saved to file successfully!\n");
    printf("File: %s\n", FILE_NAME);
    printf("Records saved: %d\n", count);
}

// Function to load data from file (Binary)
void loadFromFile(struct Student students[], int *count) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("No existing data file found. Starting fresh.\n");
        *count = 0;
        return;
    }

    // Read count first
    fread(count, sizeof(int), 1, file);

    // Read student records
    fread(students, sizeof(struct Student), *count, file);

    fclose(file);
    printf("✓ Data loaded from file successfully!\n");
    printf("Records loaded: %d\n", *count);
}

// Main function
int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    printf("\n");
    printf("    ╔═══════════════════════════════════════╗\n");
    printf("    ║  STUDENT MANAGEMENT SYSTEM           ║\n");
    printf("    ║  CodeAlpha Internship Project        ║\n");
    printf("    ╚═══════════════════════════════════════╝\n");

    // Load existing data from file
    loadFromFile(students, &count);

    do {
        displayMenu();
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                displayAllStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                updateStudent(students, count);
                break;

            case 5:
                deleteStudent(students, &count);
                break;

            case 6:
                saveToFile(students, count);
                printf("\nThank you for using Student Management System!\n");
                printf("Goodbye! 👋\n\n");
                break;

            default:
                printf("\nERROR: Invalid choice! Please enter 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}

/*
 * ====================================================================
 * TEST CASES:
 * ====================================================================
 * 
 * TEST 1: Add Students
 * Add 3 students with different details
 * Verify: Count increases, data stored correctly
 * 
 * TEST 2: Display All
 * Display all added students
 * Verify: All records shown in table format
 * 
 * TEST 3: Search Existing Student
 * Search for roll number 101
 * Verify: Student details displayed
 * 
 * TEST 4: Search Non-existing Student
 * Search for roll number 999
 * Verify: "Student not found!" message
 * 
 * TEST 5: Update Student
 * Update GPA and department of roll 101
 * Verify: Changes reflected in display
 * 
 * TEST 6: Delete Student
 * Delete roll number 102
 * Verify: Student removed, count decreased
 * 
 * TEST 7: Duplicate Roll Number
 * Try adding student with existing roll number
 * Verify: Error message displayed
 * 
 * TEST 8: File Persistence
 * Save data, close program, reopen
 * Verify: Data loaded correctly
 * 
 * TEST 9: Invalid GPA
 * Try entering GPA > 4.0
 * Verify: Error message, data not saved
 * 
 * ====================================================================
 */
