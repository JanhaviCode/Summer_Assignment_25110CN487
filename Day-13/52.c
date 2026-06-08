//Write a program to Count even and odd elements.
#include <stdio.h>
int main(){
    int n, even=0, odd=0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    printf("Number of even elements in the array is: %d\n", even);
    printf("Number of odd elements in the array is: %d\n", odd);
    return 0;
}