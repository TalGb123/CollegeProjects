#include <stdio.h>
#define NO_ERROR 0


int ex3(int arr[4][4]){
    int col, row;
    printf("Enter the row: ");
    scanf("%d", &row);
    while (row < 0 || row > 3 /*gotta change*/){
        printf("Invalid row. Please enter a valid row: ");
        scanf("%d", &row);
    }
    printf("Enter the column: ");
    scanf("%d", &col);
    while (col < 0 || col > 3 /*gotta change*/){
        printf("Invalid row. Please enter a valid row: ");
        scanf("%d", &row);
    }
    int val = arr[row][col];
    int mulCount = 0;
    int divCount = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (arr[i][j]%val == 0 && arr[i][j] != val){
                mulCount++;
            }
            if (val%arr[i][j] == 0 && arr[i][j] != val){
                divCount++;
            }
        }
    }
    printf("Multiples: %d\n", mulCount);
    printf("Divisors: %d\n", divCount);
    return NO_ERROR;
}

int is_symmetric(int matrix[][8], int start_row, int start_col) {
    int size = 2;
    while (start_row + size < 5 && start_col + size < 8) {
        if (matrix[start_row+size][start_col] == matrix[start_row][start_col+size] && 
        matrix[start_row][start_col] < matrix[start_row+size][start_col+size]) {
            size++;
        } else {
            break;
        }
    }
    return size;
}


int ex4(int matrix[5][8], int rows, int cols){
    int max_size = 0;
    int max_start_row = 0, max_start_col = 0;

    // Loop through all possible starting points
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i+1][j] == matrix[i][j+1] && matrix[i][j] < matrix[i+1][j+1]) {
                int tempSize = is_symmetric(matrix, i, j);
                if (tempSize > max_size) {
                    max_size = tempSize;
                    max_start_row = i;
                    max_start_col = j;
                }
            }
        }
    }
    printf("Size: %d\n", max_size);
    return NO_ERROR;
}


int main(){
    #define C1 4
    #define R1 4
    #define C2 8
    #define R2 5
    int matr1[R1][C1];
    int matr2[R2][C2];
    // for (int i = 0; i < R1; i++){
    //     for (int j = 0; j < C1; j++){
    //         printf("Enter value for matr1[%d][%d]: ", i, j);
    //         scanf("%d", &matr1[i][j]);
    //     }
    // }
    // for (int i = 0; i < R2; i++){
    //     for (int j = 0; j < C2; j++){
    //         printf("Enter value for matr2[%d][%d]: ", i, j);
    //         scanf("%d", &matr2[i][j]);
    //     }
    // }
    int matrix[5][8] = {
    {1, 2, 0, 3, 2, 1, 0, 7},
    {2, 3, 4, 1, 2, 3, 4, 5},
    {3, 4, 6, 2, 5, 6, 7, 6},
    {4, 5, 7, 3, 6, 8, 9, 8},
    {6, 7, 1, 4, 7, 9, 0, 9}
    };
    //ex3(matr1);
    ex4(matrix, R2, C2);
    return NO_ERROR;
}