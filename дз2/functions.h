#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <assert.h>

void set_elem(double** matrix, int row, int col, double elem){
    matrix[row][col] = elem;
}
double matrixNorm(double** matrix, int row, int col){
    double elemSum = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (matrix[i][j] != 0){
                elemSum += pow(matrix[i][j], 2);
            }
        }
    }
    return sqrt(elemSum);
}
void printMatrix(double** matrix, int row, int col){
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            printf("%f ", matrix[r][c]);
        }
        printf("\n"); 
    }
}
void deleteMatrix(double** matrix, int row){
    for (int r = 0; r < row; r++){
        free(matrix[r]);
    }
    free(matrix);
}