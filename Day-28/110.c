#include <stdio.h>
#include <stdlib.h>

struct Bank {
    int accNo;
    char name[50];
    float balance;
};

void createAccount() {
    struct Bank b;
    FILE *fp = fopen("bank.txt", "a");

    printf("Enter Account Number: ");
    scanf("%d", &b.accNo);

    printf("Enter Customer Name: ");
    scanf("%s", b.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &b.balance);

    fprintf(fp, "%d %s %.2f\n", b.accNo, b.name, b.balance);

    fclose(fp);
    printf("Account Created Successfully.\n");
}

void displayAccounts() {
    struct Bank b;
    FILE *fp = fopen("bank.txt", "r");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("\nAcc No\tName\tBalance\n");

    while (fscanf(fp, "%d %s %f", &b.accNo, b.name, &b.balance) != EOF) {
        printf("%d\t%s\t%.2f\n", b.accNo, b.name, b.balance);
    }

    fclose(fp);
}

void searchAccount() {
    struct Bank b;
    int acc, found = 0;

    FILE *fp = fopen("bank.txt", "r");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fscanf(fp, "%d %s %f", &b.accNo, b.name, &b.balance) != EOF) {
        if (b.accNo == acc) {
            printf("\nAccount Found\n");
            printf("Account No: %d\n", b.accNo);
            printf("Name: %s\n", b.name);
            printf("Balance: %.2f\n", b.balance);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Account Not Found.\n");
}

void depositMoney() {
    struct Bank b;
    int acc, found = 0;
    float amount;

    FILE *fp = fopen("bank.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    while (fscanf(fp, "%d %s %f", &b.accNo, b.name, &b.balance) != EOF) {
        if (b.accNo == acc) {
            b.balance += amount;
            found = 1;
        }

        fprintf(temp, "%d %s %.2f\n", b.accNo, b.name, b.balance);
    }

    fclose(fp);
    fclose(temp);

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (found)
        printf("Amount Deposited Successfully.\n");
    else
        printf("Account Not Found.\n");
}

void withdrawMoney() {
    struct Bank b;
    int acc, found = 0;
    float amount;

    FILE *fp = fopen("bank.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    printf("Enter Withdraw Amount: ");
    scanf("%f", &amount);

    while (fscanf(fp, "%d %s %f", &b.accNo, b.name, &b.balance) != EOF) {
        if (b.accNo == acc) {
            if (amount <= b.balance) {
                b.balance -= amount;
                printf("Withdrawal Successful.\n");
            } else {
                printf("Insufficient Balance.\n");
            }
            found = 1;
        }

        fprintf(temp, "%d %s %.2f\n", b.accNo, b.name, b.balance);
    }

    fclose(fp);
    fclose(temp);

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (!found)
        printf("Account Not Found.\n");
}

void deleteAccount() {
    struct Bank b;
    int acc, found = 0;

    FILE *fp = fopen("bank.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No Records Found.\n");
        return;
    }

    printf("Enter Account Number to Delete: ");
    scanf("%d", &acc);

    while (fscanf(fp, "%d %s %f", &b.accNo, b.name, &b.balance) != EOF) {
        if (b.accNo == acc) {
            found = 1;
            continue;
        }

        fprintf(temp, "%d %s %.2f\n", b.accNo, b.name, b.balance);
    }

    fclose(fp);
    fclose(temp);

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (found)
        printf("Account Deleted Successfully.\n");
    else
        printf("Account Not Found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Bank Account Management System =====\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Search Account\n");
        printf("4. Deposit Money\n");
        printf("5. Withdraw Money\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                depositMoney();
                break;
            case 5:
                withdrawMoney();
                break;
            case 6:
                deleteAccount();
                break;
            case 7:
                printf("Thank You!\n");
                return 0;
            default:
                printf("Invalid Choice.\n");
        }
    }
}