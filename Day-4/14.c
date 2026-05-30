// Write a program to find nth Fibonacci term.
#include <stdio.h>

int main() {
    int n, a = 0, b = 1, fib, i;

    printf("Enter the term number: ");
    scanf("%d", &n);

    if (n == 1) {
        printf("Nth Fibonacci term = %d", a);
    }
    else if (n == 2) {
        printf("Nth Fibonacci term = %d", b);
    }
    else {
        for (i = 3; i <= n; i++) {
            fib = a + b;
            a = b;
            b = fib;
        }
        printf("Nth Fibonacci term = %d", b);
    }

    return 0;
}
