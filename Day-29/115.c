#include <stdio.h>
#include <string.h>

void length(char str[]);
void copy(char str[]);
void concatenate(char str[]);
void compare(char str[]);
void reverse(char str[]);

int main() {
    char str[100];
    int choice;

    printf("Enter a string: ");
    scanf("%s", str);

    do {
        printf("\n===== STRING MENU =====\n");
        printf("1. Find Length\n");
        printf("2. Copy String\n");
        printf("3. Concatenate String\n");
        printf("4. Compare String\n");
        printf("5. Reverse String\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                length(str);
                break;

            case 2:
                copy(str);
                break;

            case 3:
                concatenate(str);
                break;

            case 4:
                compare(str);
                break;

            case 5:
                reverse(str);
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

void length(char str[]) {
    printf("Length = %d\n", strlen(str));
}

void copy(char str[]) {
    char copy[100];
    strcpy(copy, str);
    printf("Copied String = %s\n", copy);
}

void concatenate(char str[]) {
    char str2[100];

    printf("Enter another string: ");
    scanf("%s", str2);

    strcat(str, str2);

    printf("Concatenated String = %s\n", str);
}

void compare(char str[]) {
    char str2[100];

    printf("Enter another string: ");
    scanf("%s", str2);

    if(strcmp(str, str2) == 0)
        printf("Strings are Equal\n");
    else
        printf("Strings are Not Equal\n");
}

void reverse(char str[]) {
    strrev(str);
    printf("Reversed String = %s\n", str);
}