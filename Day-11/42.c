//Write a program to Write function to find maximum.
#include <stdio.h>
int Max(int a, int b) {
    return (a > b) ? a : b;
}
int main() {
    int num1, num2, max;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    max = Max(num1, num2);
    printf("Maximum of %d and %d is %d\n", num1, num2, max);
    return 0;
}