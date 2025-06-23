#include <stdio.h>
#include "student.h"

int main() {
    loadFromFile();
    int choice;
    do {
        printf("\n--- Student Management Menu ---\n");
        printf("1. Add Student\n");
        printf("2. List Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Sort by Name\n");
        printf("7. Sort by Age\n");
        printf("8. Sort by GPA\n");
        printf("9. Save & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: listStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: sortByName(); break;
            case 7: sortByAge(); break;
            case 8: sortByGPA(); break;
            case 9: saveToFile(); printf("Exiting.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 9);

    return 0;
}
