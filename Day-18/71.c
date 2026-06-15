//Write a program to Binary search.
#include <stdio.h>
int main() {
    int arr[100], n, i, key, low, high, mid;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array (sorted):\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return 0;
        } else if(arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Element not found in the array.\n");
    return 0;
}