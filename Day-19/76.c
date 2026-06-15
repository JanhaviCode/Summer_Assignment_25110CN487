// Write a program to Find diagonal sum.
#include <stdio.h>

int main() {
    int a[10][10], rows, col, sum = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &col);

    printf("Enter matrix elements:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i < rows; i++) {
        sum += a[i][i];
    }

    printf("Diagonal Sum = %d", sum);

    return 0;
}