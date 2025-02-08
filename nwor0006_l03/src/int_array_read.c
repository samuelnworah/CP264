/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

/**
 * Reads size integers from the keyboard into an array of int.
 * Continues until size valid integers are read.
 * Prompt: "Enter %d values for an array of int.\n"
 * Error: "Not a valid integer\n"
 *
 * @param array - pointer to an array of int.
 * @param size - number of values to be stored in array.
 */
void int_array_read(int *array, int size) {
    
    printf("Enter %d values for an array of int.\n", size);

    // Loop to read size integers
    for (int i = 0; i < size; i++) {
        // Try to read an integer
        int result = scanf("%d", &array[i]);

        if (result == 1) {
            // If input is valid, continue to the next index
        } else {
            // If input is invalid, display an error message
            printf("Not a valid integer\n");

            // Clear the input buffer
            while (getchar() != '\n');

            // Retry reading the current index
            i--;
        }
    }

}
