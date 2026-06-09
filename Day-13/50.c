//Write a program to Find sum and average of array
#include <stdio.h>
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    float average = (float)sum/n;
    printf("Sum of array elements is: %d\n", sum);
    printf("Average of array elements is: %.2f\n", average);
    return 0;
}