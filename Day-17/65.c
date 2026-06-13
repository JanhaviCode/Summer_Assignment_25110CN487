//Write a program to Merge arrays.
#include <stdio.h>
void merge(int arr1[],int s1,int arr2[],int s2,int merged[]){
    for (int i=0;i<s1;i++){
        merged[i]=arr1[i];
    }
    for (int i=0;i<s2;i++){
        merged[s1+i]=arr2[i];
    }
}
int main(){
    int arr1[100],arr2[100],merged[200];
    int s1,s2;
    printf("Enter the size of first array:");
    scanf("%d",&s1);
    printf("Enter the elements of first array:");
    for (int i=0;i<s1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter the size of second array:");
    scanf("%d",&s2);
    printf("Enter the elements of second array:");
    for (int i=0;i<s2;i++){
        scanf("%d",&arr2[i]);
    }
    merge(arr1,s1,arr2,s2,merged);
    printf("Merged array:");
    for (int i=0;i<s1+s2;i++){
        printf("%d ",merged[i]);
    }
    return 0;
}