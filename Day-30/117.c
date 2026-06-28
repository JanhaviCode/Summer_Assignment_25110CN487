#include <stdio.h>
#include <string.h>

int main() {
    int roll[100], marks[100];
    char name[100][50];
    int n = 0, choice, i, j, r, found;

    do {
        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter Roll Number: ");
            scanf("%d", &roll[n]);

            printf("Enter Name: ");
            scanf(" %[^\n]", name[n]);

            printf("Enter Marks: ");
            scanf("%d", &marks[n]);

            n++;
            printf("Student Added Successfully!\n");
            break;

        case 2:
            if(n == 0) {
                printf("No Records Found!\n");
            } else {
                printf("\nStudent Records:\n");
                for(i = 0; i < n; i++) {
                    printf("\nRoll Number: %d\n", roll[i]);
                    printf("Name: %s\n", name[i]);
                    printf("Marks: %d\n", marks[i]);
                }
            }
            break;

        case 3:
            printf("Enter Roll Number to Search: ");
            scanf("%d", &r);

            found = 0;
            for(i = 0; i < n; i++) {
                if(roll[i] == r) {
                    printf("\nRecord Found\n");
                    printf("Roll Number: %d\n", roll[i]);
                    printf("Name: %s\n", name[i]);
                    printf("Marks: %d\n", marks[i]);
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Student Not Found!\n");
            break;

        case 4:
            printf("Enter Roll Number to Update: ");
            scanf("%d", &r);

            found = 0;
            for(i = 0; i < n; i++) {
                if(roll[i] == r) {
                    printf("Enter New Name: ");
                    scanf(" %[^\n]", name[i]);

                    printf("Enter New Marks: ");
                    scanf("%d", &marks[i]);

                    printf("Record Updated Successfully!\n");
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Student Not Found!\n");
            break;

        case 5:
            printf("Enter Roll Number to Delete: ");
            scanf("%d", &r);

            found = 0;
            for(i = 0; i < n; i++) {
                if(roll[i] == r) {
                    for(j = i; j < n - 1; j++) {
                        roll[j] = roll[j + 1];
                        marks[j] = marks[j + 1];
                        strcpy(name[j], name[j + 1]);
                    }
                    n--;
                    printf("Record Deleted Successfully!\n");
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Student Not Found!\n");
            break;

        case 6:
            printf("Thank You!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}