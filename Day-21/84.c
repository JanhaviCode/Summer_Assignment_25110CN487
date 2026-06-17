//Write a program to Convert lowercase to uppercase.
#include <stdio.h>
int main() {
    char str[100];
    int count = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    while (str[count] != '\0') {
        if (str[count] >= 'a' && str[count] <= 'z') {
            str[count] = str[count] - 32; 
        }
        count++;
    }
    printf("Converted string: %s", str);
    return 0;
}