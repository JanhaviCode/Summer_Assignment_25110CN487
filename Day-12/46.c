// Write a program to write a function for Armstrong number checking.
#include <stdio.h>
#include <math.h>

int isArm(int n) {
    int temp = n, r, len = 0, arm = 0;
    if (n < 0) {
        return 0;
    }
    while (temp != 0) {
        temp /= 10;
        len++;
    }
    temp = n;
    while (temp != 0) {
        r = temp % 10;
        arm += (int)round(pow((double)r, len));
        temp /= 10;
    }
    return arm == n;
}
int main() {
    int n;
    printf("Enter the number to check: ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    if (isArm(n)) {
        printf("%d is an Armstrong number\n", n);
    } else {
        printf("%d is not an Armstrong number\n", n);
    }
    return 0;
}
