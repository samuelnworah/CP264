/*
 * your program signature
 */ 
 

#include "matrix.h"

#include <math.h>

/**
 * Compute the norm (magnitude) of a vector.
 * Norm = sqrt(v[0]^2 + v[1]^2 + ... + v[n-1]^2)
 *
 * @param *v - pointer to the vector
 * @param n  - size of the vector
 * @return - the norm of the vector
 */
float norm(float *v, int n) {
    float sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += v[i] * v[i];  // Square each element and add to sum
    }

    return sqrtf(sum);  // Return the square root of the sum
}

/**
 * Compute the dot product of two vectors.
 * Dot product = v1[0]*v2[0] + v1[1]*v2[1] + ... + v1[n-1]*v2[n-1]
 *
 * @param *v1 - pointer to the first vector
 * @param *v2 - pointer to the second vector
 * @param n   - size of the vectors
 * @return - the dot product of v1 and v2
 */
float dot_product(float *v1, float *v2, int n) {
    float result = 0.0;

    for (int i = 0; i < n; i++) {
        result += v1[i] * v2[i];  // Multiply corresponding elements and sum
    }

    return result;
}

/**
 * Multiply an n x n matrix with a vector.
 * Result: vout = m * vin
 *
 * @param *m   - pointer to the matrix (stored row-major)
 * @param *vin - pointer to the input vector
 * @param *vout - pointer to the output vector
 * @param n    - size of the matrix and vector
 */
void matrix_multiply_vector(float *m, float *vin, float *vout, int n) {
    for (int i = 0; i < n; i++) {
        vout[i] = 0.0;  // Initialize the output vector element
        for (int j = 0; j < n; j++) {
            vout[i] += m[i * n + j] * vin[j];  // Multiply row of matrix with vector
        }
    }
}

/**
 * Multiply two n x n matrices.
 * Result: m3 = m1 * m2
 *
 * @param *m1 - pointer to the first matrix (row-major order)
 * @param *m2 - pointer to the second matrix (row-major order)
 * @param *m3 - pointer to the output matrix (row-major order)
 * @param n   - size of the matrices
 */
void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m3[i * n + j] = 0.0;  // Initialize each element of the output matrix
            for (int k = 0; k < n; k++) {
                m3[i * n + j] += m1[i * n + k] * m2[k * n + j];  // Dot product of row i of m1 and column j of m2
            }
        }
    }
}
