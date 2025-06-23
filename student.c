#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100
Student students[MAX_STUDENTS];
int count = 0;

void addStudent() {
    if (count >= MAX_STUDENTS) {
        printf("Student limit reached.\n");
        return;
    }
    printf("Enter ID, Name, Age, GPA: ");
    scanf("%d %s %d %f", &students[count].id, students[count].name, &students[count].age, &students[count].gpa);
    count++;
}

void listStudents() {
    printf("\n%-5s %-20s %-5s %-5s\n", "ID", "Name", "Age", "GPA");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-5d %-5.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
    }
}

void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Found: %d %s %d %.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void updateStudent() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter new Name, Age, GPA: ");
            scanf("%s %d %f", students[i].name, &students[i].age, &students[i].gpa);
            printf("Updated successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

int compareName(const void *a, const void *b) {
    return strcmp(((Student *)a)->name, ((Student *)b)->name);
}

int compareAge(const void *a, const void *b) {
    return ((Student *)a)->age - ((Student *)b)->age;
}

int compareGPA(const void *a, const void *b) {
    float diff = ((Student *)b)->gpa - ((Student *)a)->gpa;
    return (diff > 0) - (diff < 0);
}

void sortByName() {
    qsort(students, count, sizeof(Student), compareName);
    printf("Sorted by name.\n");
}

void sortByAge() {
    qsort(students, count, sizeof(Student), compareAge);
    printf("Sorted by age.\n");
}

void sortByGPA() {
    qsort(students, count, sizeof(Student), compareGPA);
    printf("Sorted by GPA.\n");
}

void saveToFile() {
    FILE *f = fopen("data.txt", "w");
    if (!f) {
        perror("Failed to open file");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(f, "%d %s %d %.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
    }
    fclose(f);
    printf("Saved to file.\n");
}

void loadFromFile() {
    FILE *f = fopen("data.txt", "r");
    if (!f) return;
    while (fscanf(f, "%d %s %d %f", &students[count].id, students[count].name, &students[count].age, &students[count].gpa) == 4) {
        count++;
    }
    fclose(f);
}
