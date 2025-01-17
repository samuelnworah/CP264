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

//If character is an arithmethic operator
 if (c == '*' || c == '+' || c == '-' || c == '/') {
  character = 1;
 }

 //If character is a left parenthesis
 if (c == '(') {
  character = 2;
 }

 //If character is a right parenthesis
 if (c == ')') {
  character = 3;
 }

 //If character is an upper case english letter
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
    character = 4;
  }
  
   return character;
}


/**
 * Flip the case of an English character.
 *
 * @param c - char type
 * @return -  c's upper/lower case letter if c is a lower/upper case English letter.
 */
char case_flip(char c) {
 if (c >= 65 && c <= 90) {
  c += 32;
 } else if (c >= 97 && c <= 122) {
  c -= 32;
 }

 return c;
}

/**
 * Convert digit character to the corresponding integer value.
 *
 * @param c - char type value
 * @return - its corresponding integer value if c is a digit character;
 *           otherwise -1.
 */
int digit_to_int(char c) {
 
 if (c >= '0' && c <= '9') {
  return c - '0';
 } else {
  return -1;
 }

}