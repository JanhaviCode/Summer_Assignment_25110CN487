//Write a program to Print number pyramid.
#include <stdio.h>

int main() {
    int i, j, k, n = 5;

    for(i = 1; i <= n; i++) {

        // Print spaces
        for(j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Print ascending numbers
        for(j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Print descending numbers
        for(k = i - 1; k >= 1; k--) {
            printf("%d", k);
        }

        printf("\n");
    }

    return 0;
}