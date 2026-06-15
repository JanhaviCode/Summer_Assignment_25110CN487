// Write a program to Subtract matrices.
#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10];
    int rows, col;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &col);

    printf("Enter first matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter second matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("Difference of matrices:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}