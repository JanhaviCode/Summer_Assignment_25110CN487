//Write a program to Find longest word.
#include <stdio.h>
#include <string.h>
int main() {
    char str[100], longest[100];
    int n, maxLength = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    n = strlen(str);

    for (int i = 0; i < n; i++) {
        int length = 0;
        char word[100];

        while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
            word[length++] = str[i++];
        }
        word[length] = '\0';

        if (length > maxLength) {
            maxLength = length;
            strcpy(longest, word);
        }
    }
    printf("The longest word in the string is: %s\n", longest);
}