/*
 * your program signature
 */ 

#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000
#define DICTIONARY_SIZE 2000

/**
 * Reads words from a file and stores them in a dictionary.
 * @param fp The file pointer to read from.
 * @param dictionary The array to store the dictionary words.
 * @return The number of words added to the dictionary.
 */
int create_dictionary(FILE *fp, char *dictionary) {
    char word[30];
    int count = 0;
    while (fscanf(fp, "%s", word) != EOF && count < DICTIONARY_SIZE) {
        strcpy(&dictionary[count * 30], word);  // Each word is stored in a fixed-size slot
        count++;
    }
    return count;
}

/**
 * Checks if a word exists in the dictionary.
 * @param dictionary The dictionary array.
 * @param word The word to search for.
 * @return TRUE if the word is found, FALSE otherwise.
 */
BOOLEAN contain_word(char *dictionary, char *word) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(&dictionary[i * 30], word) == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

/**
 * Processes words from a file, counts their frequency, and updates statistics.
 * @param fp The file pointer to read from.
 * @param words The array to store unique words and their counts.
 * @param dictionary The dictionary array for checking stop words.
 * @return A WORDSTATS structure containing line, word, and keyword counts.
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
    WORDSTATS stats = {0, 0, 0};
    char line[MAX_LINE_LEN];
    char *delimiters = " .,;\n\t\r";

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        stats.line_count++;
        char *token = strtok(line, delimiters);
        while (token != NULL) {
            stats.word_count++;
            if (!contain_word(dictionary, token)) {
                // Check if the word is already in the words array
                BOOLEAN found = FALSE;
                for (int i = 0; i < stats.keyword_count; i++) {
                    if (strcmp(words[i].word, token) == 0) {
                        words[i].count++;
                        found = TRUE;
                        break;
                    }
                }
                if (!found) {
                    strcpy(words[stats.keyword_count].word, token);
                    words[stats.keyword_count].count = 1;
                    stats.keyword_count++;
                }
            }
            token = strtok(NULL, delimiters);
        }
    }
    return stats;
}