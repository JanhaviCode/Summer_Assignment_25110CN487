//Write a program to Remove duplicates from array.
#include <stdio.h>
int main() {
    int arr[100], unique[100];
    int n, count = 0, found;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
        found = 0;

        for(int j = 0; j < count; j++) {
            if(arr[i] == unique[j]) {
                found = 1;
                break;
            }
        }
        if(found == 0) {
            unique[count] = arr[i];
            count++;
        }
    }
    printf("Array after removing duplicates:\n");
    for(int i = 0; i < count; i++) {
        printf("%d ", unique[i]);
    }
    return 0;
}