#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

void add_matrix(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]);
void sub_matrix(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]);
void multiply_matrix(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]);
void element_wise_multiply(double a[SIZE][SIZE], double b[SIZE][SIZE], double result[SIZE][SIZE]);
void transpose_matrix(double a[SIZE][SIZE], double result[SIZE][SIZE]);
double determinant_matrix(double a[SIZE][SIZE]);
void adjoint_matrix(double a[SIZE][SIZE], double result[SIZE][SIZE]);
int inverse_matrix(double a[SIZE][SIZE], double result[SIZE][SIZE]);
void print_matrix(double matrix[SIZE][SIZE]);

#endif