//Write a program to Resurcive reverse number.
#include <stdio.h>

int reverseNum(int n, int rev)
{
    if (n == 0)
        return rev;

    return reverseNum(n / 10, rev * 10 + n % 10);
}

int main()
{
    int num, reverse;

    printf("Enter a number: ");
    scanf("%d", &num);

    reverse = reverseNum(num, 0);

    printf("Reversed number = %d\n", reverse);

    return 0;
}