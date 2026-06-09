//Write a program to Write function to find sum of two numbers.
#include <stdio.h>

// Function to find sum
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int num1, num2, sum;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    sum = add(num1, num2);

    printf("Sum = %d", sum);

    return 0;
}