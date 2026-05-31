// write a program to check perfect number.
#include <stdio.h>
int main (){
    int n, i, perfect;
    printf("Enter the number ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    perfect = 0;
    for (i=1; i<=n/2; ++i) {
        if (n%i== 0) {
            perfect += i;
        }
    }
    if (perfect==n) {
        printf("%d is a perfect number.\n", n);
    } else {
        printf("%d is not a perfect number.\n", n);
    }
    return 0;
}