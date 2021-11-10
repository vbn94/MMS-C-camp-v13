#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define N 10
#define M 4

int** scalarMult(int** A, size_t n, size_t m, int num){
    int** R = malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++){
        R[i] = malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            R[i][j] = num * A[i][j]; 
        }
    }
    return R;
}

int** addMatrix(int** A, int** B, size_t n, size_t m){
    int** R = malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++){
        R[i] = malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            R[i][j] = A[i][j] + B[i][j]; 
        }
    }
    return R;
}


int main(){
    int i, j;
    int** matrix = malloc(N * sizeof(int*));

    for (i = 0; i < N; i++){
        *(matrix + i) = malloc(M * sizeof(int));
    }

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            *(*(matrix+i)+j) = rand() % 10; // matrix[i][j] = 
        }
    }

    int** matrix2 = malloc(N * sizeof(int*));

    for (i = 0; i < N; i++){
        *(matrix2 + i) = malloc(M * sizeof(int));
    }

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            *(*(matrix2+i)+j) = rand() % 10;
        }
    }

    int** matrix3 = addMatrix(matrix, matrix2, N, M);

    for (int i = 0; i < N; i++){
        free(matrix3[i]);
    }
    free(matrix3);

    int arr[10];
    printf("%p \n", arr);
    printf("%p \n", &arr);
    return EXIT_SUCCESS;
}