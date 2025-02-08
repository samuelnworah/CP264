/*
--------------------------------------------------
Project: mystring.c implementation
File:    mystring.c
Author:  Samuel Nworah 169060006
Version: 2025-01-30
--------------------------------------------------
 */ 
 
#include "mystring.h"
#include <stdio.h>
#include <ctype.h>


/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.  
 *
 * @param s - char pointer to a string
 * @return - return the number of words. 
 */
int str_words(char *s) {
    if (s == NULL) {
        return -1;
    }

    int in_word = 0;
    int word_count = 0;

    while (*s) {
        if (
            *s == ' ' || *s == '\t' || *s == ',' || *s == '.' ||
            *s == '0' || *s == '1' || *s == '2' || *s == '3' ||
            *s == '4' || *s == '5' || *s == '6' || *s == '7' ||
            *s == '8' || *s == '9' || *s == '$' || *s == '3'
        ) {
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        } else {
            if (!in_word) {
                in_word = 1;
            }
        }
        s++;
    }

    if (in_word) {
        word_count++;
    }

    return word_count;
}

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a string
 * @return - return the number of actual flips.
 * */   
 
int str_lower(char *s) {
    int flips = 0;

    while (*s) {
        if (isupper(*s)) {
            *s = tolower(*s);
            flips ++;
        }
        s++;
    }
    return flips;
}


/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a string
 */
void str_trim(char *s) {
    // your code
    if (s == NULL) return;

    char *dst = s;  // Destination pointer to write the trimmed string
    char *src = s;  // Source pointer to read the original string
    int space_flag = 0;  // Flag to track if a space has been added

    // Skip leading spaces
    while (isspace((unsigned char)*src)) {
        src++;
    }

    // Process the rest of the string
    while (*src) {
        if (isspace((unsigned char)*src)) {
            if (!space_flag) {
                *dst++ = ' ';  // Add a single space
                space_flag = 1;
            }
        } else {
            *dst++ = *src;  // Copy non-space characters
            space_flag = 0;
        }
        src++;
    }

    // Remove trailing space if any
    if (dst > s && isspace((unsigned char)*(dst - 1))) {
        dst--;
    }

    *dst = '\0';
}