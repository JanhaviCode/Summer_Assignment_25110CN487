// Write a program to Transpose matrix.
#include <stdio.h>

int main() {
    int a[10][10], t[10][10];
    int rows, col;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &col);

    printf("Enter matrix elements:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            t[j][i] = a[i][j];
        }
    }

    printf("Transpose Matrix:\n");
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < rows; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}