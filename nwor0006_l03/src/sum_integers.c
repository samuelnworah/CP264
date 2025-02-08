/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author Samuel Nworah 169060006
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

/**
 * Reads and sums a series of integers read one at a time from the keyboard.
 * Stop reading when a non-integer is entered.
 * Prompt: "Enter integers, one per line: "
 *
 * @return - the sum of integers read from the keyboard
 */
int sum_integers(void) {
    int sum = 0; //what we ad the user input to
    int input; //user input

    //start an infinite loop only broken out of if input is invalid
    while (1) {

        //user prompt
        printf("Enter integers, one per line: ");

        //scanf returns 1 if user input is vlaid and 0 otherwise
        int valid = scanf("%d", &input);

        //if its 1 then the input is valid so it adds
        if (valid == 1){
            sum += input;

        //if its 0 then the input is invalid so it breaks out of the loop
        } else {
            break;
        }
    }
    return sum;
}