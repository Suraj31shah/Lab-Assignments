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

void binarySearch(Student students[], int n, char* name) {
    int low = 0, high = n - 1;
    int found = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(students[mid].name, name);

        if (cmp == 0) {
            int i = mid;
            while (i >= 0 && strcmp(students[i].name, name) == 0) i--;
            i++;
            while (i < n && strcmp(students[i].name, name) == 0) {
                printf("%s, %d, %s\n", students[i].name, students[i].rollNo, students[i].department);
                i++;
            }
            found = 1;
            break;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("No student found with name: %s\n", name);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = readFromFile(students, "students.txt");

    if (studentCount == 0) {
        return 1;
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
