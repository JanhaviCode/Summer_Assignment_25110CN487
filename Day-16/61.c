// Write a program to Find missing number in array
#include <stdio.h>

int main() {
    int n, i, sum = 0, total, miss;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n - 1];
    printf("Enter %d numbers: ", n - 1);
    for(i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    total = n * (n + 1) / 2;
    miss = total - sum;
    printf("Missing number = %d", miss);
    return 0;
}