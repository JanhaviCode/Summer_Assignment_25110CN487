#include <stdio.h>

int main() {
    int a[50], b[50], c[100];
    int n1, n2, i, j, temp;

    printf("Enter size of first array: ");
    scanf("%d",&n1);

    printf("Enter elements: ");
    for(i=0;i<n1;i++)
        scanf("%d",&a[i]);

    printf("Enter size of second array: ");
    scanf("%d",&n2);

    printf("Enter elements: ");
    for(i=0;i<n2;i++)
        scanf("%d",&b[i]);


    for(i=0;i<n1;i++)
        c[i]=a[i];


    for(i=0;i<n2;i++)
        c[n1+i]=b[i];


    for(i=0;i<n1+n2-1;i++){
        for(j=i+1;j<n1+n2;j++){
            if(c[i]>c[j]){
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }

    printf("Merged Array: ");
    for(i=0;i<n1+n2;i++)
        printf("%d ",c[i]);
}