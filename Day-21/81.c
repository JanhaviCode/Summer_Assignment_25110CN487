#include <stdio.h>
int main() {
    char str[100];
    int count = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    while (str[count] != '\0') {
        count++;
    }
    printf("Length of the string = %d\n", count);
    return 0;
}