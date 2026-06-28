#include <stdio.h>
#include <stdlib.h>


int main() {
    int secret, guess, gameFlag = 5;
    if (gameFlag == 5) {
        printf("Welcome to the Number Guessing Game!\n");
        printf("I have selected a secret number between 1 and 50.\n");
        printf("Try to guess the number!\n");
        printf("enter 1 to start the game or 0 to exit: ");
        scanf("%d", &gameFlag);
    }
    while (gameFlag == 1) {
        secret = rand() % 50 + 1;

        printf("Guess the number (1-50): ");
        scanf("%d", &guess);

        if (guess == secret)
            {printf("Correct Guess!\n");
            printf("Do you want to restart? (1 for Yes, 0 for No): ");
        scanf("%d", &gameFlag);}
        else if (guess < secret)
            printf("Too Small!\n");
        else
            printf("Too Large!\n");

        
    }
    if (gameFlag == 0) {
        printf("Thank you for playing! Goodbye!\n");
    } else {
        printf("Invalid input. Exiting the game.\n");
    }

    return 0;
}