//Write a program to Find maximum frequency element.
#include <stdio.h>
int main() {
    int n, i, j, maxCount = 0, count,element;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            element = arr[i];
        }
    }
    printf("Maximum frequency element is %d and it appears %d times.", element, maxCount);
    return 0;
}