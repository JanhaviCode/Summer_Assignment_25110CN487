//Write a program to write function to find sum of two numbers.
#include <stdio.h>
int Sum(int a, int b) {
    return a + b;
}
int main() {
    int num1, num2, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    sum = Sum(num1, num2);
    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    return 0;
}