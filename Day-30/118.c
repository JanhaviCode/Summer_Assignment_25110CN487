#include <stdio.h>
#include <string.h>

int main() {
    int bookid[100], quantity[100];
    char title[100][50], author[100][50];
    int n = 0, choice, i, j, id, found;

    do {
        printf("\n===== Mini Library System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter Book ID: ");
            scanf("%d", &bookid[n]);

            printf("Enter Book Title: ");
            scanf(" %[^\n]", title[n]);

            printf("Enter Author Name: ");
            scanf(" %[^\n]", author[n]);

            printf("Enter Quantity: ");
            scanf("%d", &quantity[n]);

            n++;
            printf("Book Added Successfully!\n");
            break;

        case 2:
            if(n == 0) {
                printf("No Books Available!\n");
            } else {
                printf("\nLibrary Records:\n");
                for(i = 0; i < n; i++) {
                    printf("\nBook ID: %d\n", bookid[i]);
                    printf("Title: %s\n", title[i]);
                    printf("Author: %s\n", author[i]);
                    printf("Quantity: %d\n", quantity[i]);
                }
            }
            break;

        case 3:
            printf("Enter Book ID to Search: ");
            scanf("%d", &id);

            found = 0;
            for(i = 0; i < n; i++) {
                if(bookid[i] == id) {
                    printf("\nBook Found\n");
                    printf("Book ID: %d\n", bookid[i]);
                    printf("Title: %s\n", title[i]);
                    printf("Author: %s\n", author[i]);
                    printf("Quantity: %d\n", quantity[i]);
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Book Not Found!\n");
            break;

        case 4:
            printf("Enter Book ID to Update: ");
            scanf("%d", &id);

            found = 0;
            for(i = 0; i < n; i++) {
                if(bookid[i] == id) {
                    printf("Enter New Title: ");
                    scanf(" %[^\n]", title[i]);

                    printf("Enter New Author: ");
                    scanf(" %[^\n]", author[i]);

                    printf("Enter New Quantity: ");
                    scanf("%d", &quantity[i]);

                    printf("Book Updated Successfully!\n");
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Book Not Found!\n");
            break;

        case 5:
            printf("Enter Book ID to Delete: ");
            scanf("%d", &id);

            found = 0;
            for(i = 0; i < n; i++) {
                if(bookid[i] == id) {
                    for(j = i; j < n - 1; j++) {
                        bookid[j] = bookid[j + 1];
                        quantity[j] = quantity[j + 1];
                        strcpy(title[j], title[j + 1]);
                        strcpy(author[j], author[j + 1]);
                    }
                    n--;
                    printf("Book Deleted Successfully!\n");
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                printf("Book Not Found!\n");
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