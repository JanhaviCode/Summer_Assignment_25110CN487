#include <stdio.h>
#include <string.h>
struct Product {
    int id;
    char name[30];
    int quantity;
    float price;
};
void addProduct();
void viewProducts();
void searchProduct();
int main() {
    int choice;
    do {
        printf("\n===== INVENTORY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search Product\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;

            case 2:
                viewProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}

void addProduct() {
    struct Product p;
    FILE *fp;

    fp = fopen("inventory.txt", "a");

    printf("Enter Product ID: ");
    scanf("%d", &p.id);

    printf("Enter Product Name: ");
    scanf("%s", p.name);

    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);

    printf("Enter Price: ");
    scanf("%f", &p.price);

    fprintf(fp, "%d %s %d %.2f\n", p.id, p.name, p.quantity, p.price);

    fclose(fp);

    printf("Product Added Successfully!\n");
}

void viewProducts() {
    struct Product p;
    FILE *fp;

    fp = fopen("inventory.txt", "r");

    if(fp == NULL) {
        printf("No Records Found!\n");
        return;
    }

    printf("\nID\tName\tQuantity\tPrice\n");

    while(fscanf(fp, "%d %s %d %f", &p.id, p.name, &p.quantity, &p.price) != EOF) {
        printf("%d \t %s \t %d \t \t%.2f \n",
               p.id, p.name, p.quantity, p.price);
    }

    fclose(fp);
}

void searchProduct() {
    struct Product p;
    FILE *fp;
    int id, found = 0;

    fp = fopen("inventory.txt", "r");

    if(fp == NULL) {
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Product ID to Search: ");
    scanf("%d", &id);

    while(fscanf(fp, "%d %s %d %f", &p.id, p.name, &p.quantity, &p.price) != EOF) {

        if(id == p.id) {
            printf("\nProduct Found\n");
            printf("ID       : %d\n", p.id);
            printf("Name     : %s\n", p.name);
            printf("Quantity : %d\n", p.quantity);
            printf("Price    : %.2f\n", p.price);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Product Not Found!\n");

    fclose(fp);
}