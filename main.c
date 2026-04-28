#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

static void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        ;
    }
}

static void readLine(char buffer[], size_t size) {
    if (fgets(buffer, (int)size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    } else {
        buffer[0] = '\0';
    }
}

void addStudent(struct Student s[], int *n) {
    printf("Enter Roll Number: ");
    if (scanf("%d", &s[*n].roll) != 1) {
        printf("Invalid roll number. Please try again.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    printf("Enter Name: ");
    readLine(s[*n].name, sizeof s[*n].name);

    printf("Enter Marks: ");
    if (scanf("%f", &s[*n].marks) != 1) {
        printf("Invalid marks. Please try again.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    (*n)++;
    printf("Student added successfully!\n");
}

void displayStudents(struct Student s[], int n) {
    int i;

    if(n == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n--- Student Details ---\n");
    for(i = 0; i < n; i++) {
        printf("Roll No: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n\n", s[i].marks);
    }
}

void searchStudent(struct Student s[], int n) {
    int roll, i, found = 0;

    printf("Enter roll number to search: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            printf("\nStudent Found!\n");
            printf("Roll No: %d\n", s[i].roll);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Student not found.\n");
    }
}

int main(void) {
    struct Student s[100];
    int n = 0;
    int choice;

    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudent(s, &n);
                break;

            case 2:
                displayStudents(s, n);
                break;

            case 3:
                searchStudent(s, n);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choice != 4);

    return 0;
}