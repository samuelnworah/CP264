/*
--------------------------------------------------
Project: polynomial.c implementation
File:    polynomial.c
Author:  Samuel Nworah 169060006
Version: 2025-01-22
--------------------------------------------------
 */ 
#include <math.h>
#include <stdio.h>
#include "polynomial.h"
#define EPSILON 1e-6
#define MAXCOUNT 100

/**
 * Cmpute and return the value of the (n-1)-th degree polynomial
 * p(x) = p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0
 * using Horner's algorithm (https://en.wikipedia.org/wiki/Horner%27s_method)
 *
 * @param *p - pointer to float number array
 * @param n  - the number of coefficients   
 * @return - the value of the above polynomial 
 */
float horner(float *p, int n, float x) {

    float polynomial = p[0];

    for (int i = n - 1; i < n; i++) {
        polynomial = polynomial * x + p[i];
    }

    return polynomial;

}

float myfabs(float x) {
    return (x < 0) ? -x : x;
}

// Compute the derivative of the polynomial
void derivative(float *p, float *d, int n) {
    for (int i = 0; i < n - 1; i++) {
        d[i] = (n - 1 - i) * p[i];
    }
}

// Compute the approximate real root of the polynomial using Newton's method
float newton(float *p, int n, float x0) {
    float d[n - 1];  // Array to store the derivative coefficients
    derivative(p, d, n);  // Calculate the derivative

    float tolerance = 1e-6;
    int max_iterations = 100;

    for (int i = 0; i < max_iterations; i++) {
        // Evaluate p(x0)
        float px = 0;
        for (int j = 0; j < n; j++) {
            px += p[j] * powf(x0, n - 1 - j);
        }

        // Evaluate p'(x0)
        float px_prime = 0;
        for (int j = 0; j < n - 1; j++) {
            px_prime += d[j] * powf(x0, n - 2 - j);
        }

        // Avoid division by zero
        if (myfabs(px_prime) < tolerance) {
            return x0;
        }

        // Newton's method step
        float x1 = x0 - px / px_prime;

        // Check for convergence
        if (myfabs(x1 - x0) < tolerance) {
            return x1;
        }

        x0 = x1;  // Update x0 for the next iteration
    }

    // If maximum iterations are reached, return the last x0
    return x0;
}