#include <stdio.h>
#include <stdlib.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    int quantity;
};

void addBook() {
    struct Book b;
    FILE *fp = fopen("library.txt", "a");

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Name: ");
    scanf("%s", b.name);

    printf("Enter Author Name: ");
    scanf("%s", b.author);

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    fprintf(fp, "%d %s %s %d\n", b.id, b.name, b.author, b.quantity);

    fclose(fp);
    printf("Book Added Successfully.\n");
}

void displayBooks() {
    struct Book b;
    FILE *fp = fopen("library.txt", "r");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("\nID\tBook Name\tAuthor\tQuantity\n");

    while (fscanf(fp, "%d %s %s %d", &b.id, b.name, b.author, &b.quantity) != EOF) {
        printf("%d\t%s\t\t%s\t%d\n", b.id, b.name, b.author, b.quantity);
    }

    fclose(fp);
}

void searchBook() {
    struct Book b;
    int id, found = 0;

    FILE *fp = fopen("library.txt", "r");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %d", &b.id, b.name, b.author, &b.quantity) != EOF) {
        if (b.id == id) {
            printf("\nBook Found\n");
            printf("ID: %d\n", b.id);
            printf("Book Name: %s\n", b.name);
            printf("Author: %s\n", b.author);
            printf("Quantity: %d\n", b.quantity);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Book Not Found.\n");
}

void updateBook() {
    struct Book b;
    int id, found = 0;

    FILE *fp = fopen("library.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Book ID to Update: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %d", &b.id, b.name, b.author, &b.quantity) != EOF) {
        if (b.id == id) {
            printf("Enter New Book Name: ");
            scanf("%s", b.name);

            printf("Enter New Author Name: ");
            scanf("%s", b.author);

            printf("Enter New Quantity: ");
            scanf("%d", &b.quantity);

            found = 1;
        }

        fprintf(temp, "%d %s %s %d\n", b.id, b.name, b.author, b.quantity);
    }

    fclose(fp);
    fclose(temp);

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (found)
        printf("Book Updated Successfully.\n");
    else
        printf("Book Not Found.\n");
}

void deleteBook() {
    struct Book b;
    int id, found = 0;

    FILE *fp = fopen("library.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Book ID to Delete: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d %s %s %d", &b.id, b.name, b.author, &b.quantity) != EOF) {
        if (b.id == id) {
            found = 1;
            continue;
        }

        fprintf(temp, "%d %s %s %d\n", b.id, b.name, b.author, b.quantity);
    }

    fclose(fp);
    fclose(temp);

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (found)
        printf("Book Deleted Successfully.\n");
    else
        printf("Book Not Found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                printf("Thank You!\n");
                return 0;
            default:
                printf("Invalid Choice.\n");
        }
    }
}