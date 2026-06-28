#include <stdio.h>

int main() {
    int balance = 5000;
    int choice, amount, cardDetails, cardHolder;
    int gameFlag = 0;
    if (gameFlag == 0) {
        printf("Welcome to the ATM Simulation!\n");
        printf("Please select an option:\n");
        printf("enter card or card details\n");
        scanf("%d", &cardDetails);
        printf("enter card holder name\n");
        scanf("%d", &cardHolder);
        printf("Card accepted. Please select an option:\n");
        printf("enter 1 to get to next menu or 0 to exit: ");
        scanf("%d", &gameFlag);
    }
    while (gameFlag == 1) {
        printf("ATM Menu:\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Balance = %d", balance);
        printf("\nDo you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &gameFlag);
    }
    else if(choice == 2) {
        printf("Enter amount: ");
        scanf("%d", &amount);
        balance = balance + amount;
        printf("New Balance = %d", balance);
        printf("\nDo you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &gameFlag);
    }
    else if(choice == 3) {
        printf("Enter amount: ");
        scanf("%d", &amount);

        if(amount <= balance) {
            balance = balance - amount;
            printf("New Balance = %d", balance);
        }
        else {
            printf("Insufficient Balance");
        }
        printf("\nDo you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &gameFlag);
    }
    else if(choice == 4) {
        printf("Thank you for using the ATM. Goodbye!");
        gameFlag = 0;
    }
    else {
        printf("Invalid Choice");
    }
    }
    return 0;
}