/*
--------------------------------------------------
Project: mychar interface
File:    mychar.h
Author:  Samuel Nworah 169060006
Version: 2025-01-09
--------------------------------------------------
*/ 
#ifndef MYCHAR_H
#define MYCHAR_H

#include <stdio.h>

/**
 Determine the type of a char character
*/
int mytype(char c);

/**
 Flip the case of an english character
*/
char case_flip(char c);

/**
 Convert digit character to the corresponding integer value.
*/
int digit_to_int(char c);

#endif