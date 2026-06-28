#include <stdio.h>
#include <string.h>

int main() {
    char str[100], result[100];
    int k = 0, flag;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        flag = 0;

        for (int j = 0; j < i; j++) {
            if (str[i] == str[j] && str[i] != '\n' && str[i] != ' ') {
                flag ++;  
            }
        }

        if (flag == 0)
            result[k++] = str[i];
    }

    result[k] = '\0';

    printf("String after removing duplicate characters: %s", result);

    return 0;
}