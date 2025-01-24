/*
--------------------------------------------------
Project: fibonacci.c implementation
File:    fibonacci.c
Author:  Samuel Nworah 169060006
Version: 2025-01-22
--------------------------------------------------
 */ 

#include "fibonacci.h"

/**
 * Cmpute and return the nth Fibonacci number F(n) using recurisve algorithm, 
 *  namely using recursion function. 
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number 
 */
int recursive_fibonacci(int n) {
    int num = 0;

    //base case for if n is 0 or 1
    if (n == 0) {
        num = 0;
    } else if (n == 1) {
        num = 1;

    //recursive function
    } else {
        num = recursive_fibonacci(n - 2) + recursive_fibonacci(n - 1);
    }
    
    return num;

}

/**
 * Cmpute and return the nth Fibonacci number F(n) using iterative algorithm, 
 *  namely using a for or while loop. 
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number 
 */
int iterative_fibonacci(int n) {
    int num = 0;

    //base case checks if n is 0 or 1
    if (n == 0) {
        num = 0;
    } else if (n == 1) {
        num = 1;
    }

    //two previous numbers
    // both need to be added to get current
    //keep track of them
    int previous_num_1 = 0;
    int previous_num_2 = 1;

    //recursive step
    for (int i = 2; i <= n; i++) {
        num = previous_num_1 + previous_num_2;
        previous_num_1 = previous_num_2;
        previous_num_2 = num;
    }


    return num;

}

/**
 * Cmpute and return the nth Fibonacci number F(n) using dynamic programming 
 * bottom-up method with external array f[n+1] of initial value -1 for all elements. 
 * Namely it fills up f[] byf[0]=0, f[1]=1, a[i]= a[i-2]+a[i-1] for i=2,...,n, and 
 * return f[n]. 
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number 
 */
int dpbu_fibonacci(int *f, int n) {
    //point to index 0 and index 1
    //set these to the base cases
    *f = 0;
    *(f + 1) = 1;

    for (int i = 2; i < n + 1; i++) {
        *(f + i) = *(f + i - 2) + *(f + i - 1);
    }

    return *(f + n);

}

/**
 * Cmpute and return the nth Fibonacci number F(n) using dynamic programming 
 * top-down method with external array f[n+1] of initial value -1 for all elements. 
 * Namely it fills up f[n+1] by recursion function call. Specifically it returns 
 * f[n] if f[n]>0 else sets f[n] = dptd_fibonacci(f, n-2) + dptd_fibonacci(f, n-1) 
 * and then returns f[n] 
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number F(n).
 */
int dptd_fibonacci(int *f, int n) {
    //base case setting index 1 and 0 to their base values
    *f = 0;
    *(f + 1) = 1;

    if (n == 0) {
        *f = 0;
    } else if (n == 1) {
        *(f + 1) = 1;
    } else {
        *(f + n) = dptd_fibonacci(f, n-2) + dpbu_fibonacci(f, n-1);
    }

    return *(f + n);
}