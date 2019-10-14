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
void merge(int *tab, int *tmp, int left, int mid, int right, int *cnt) {
    int indexTab1 = left, indexTab2 = mid;
    int indextmp = left;
    int nbModify = 0;
    /*
     * decompose a main table with index right mid and left mid  is the 1st element of right table
     * compare each element in a logic order, between the two tab , when one is higher it's placed in the temp table and is counter of the
     * of this table is incremented
     */
    if (tab[mid - 1] < tab[mid]) { // compare the last element of the first table and the first of the second table , as they are already sort we can abort the merge turn
        (*cnt)++;
        return;
    }
    while (indexTab1 < mid && indexTab2 <= right) {
        if (tab[indexTab1] < tab[indexTab2]) {
            tmp[indextmp] = tab[indexTab1];
            indexTab1++;
        } else {
            tmp[indextmp] = tab[indexTab2];
            indexTab2++;
        }
        (*cnt)++;
        nbModify++;
        indextmp++;
    }
    while (indexTab1 < mid)//  if it have element in the right table  copy them at the end of the tmp table
    {
        tmp[indextmp++] = tab[indexTab1++];
        (*cnt)++;
        nbModify++;
    }

    //copy the tmp table into the main table
    for (indextmp = left; indextmp < nbModify + left; indextmp++) {
        tab[indextmp] = tmp[indextmp];
        (*cnt)++;
    }
}

void mergeSort (int* tab,int* tmp, int left, int right,int* cnt){
    int mid;
    if(abs(left - right) >0) { // do the condition if the table isn't a single tab
        mid = (left+right)/2;
        mergeSort(tab, tmp, left, mid, cnt);
        mergeSort(tab, tmp, mid+1, right, cnt);

        merge(tab, tmp, left, mid+1, right, cnt);
    }
}
