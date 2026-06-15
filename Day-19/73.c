#include <stdio.h>

int main() {
    int mat1[10][10], mat2[10][10], mat3[10][10];
    int rows, col;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &col);

    printf("Enter the elements of first matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the elements of second matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("Sum of the two matrices is:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }

    return 0;
}