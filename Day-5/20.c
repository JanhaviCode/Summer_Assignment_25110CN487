//Write a program to Find largest prime factor.
#include <stdio.h>
int isPrime(int n) {
    int flag = 0;
    if (n <= 1) {
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            flag ++;
        }
    }
    if(flag == 2) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Largest prime factor of %d is: ", n);
    for(int i = n; i >= 1; i--) {
        if(n % i == 0 && isPrime(i)==1) {
            printf("%d ", i);
            break;
        }
    }
    return 0;
}