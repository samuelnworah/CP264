/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

/**
 * Reads and sums three comma-delimited integers on the same line from the keyboard.
 * Continues until a line of integers is correctly entered.
 * Prompt: "Enter three comma-separated integers: "
 * Error: "The integers were not properly entered.\n"
 *
 * @return - the sum of integers read from the keyboard
 */
int sum_three_integers(void) {

    int num1;
    int num2;
    int num3;
    int sum = 0;

    //use an infinite while loop to prompt user till 3 ints are inputed
    while(1) {
        //taking in 3 inputs
        printf("Enter three comma-seperated integers: ");
        int inputs = scanf("%d,%d,%d", &num1, &num2, &num3);

        //if it returns 3 then it has 3 valid user inputs
        //each valid int = 1 so 3 valid ints = 3
        if (inputs == 3) {
            sum = num1 + num2 + num3;
            break;

        //If user inputs only 1 or 2 valid ints but the last one isnt valid
        } else {
            printf("The integers were not properly entered.\n");
            while (getchar() != '\n');
        } 
    }
    return sum;
}
