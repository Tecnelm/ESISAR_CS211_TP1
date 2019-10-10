#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"




void affiche(int* a, int n){
	int i;
	for (i = 0 ; i < n ; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
}


int compare(int* a, int *b, int n){
	int i;
	for(i=0; i < n ; i++){
		if (a[i] != b[i]){
			printf("Comparison FAILED at index %d\n\n", i);
			return i;
		}
	}
	printf("Comparison OK\n\n");
	return -1;	
}




void swap(int* a, int* b) {
    int c;
    int n;
    c = *a;
    *a = *b;
    *b = c;
}
int bulle(int* tab, int n) {
    int o, i,l;
    l = n;
    while (l > 0) {
        for (i = 0; i < l; i++) {
            swap(&tab[i], &tab[i + 1]);
            l--;
            o++;
        }
    }
    return(o);
}


