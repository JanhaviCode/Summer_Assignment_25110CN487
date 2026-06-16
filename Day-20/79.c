//Write a program to Find row-wise sum.
#include <stdio.h>
void matIn(int matrix[10][10], int rows, int col){
    for (int i=0; i<rows;i++){
        for(int j=0;j<col;j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}
void matOut(int matrix[10][10], int rows, int col){
    for (int i=0; i<rows;i++){
        for(int j=0;j<col;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int mat[10][10], rows, col, rowSum[10];
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &col);
    printf("Enter the elements of the matrix: \n");
    matIn(mat, rows, col);
    printf("Matrix: \n");
    matOut(mat, rows, col);
    for (int i=0; i<rows;i++){
        rowSum[i] = 0;
        for(int j=0;j<col;j++){
            rowSum[i] += mat[i][j];
        }
    }
    printf("Row-wise sum of the matrix is: \n");
    for (int i=0; i<rows;i++){
        printf("Row %d: %d\n", i+1, rowSum[i]);
    }
    return 0;
}