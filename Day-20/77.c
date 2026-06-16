// Write a program to Multiply matrices.
#include <Stdio.h>
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
void matMul(int matrix1[10][10],int matrix2[10][10],int matrix3[10][10], int rows1, int col1, int col2){
    
    for (int i=0; i<rows1;i++){
        for(int j=0;j<col2;j++){
            matrix3[i][j] = 0;
            for(int k=0;k<col1;k++){
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
int main(){
    int mat1[10][10], mat2[10][10], mat3[10][10], rows1, col1, rows2, col2;
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &col1);
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &col2);
    if(col1 != rows2) {
        printf("Matrix multiplication is not possible.");
        return 0;
    }
    printf("Enter the elements of first matrix: \n");
    matIn(mat1, rows1, col1);
    printf("Enter the elements of second matrix: \n");
    matIn(mat2, rows2, col2);
    printf("First matrix: \n");
    matOut(mat1, rows1, col1);
    printf("Second matrix: \n");
    matOut(mat2, rows2, col2);
    matMul(mat1, mat2, mat3, rows1, col1, col2);
    printf("Product of the two matrices is: \n");
    matOut(mat3, rows1, col2);
    return 0;
}