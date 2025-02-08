/*
 * your program signature
 */ 
#ifndef MYWORD_H
#define MYWORD_H

#include <stdio.h>

typedef enum boolean {
    FALSE = 0,
    TRUE = 1
} BOOLEAN;

typedef struct word {
    char word[30];  // Assuming a maximum word length of 29 characters
    int count;      // Frequency of the word
} WORD;

typedef struct wordstats {
    int line_count;     // Total number of lines processed
    int word_count;     // Total number of words processed
    int keyword_count;  // Total number of unique keywords processed
} WORDSTATS;

int create_dictionary(FILE *fp, char *dictionary);

BOOLEAN contain_word(char *dictionary, char *word);

WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary);

#endif