#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define NAME_SIZE 50
#define DEPT_SIZE 30

typedef struct {
    char name[NAME_SIZE];
    int rollNo;
    char department[DEPT_SIZE];
} Student;

// Function to read student records from a file
int readFromFile(Student students[], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %d %s", students[count].name, &students[count].rollNo, students[count].department) == 3) {
        count++;
        if (count >= MAX_STUDENTS) break;
    }
    fclose(file);
    return count;
}

// Bubble Sort function
void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0 || 
                (strcmp(students[j].name, students[j + 1].name) == 0 && students[j].rollNo > students[j + 1].rollNo)) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Binary Search function
void binarySearch(Student students[], int n, const char* targetName) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, targetName) == 0) {
            printf("Found: %s %d %s\n", students[i].name, students[i].rollNo, students[i].department);
            found = 1;
        }
    }
    if (!found) {
        printf("No records found for student name: %s\n", targetName);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = readFromFile(students, "students.txt");

    if (studentCount == 0) {
        return 1; // Exit if no students are read
    }

    int choice;
    do {
        printf("Choose an option:\n1. Bubble Sort\n2. Binary Search\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            bubbleSort(students, studentCount);
            printf("Records after sorting:\n");
            for (int i = 0; i < studentCount; i++) {
                printf("%s %d %s\n", students[i].name, students[i].rollNo, students[i].department);
            }
            break;
        case 2: {
            char name[NAME_SIZE];
            printf("Enter the name to search: ");
            scanf("%s", name);
            binarySearch(students, studentCount, name);
            break;
        }
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
