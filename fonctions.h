#include <stdio.h>


void swap(int* a, int* b);
int compare(int* a, int *b, int n);
void affiche(int* a, int n);
void merge (int* tab, int* tmp, int left, int mid, int right, int* cnt);
void mergeSort (int* tab,int* tmp, int left, int right, int* cnt);

int bulle(int* tab, int n);
int insertionSort(int* table,int size);
int custom_bulle(int *tab, int n,int (*fonction)(int,int));
int asc(int a,int b);
int desc(int a ,int b);




