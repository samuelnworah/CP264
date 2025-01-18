/*
--------------------------------------------------
Project: powersum.c implementation
File:    powersum.c
Author:  Samuel Nworah 169060006
Version: 2025-01-09
--------------------------------------------------
*/
#include "powersum.h"

/**
 * Depect if overflow in power computing of b to power of n  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - 1 if overflow happens, 0 otherwise
 */
int power_overflow(int b, int n)
{
int answer = 1;

for (int i = 0; i < n; i++ ) {
    answer *= b;
}
if (answer > 0) {
    answer = 0;
} else {
    answer = 1;
}
return answer;
}

/**
 * Compute and return b to power of n.  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - b to the power of n if no overflow happens, 0 otherwise
 */
int mypower(int b, int n)
{
int answer = 1;

for (int i = 0; i < n; i++ ) {
    answer *= b;
}

if (answer > 0) {
    return answer;
} else {
    return 0;
}


}

/**
 * Compute and return the sum of powers.
 *
 * @param b - the base
 * @param n - the exponent
 * @return -  the sum of powers if no overflow happens, 0 otherwise 
 */
int powersum(int b, int n)
{
int sum = 0;
    int current_power = 1;

    for (int i = 1; i <= n; i++) {
        // Compute b^i while checking for overflow
        int temp = current_power * b;
        if (b != 0 && temp / b != current_power) {
            return 0; // Overflow occurred
        }
        current_power = temp;

        // Check if adding current_power causes overflow
        if (sum + current_power < sum) {
            return 0; // Overflow occurred
        }
        sum += current_power;
    }

    return sum;
}