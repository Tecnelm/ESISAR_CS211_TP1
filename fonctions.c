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
void merge (int* tab, int* tmp, int left, int mid, int right, int* cnt){
    int indexTab1 = left , indexTab2 = mid;
    int indextmp = left;
    int nbModify=0;

    while (indexTab1 < mid && indexTab2 <right)
    {
        if(tab[indexTab1]< tab[indexTab2])
        {
            tmp[indextmp] = tab[indexTab1];
            indexTab1++;

        }
        else
        {
            tmp[indextmp] = tab[indexTab2];
            indexTab2++;
        }
        nbModify++;

        indextmp++;
    }
    int i;
    for(i = 0; i < nbModify ; i++ )
    {
        tab[i +left] = tmp[left + i];
        *cnt ++ ;
    }
}


