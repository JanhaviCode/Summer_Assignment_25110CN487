#include <stdio.h>
int main(){
    int n, arr[100], i, j, count;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++){
    int flag = 0;

    for(j=0;j<n;j++){
        if(i!=j && arr[i]==arr[j]){
            flag = 1;
            break;
        }
    }

    if(flag!=0){
        printf("first repeated element in the array is: %d\n", arr[i]);
        break;
    }
}
}