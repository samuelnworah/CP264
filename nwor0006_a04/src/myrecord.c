/*
 * your program signature
 */ 
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#include "mysort.h"

GRADE grade(float score) {
    GRADE r;
    if (score >= 90) strcpy(r.letter_grade, "A+");
    else if (score >= 85) strcpy(r.letter_grade, "A");
    else if (score >= 80) strcpy(r.letter_grade, "A-");
    else if (score >= 75) strcpy(r.letter_grade, "B+");
    else if (score >= 70) strcpy(r.letter_grade, "B");
    else if (score >= 65) strcpy(r.letter_grade, "C+");
    else if (score >= 60) strcpy(r.letter_grade, "C");
    else if (score >= 55) strcpy(r.letter_grade, "D+");
    else if (score >= 50) strcpy(r.letter_grade, "D");
    else strcpy(r.letter_grade, "F");
    return r;
}


int import_data(FILE *fp, RECORD *dataset) {
    int i = 0;
    while (fscanf(fp, "%s %f", dataset[i].name, &dataset[i].score) == 2) {
        i++;
    }
    return i;
}

float median(RECORD dataset[], int n) {

    float **a = malloc(n * sizeof(float*));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;  // Return an error value if allocation fails
    }

    // Fill the pointer array with the addresses of the scores
    for (int i = 0; i < n; i++) {
        a[i] = &dataset[i].score;
    }

    // Sort the array of pointers
    select_sort((void*)a, 0, n - 1);

    float median_value;
    if (n % 2 == 0)
        median_value = (*a[n / 2 - 1] + *a[n / 2]) / 2.0;
    else
        median_value = *a[n / 2];

    // Free the allocated memory
    free(a);

    return median_value;
}


STATS process_data(RECORD *dataset, int count) {
    STATS stats = {count, 0, 0, 0};
    if (count == 0) return stats;

    float sum = 0, sum_sq = 0;
    for (int i = 0; i < count; i++) {
        sum += dataset[i].score;
        sum_sq += dataset[i].score * dataset[i].score;
    }

    stats.mean = sum / count;
    stats.stddev = sqrt((sum_sq / count) - (stats.mean * stats.mean));
    stats.median = median(dataset, count);

    return stats;
}


int cmp1(void *x, void *y) {
    float b = ((RECORD*)y)->score;
    float a = ((RECORD*)x)->score;
    return (a > b) ? -1 : (a < b) ? 1 : 0;
}

int report_data(FILE *fp, RECORD *dataset, STATS stats) {
    
    RECORD **p = malloc(stats.count * sizeof(RECORD*));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    for (int i = 0; i < stats.count; i++) {
        p[i] = &dataset[i];
    }

    my_sort((void*)p, 0, stats.count - 1, cmp1);

    for (int i = 0; i < stats.count; i++) {
        GRADE g = grade(p[i]->score);
        fprintf(fp, "%s %.2f %s\n", p[i]->name, p[i]->score, g.letter_grade);
    }

    fprintf(fp, "Statistics: Count = %d, Mean = %.2f, Stddev = %.2f, Median = %.2f\n",
            stats.count, stats.mean, stats.stddev, stats.median);

    // Free dynamically allocated memory
    free(p);
    return stats.count;
}