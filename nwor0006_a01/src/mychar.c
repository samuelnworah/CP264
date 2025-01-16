/*
--------------------------------------------------
Project: mychar.c implementation
File:    mychar.c
Author:  Samuel Nworah 169060006
Version: 2025-01-09
--------------------------------------------------
*/ 
#include "mychar.h"

/**
 * Determine the type of a char character.
 *
 * @param c - char type
 * @return - 0 if c is a digit 
             1 if c is an arithmetic operator
             2 if c is the left parenthsis (
             3 if c is the right parenthsis )
             4 if c is an English letter; 
             otherwise -1.
 */
int mytype(char c) {
 int character = -1;

//If character is a digit
 if (c >= '0' && c <= '9') {
  character = 0;
 }

//If character is an english letter
  if (c >= 'a' && c <= 'z') {
    character = 4;
  }
}

/**
 * Flip the case of an English character.
 *
 * @param c - char type
 * @return -  c's upper/lower case letter if c is a lower/upper case English letter.
 */
char case_flip(char c) {
 // your code
}

/**
 * Convert digit character to the corresponding integer value.
 *
 * @param c - char type value
 * @return - its corresponding integer value if c is a digit character;
 *           otherwise -1.
 */
int digit_to_int(char c) {
 // your code
}