#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for student
typedef struct {
    char name[100];
    int rollNumber;
    float gpa;
} Student;

// Function to add students
void addStudents(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", (students + i)->name); // Using pointer arithmetic
        printf("Roll Number: ");
        scanf("%d", &(students + i)->rollNumber);
        printf("GPA: ");
        scanf("%f", &(students + i)->gpa);
    }
}

// Function to display students
void displayStudents(Student *students, int count) {
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", (students + i)->name);
        printf("Roll Number: %d\n", (students + i)->rollNumber);
        printf("GPA: %.2f\n\n", (students + i)->gpa);
    }
}

// Function to update GPA
void updateGPA(Student *students, int count) {
    int rollNo;
    float newGPA;
    int found = 0;

    printf("\nEnter the roll number of the student to update GPA: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < count; i++) {
        if ((students + i)->rollNumber == rollNo) {
            printf("Enter new GPA for %s: ", (students + i)->name);
            scanf("%f", &newGPA);
            (students + i)->gpa = newGPA;
            printf("GPA updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNo);
    }
}

int main() {
    int numStudents;
    Student *students;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory
    students = (Student *)malloc(numStudents * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    addStudents(students, numStudents);
    displayStudents(students, numStudents);

    char choice;
    printf("Do you want to update a student's GPA? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        updateGPA(students, numStudents);
        displayStudents(students, numStudents);
    }

    // Free the allocated memory
    free(students);
    printf("Memory freed. Program exiting.\n");

    return 0;
}
