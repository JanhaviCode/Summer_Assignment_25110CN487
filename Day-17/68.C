//Write a program to Find common elements.
#include <stdio.h>
int main() {
    int a[100], b[100], common[100];
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
                common[k++] = a[i];
                break;
            }
        }
    }

    printf("Common elements: ");
    for(i = 0; i < k; i++) {
        printf("%d ", common[i]);
    }

    return 0;
}