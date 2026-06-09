// Write a program to Input and display array.
#include <stdio.h>
int main(){
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Elements in the array are: ");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}