//Write a program to Find column-wise sum.
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
    int mat[10][10], rows, col, colSum[10];
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &col);
    printf("Enter the elements of the matrix: \n");
    matIn(mat, rows, col);
    printf("Matrix: \n");
    matOut(mat, rows, col);
    for (int j=0; j<col;j++){
        colSum[j] = 0;
        for(int i=0;i<rows;i++){
            colSum[j] += mat[i][j];
        }
    }
    printf("Column-wise sum of the matrix is: \n");
    for (int j=0; j<col;j++){
        printf("Column %d: %d\n", j+1, colSum[j]);
    }
    return 0;      
}