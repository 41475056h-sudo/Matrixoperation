#include <stdio.h>
#include "matrix_op.h"

void add_matrix(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void sub_matrix(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiply_matrix(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void element_wise_multiply(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] * b[i][j];
        }
    }
}

void transpose_matrix(double a[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = a[i][j];
        }
    }
}

double determinant_matrix(double a[SIZE][SIZE]) {
    double det = 0;
    det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
          a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
          a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
    return det;
}

void adjoint_matrix(double a[SIZE][SIZE], double result[SIZE][SIZE]) {
    result[0][0] =  (a[1][1] * a[2][2] - a[1][2] * a[2][1]);
    result[0][1] = -(a[0][1] * a[2][2] - a[0][2] * a[2][1]);
    result[0][2] =  (a[0][1] * a[1][2] - a[0][2] * a[1][1]);

    result[1][0] = -(a[1][0] * a[2][2] - a[1][2] * a[2][0]);
    result[1][1] =  (a[0][0] * a[2][2] - a[0][2] * a[2][0]);
    result[1][2] = -(a[0][0] * a[1][2] - a[0][2] * a[1][0]);

    result[2][0] =  (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
    result[2][1] = -(a[0][0] * a[2][1] - a[0][1] * a[2][0]);
    result[2][2] =  (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
}

int inverse_matrix(double a[SIZE][SIZE], double result[SIZE][SIZE]) {
    double det = determinant_matrix(a);
    if (det == 0) {
        return 0;
    }

    double adj[SIZE][SIZE];
    adjoint_matrix(a, adj);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = adj[i][j] / det;
        }
    }
    return 1;
}

void print_matrix(double matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("[ ");
        for (int j = 0; j < SIZE; j++) {
            printf("%8.3f ", matrix[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}