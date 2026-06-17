//Write a program to Reverse a string.
#include <stdio.h>
int main() {
    char str1[100];

    int count = 0;
    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);

    while (str1[count] != '\0') {
        count++;
    }
    char str2[count];
    for (int i = 0; i < count - 1; i++) {
        str2[count - 2 - i] = str1[i];
    }
    str2[count-1] = '\0'; 
    fputs(str2, stdout);
    return 0;
}