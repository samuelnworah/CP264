/*
--------------------------------------------------
Project: quadratic.c implementation
File:    quadratic.c
Author:  Samuel Nworah 169060006
Version: 2025-01-09
--------------------------------------------------
*/
#include "quadratic.h"
#include <math.h>
#define EPSILON 1e-6

int solution_type(float a, float b, float c)
{
    int t = -1;
    
    if (fabs(a) < EPSILON) // If a == 0, it's not a quadratic equation.
        t = 0;
    else
    {
        // Calculate the discriminant D = b^2 - 4ac
        float D = b * b - 4 * a * c;

        if (D > EPSILON) // Two distinct real roots.
            t = 2;
        else if (fabs(D) < EPSILON) // One real root (repeated).
            t = 1;
        else // Complex roots (D < 0).
            t = 3;
    }

    return t;
}

float real_root_big(float a, float b, float c)
{
    // Call solution_type to determine the solution type
    int sol_type = solution_type(a, b, c);

    if (sol_type == 0 || sol_type == 3) // Not quadratic or complex roots.
        return 0.0f;

    // If the solution type is 1 or 2 (real solutions), calculate the bigger root.
    float D = b * b - 4 * a * c;
    if (sol_type == 1) {
        return -b / (2 * a); // Only one root.
    } else if (sol_type == 2) {
        // Two distinct real roots, return the bigger one.
        float sqrtD = sqrt(D);
        return (-b + sqrtD) / (2 * a); // Bigger root.
    }

    return 0.0f; // In case no real solution.
}

float real_root_small(float a, float b, float c)
{
    // Call solution_type to determine the solution type
    int sol_type = solution_type(a, b, c);

    if (sol_type == 0 || sol_type == 3) // Not quadratic or complex roots.
        return 0.0f;

    // If the solution type is 1 or 2 (real solutions), calculate the smaller root.
    float D = b * b - 4 * a * c;
    if (sol_type == 1) {
        return -b / (2 * a); // Only one root.
    } else if (sol_type == 2) {
        // Two distinct real roots, return the smaller one.
        float sqrtD = sqrt(D);
        return (-b - sqrtD) / (2 * a); // Smaller root.
    }

    return 0.0f; // In case no real solution.
}
