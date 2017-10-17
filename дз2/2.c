#include "functions.h"

int main(int argc, char* argv[]){

    if (argc < 2){
        printf("Not enough arguments in command line");
        return -1;
    } 

    int row = 0, col = 0, n = 0; //где лучше определять?
    int rowInd = 0, colInd = 0;
    double elem = 0;
    char buf = 0;
    FILE* f;
    for (int iter = 0; iter < argc - 1; iter++){
        f = fopen(argv[iter+1], "r");
        if (!f){
            printf("File doesn't exist");
            return -1;
        }
        
        //fscanf(f, "%d%d%d", &row, &col, &n);
       if ((fscanf(f, "%d%*1[\n]%d%*1[\n]%d%*1[\n]", &row, &col, &n) != 3)){
            printf("Error of data in the %s", argv[iter+1]);
            return -1;
        }
        assert (row > 0 && col > 0);


        double** matrix = (double**) malloc(sizeof(double*) * row);
        assert(matrix);
        for (int r = 0; r < row; r++){
            matrix[r] = (double*) calloc(sizeof(double), col);
            //assert(matrix[r]);
            if (!matrix[r]){
                // goto err;
                deleteMatrix(matrix, r);
                return -1;
            }
        }

        for (int i = 0; i < n; i++){
            int p = 0; //где определять?
            //fscanf(f, "%d%d%lf", &rowInd, &colInd, &elem); 
            if ((((p = fscanf(f, "%d %d %lf%c", &rowInd, &colInd, &elem, &buf)) == 4) && (buf == '\n')) || ((i == n-1) && (p == 3))){
                assert(rowInd < row && colInd < col);
                //matrix[rowInd][colInd] = elem;
                set_elem(matrix, rowInd, colInd, elem);
            } else {
                printf("Error of data in the %s", argv[iter+1]);
                deleteMatrix(matrix, row);
                return -1;
            }
        }

        printMatrix(matrix, row, col);
        printf(">>>%f\n", matrixNorm(matrix, row, col));

        fclose(f);
        deleteMatrix(matrix, row);
    }

    return 0;
    // mem_err:
    // //todo memory free
    // err:   
    // fclose(f);
    // return -1;
}
//if вместо assert
