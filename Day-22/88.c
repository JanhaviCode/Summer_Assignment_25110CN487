//Write a program to Remove spaces from string.
#include <stdio.h>
int main() {
    char str1[100];

    int count = 0;
    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);

for (int i = 0; str1[i] != '\0'; i++) {
    if (str1[i] != ' ') {
        count++;
    }
}
    char str2[count + 1];
    int j = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != ' ') {
            str2[j++] = str1[i];
        }
    }
    str2[count] = '\0';
    printf("String after removing spaces: %s", str2);
    return 0;
}