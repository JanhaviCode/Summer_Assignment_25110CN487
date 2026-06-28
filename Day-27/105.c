// Student Record Management System using File Handling
#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    do {
        printf("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Thank You!\n"); break;
            default: printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.txt", "a");

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%d %s %.2f\n", s.roll, s.name, s.marks);

    fclose(fp);

    printf("Student Added Successfully!\n");
}

void viewStudents() {
    struct Student s;
    FILE *fp = fopen("students.txt", "r");

    if(fp == NULL) {
        printf("No Records Found!\n");
        return;
    }

    printf("\nRoll\tName\tMarks\n");

    while(fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
        printf("%d\t%s\t%.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}


void searchStudent() {
    struct Student s;
    int roll, found = 0;

    FILE *fp = fopen("students.txt", "r");

    if(fp == NULL) {
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    while(fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {

        if(s.roll == roll) {
            printf("\nStudent Found\n");
            printf("Roll  : %d\n", s.roll);
            printf("Name  : %s\n", s.name);
            printf("Marks : %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Student Not Found!\n");

    fclose(fp);
}


void updateStudent() {
    struct Student s;
    int roll, found = 0;

    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if(fp == NULL) {
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    while(fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {

        if(s.roll == roll) {

            printf("Enter New Name: ");
            scanf("%s", s.name);

            printf("Enter New Marks: ");
            scanf("%f", &s.marks);

            found = 1;
        }

        fprintf(temp, "%d %s %.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(found)
        printf("Record Updated Successfully!\n");
    else
        printf("Student Not Found!\n");
}


void deleteStudent() {
    struct Student s;
    int roll, found = 0;

    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if(fp == NULL) {
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    while(fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {

        if(s.roll == roll) {
            found = 1;
            continue;
        }

        fprintf(temp, "%d %s %.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(found)
        printf("Record Deleted Successfully!\n");
    else
        printf("Student Not Found!\n");
}