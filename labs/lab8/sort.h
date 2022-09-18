// Honor Code : On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
// Signed: 이경민, Student number: 22100487, Class: 02

#ifndef SORT_H
#define SORT_H

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

void bubblesort(int *list, int n, bool (*comp)(int, int) = ::less);
void insertionsort(int *list, int n, bool (*comp)(int, int) = ::less);
void mergesort(int *a, int N, bool (*comp)(int, int) = ::less);
void quicksort(int *a, int n, bool (*comp)(int, int) = ::less);
void selectionsort(int *list, int n, bool (*comp)(int, int) = ::less);

void printlist(int *list, int n, int show_n = 20, int per_line = 10);

#endif
