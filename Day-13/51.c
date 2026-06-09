//Write a program to Find largest and smallest element
#include <stdio.h>
int main(){
    int n, max, min;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    max = min = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    printf("Largest element in the array is: %d\n", max);
    printf("Smallest element in the array is: %d\n", min);
    return 0;
}