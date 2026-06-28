#include <stdio.h>
#include <stdlib.h>

struct Contact {
    int id;
    char name[50];
    char phone[20];
};

void addContact() {
    struct Contact c;
    FILE *fp = fopen("contact.txt", "a");

    printf("Enter Contact ID: ");
    scanf("%d", &c.id);

    printf("Enter Name: ");
    scanf("%s", c.name);

    printf("Enter Phone Number: ");
    scanf("%s", c.phone);

    fprintf(fp, "%d %s %s\n", c.id, c.name, c.phone);

    fclose(fp);
    printf("Contact Added Successfully.\n");
}

void displayContacts() {
    struct Contact c;
    FILE *fp = fopen("contact.txt", "r");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("\nID\tName\tPhone Number\n");

    while (fscanf(fp, "%d %s %s", &c.id, c.name, c.phone) != EOF) {
        printf("%d\t%s\t%s\n", c.id, c.name, c.phone);
    }

    fclose(fp);
}

void searchContact() {
    struct Contact c;
    int id, found = 0;

    FILE *fp = fopen("contact.txt", "r");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Contact ID: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s", &c.id, c.name, c.phone) != EOF) {
        if (c.id == id) {
            printf("\nContact Found\n");
            printf("ID: %d\n", c.id);
            printf("Name: %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Contact Not Found.\n");
}

void updateContact() {
    struct Contact c;
    int id, found = 0;

    FILE *fp = fopen("contact.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Contact ID to Update: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s", &c.id, c.name, c.phone) != EOF) {
        if (c.id == id) {
            printf("Enter New Name: ");
            scanf("%s", c.name);

            printf("Enter New Phone Number: ");
            scanf("%s", c.phone);

            found = 1;
        }

        fprintf(temp, "%d %s %s\n", c.id, c.name, c.phone);
    }

    fclose(fp);
    fclose(temp);

    remove("contact.txt");
    rename("temp.txt", "contact.txt");

    if (found)
        printf("Contact Updated Successfully.\n");
    else
        printf("Contact Not Found.\n");
}

void deleteContact() {
    struct Contact c;
    int id, found = 0;

    FILE *fp = fopen("contact.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Contact ID to Delete: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s", &c.id, c.name, c.phone) != EOF) {
        if (c.id == id) {
            found = 1;
            continue;
        }

        fprintf(temp, "%d %s %s\n", c.id, c.name, c.phone);
    }

    fclose(fp);
    fclose(temp);

    remove("contact.txt");
    rename("temp.txt", "contact.txt");

    if (found)
        printf("Contact Deleted Successfully.\n");
    else
        printf("Contact Not Found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                updateContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                printf("Thank You!\n");
                return 0;
            default:
                printf("Invalid Choice.\n");
        }
    }
}