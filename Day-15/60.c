// Write a program to Move zeroes to end.
#include <stdio.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], result[n];
    
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int k = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            result[k] = arr[i];
            k++;
        }
    }
    while(k < n) {
        result[k] = 0;
        k++;
    }

    printf("Array after moving zeroes to end:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}