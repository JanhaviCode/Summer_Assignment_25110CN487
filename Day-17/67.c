//Write a program to Intersection of arrays. 
#include <stdio.h>
int main() {
    int a[100], b[100], intersection[100];
    int n1, n2, i, j, k = 0;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements of first array:\n");
    for(i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements of second array:\n");
    for(i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }
    for(i = 0; i < n1; i++) {
        for(j = 0; j < n2; j++) {
            if(a[i] == b[j]) {
                intersection[k++] = a[i];
                break;
            }
        }
    }
    printf("Intersection of arrays: ");
    for(i = 0; i < k; i++) {
        printf("%d ", intersection[i]);
    }
    return 0;
}