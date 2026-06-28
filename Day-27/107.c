#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Salary {
    int id;
    char name[50];
    float basic, hra, da, total;
};

void addRecord() {
    struct Salary s;
    FILE *fp = fopen("salary.txt", "a");

    printf("Enter Employee ID: ");
    scanf("%d", &s.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Basic Salary: ");
    scanf("%f", &s.basic);

    printf("Enter HRA: ");
    scanf("%f", &s.hra);

    printf("Enter DA: ");
    scanf("%f", &s.da);

    s.total = s.basic + s.hra + s.da;

    fprintf(fp, "%d %s %.2f %.2f %.2f %.2f\n", s.id, s.name, s.basic, s.hra, s.da, s.total);

    fclose(fp);

    printf("Record Added Successfully.\n");
}

void displayRecord() {
    struct Salary s;
    FILE *fp = fopen("salary.txt", "r");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("\nID\tName\tBasic\tHRA\tDA\tTotal\n");

    while (fscanf(fp, "%d %s %f %f %f %f",
                  &s.id, s.name, &s.basic, &s.hra, &s.da, &s.total) != EOF) {

        printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
               s.id, s.name, s.basic, s.hra, s.da, s.total);
    }

    fclose(fp);
}

void searchRecord() {
    struct Salary s;
    int id, found = 0;

    FILE *fp = fopen("salary.txt", "r");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Employee ID to Search: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %f %f %f %f",
                  &s.id, s.name, &s.basic, &s.hra, &s.da, &s.total) != EOF) {

        if (s.id == id) {
            printf("\nEmployee Found\n");
            printf("ID: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("Basic: %.2f\n", s.basic);
            printf("HRA: %.2f\n", s.hra);
            printf("DA: %.2f\n", s.da);
            printf("Total Salary: %.2f\n", s.total);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record Not Found.\n");

    fclose(fp);
}

void updateRecord() {
    struct Salary s;
    int id, found = 0;

    FILE *fp = fopen("salary.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Employee ID to Update: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %f %f %f %f",
                  &s.id, s.name, &s.basic, &s.hra, &s.da, &s.total) != EOF) {

        if (s.id == id) {
            printf("Enter New Basic Salary: ");
            scanf("%f", &s.basic);

            printf("Enter New HRA: ");
            scanf("%f", &s.hra);

            printf("Enter New DA: ");
            scanf("%f", &s.da);

            s.total = s.basic + s.hra + s.da;
            found = 1;
        }

        fprintf(temp, "%d %s %.2f %.2f %.2f %.2f\n",
                s.id, s.name, s.basic, s.hra, s.da, s.total);
    }

    fclose(fp);
    fclose(temp);

    remove("salary.txt");
    rename("temp.txt", "salary.txt");

    if (found)
        printf("Record Updated Successfully.\n");
    else
        printf("Record Not Found.\n");
}

void deleteRecord() {
    struct Salary s;
    int id, found = 0;

    FILE *fp = fopen("salary.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Employee ID to Delete: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %f %f %f %f",
                  &s.id, s.name, &s.basic, &s.hra, &s.da, &s.total) != EOF) {

        if (s.id == id) {
            found = 1;
            continue;
        }

        fprintf(temp, "%d %s %.2f %.2f %.2f %.2f\n",
                s.id, s.name, s.basic, s.hra, s.da, s.total);
    }

    fclose(fp);
    fclose(temp);

    remove("salary.txt");
    rename("temp.txt", "salary.txt");

    if (found)
        printf("Record Deleted Successfully.\n");
    else
        printf("Record Not Found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Salary Management System =====\n");
        printf("1. Add Salary Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record\n");
        printf("4. Update Salary\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecord();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                updateRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                printf("Thank You!\n");
                return 0;
            default:
                printf("Invalid Choice.\n");
        }
    }
}