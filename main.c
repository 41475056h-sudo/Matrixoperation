#include <stdio.h>
#include "matrix_op.h"

int main() {
    double A[SIZE][SIZE] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    double B[SIZE][SIZE] = {
        {-1, 2, 0},
        {5, -3, 2},
        {1, 0, 1}
    };

    double result[SIZE][SIZE];
    double det;

    printf("--- Basic Operations ---\n");
    printf("Matrix A + B:\n");
    add_matrix(A, B, result);
    print_matrix(result);

    printf("Matrix A - B:\n");
    sub_matrix(A, B, result);
    print_matrix(result);

    printf("Element-wise Multiply:\n");
    element_wise_multiply(A, B, result);
    print_matrix(result);

    printf("--- Linear Operations ---\n");
    printf("Matrix A * B:\n");
    multiply_matrix(A, B, result);
    print_matrix(result);

    printf("Transpose of A:\n");
    transpose_matrix(A, result);
    print_matrix(result);

    printf("--- Advanced Operations ---\n");
    det = determinant_matrix(A);
    printf("Determinant of A: %.3f\n\n", det);

    printf("Adjoint of A:\n");
    adjoint_matrix(A, result);
    print_matrix(result);

    printf("Inverse of A:\n");
    if (inverse_matrix(A, result)) {
        print_matrix(result);
        
        // Check: A * Inverse should be Identity
        printf("Check (A * Inverse):\n");
        double identity[SIZE][SIZE];
        multiply_matrix(A, result, identity);
        print_matrix(identity);
    } else {
        printf("Matrix is singular, inverse does not exist.\n");
    }

    return 0;
}