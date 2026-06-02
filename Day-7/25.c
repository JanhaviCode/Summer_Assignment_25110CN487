// Write a program to recursive factorial.
#include <stdio.h>

long long factorial(int n)
{
    if (n == 0 || n == 1)   // Base case
        return 1;
    else
        return n * factorial(n - 1);  // Recursive call
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factorial of %d = %lld\n", n, factorial(n));

    return 0;
}