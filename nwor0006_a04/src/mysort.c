/*
 * your program signature
 */ 

#include "mysort.h"

// swap pointers
void swap(void **x, void **y) {
     void *temp = *y;
     *y = *x;
     *x = temp;
}

// a compare floating values pointed by void pointers. 
int cmp(void *x, void *y) {
   float a = *(float*)x;
   float b = *(float*)y; 
     if (a > b) return 1;
     else if (a < b) return -1;
     else return 0;
}   

void select_sort(void *a[], int left, int right) {
    for (int i = left; i < right; i++) {
        int min_index = i;
        for (int j = i + 1; j <= right; j++) {
            if (cmp(a[j], a[min_index]) < 0) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(&a[i], &a[min_index]);
        }
    }
}

int partition(void *a[], int left, int right) {
    void *pivot = a[right];
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        if (cmp(a[j], pivot) < 0) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[right]);
    return i + 1;
}

void quick_sort(void *a[], int left, int right) {
    if (left < right) {
        int pivot_index = partition(a, left, right);
        quick_sort(a, left, pivot_index - 1);
        quick_sort(a, pivot_index + 1, right);
    }
}

void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*)) {
    for (int i = left; i < right; i++) {
        int min_index = i;
        for (int j = i + 1; j <= right; j++) {
            if (cmp(a[j], a[min_index]) < 0) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(&a[i], &a[min_index]);
        }
    }
}