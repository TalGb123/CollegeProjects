#include <stdio.h>
#include <stdlib.h>
#define NO_ERROR 0

int** BuildMatrix(int* pRow, int* pCol) {
    printf("Enter the number of rows: ");
    *pRow = scanf("%d", pRow);
    printf("Enter the number of columns: ");
    *pCol = scanf("%d", pCol);

    int** matrix = (int**)malloc(*pRow * sizeof(int*));
    for (int i = 0; i < *pRow; i++) {
        matrix[i] = (int*)malloc(*pCol * sizeof(int));
        for (int j = 0; j < *pCol; j++) {
            matrix[i][j] = i * *pCol + j; // Example initialization
        }
    }
    return matrix;
}

void printMatrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** TransposeMatrix(int** matrix, int row, int col, int* pRow, int* pCol) {
    *pRow = col;
    *pCol = row;
    int** transposeMatrix = (int**)malloc(*pRow * sizeof(int*));
    for (int i = 0; i < *pRow; i++){
        transposeMatrix[i] = (int*)malloc(*pCol * sizeof(int*));
        for (int j=0; j < *pCol; j++){
            transposeMatrix[i][j] = matrix[j][i];
        }
    }
    return transposeMatrix;
}


int main() {
    int row, col;
    int** matrix = BuildMatrix(&row, &col);
    // printMatrix(matrix, row, col);
    int** transposeMatrix = TransposeMatrix(matrix, row, col, &row, &col);
    printMatrix(transposeMatrix, row, col);
    // Free allocated memory
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < col; i++) {
        free(transposeMatrix[i]);
    }
    free(transposeMatrix);

    return NO_ERROR;
}