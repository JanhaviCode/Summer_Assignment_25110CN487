#include <stdio.h>
int main(){
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    int num = 65;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%c ", num);
        }
        num++;
        printf("\n");
    }
}