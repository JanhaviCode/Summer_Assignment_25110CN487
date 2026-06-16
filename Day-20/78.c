//Write a program to Check symmetric matrix.
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
    int mat[10][10], rows, col, flag = 1;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &col);
    if(rows != col) {
        printf("Matrix is not symmetric.");
        return 0;
    }
    printf("Enter the elements of the matrix: \n");
    matIn(mat, rows, col);
    printf("Matrix: \n");
    matOut(mat, rows, col);
    for (int i=0; i<rows;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j] != mat[j][i]) {
                flag = 0;
                break;
            }
        }
        if(flag == 0) {
            break;
        }
    }
    if(flag == 1) {
        printf("Matrix is symmetric.");
    } else {
        printf("Matrix is not symmetric.");
    }
    return 0;
}