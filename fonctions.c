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
void swap(int* a, int* b)
{
int c = *a;
*a = *b;
*b = c;
}

/**
 *
 * on décompose la tableau en deux sous tableau la partie trié et la non trier
 * on prend le premier élément du tableau non trié puis on parcours le tableau trié pour le mettre à la bonne position
 * @param table  : tableau de valeur a trier
 * @param size  : taille du tableai
 * @return      : nombre d'opération réalisé
 */
int insertionSort(int* table,int size)
{

    int index;
    int index2;
    int varToSort;
    int nbaction =0;
    for (index = 1 ; index < size ; index++ ) {
        varToSort = *(table + index);
        index2 = index;
        nbaction++;
        while(index2 >0 && varToSort < table[index2 -1])
        {
            table[index2] = table[index2-1];
            index2 --;
            nbaction++;
        }
        table[index2] = varToSort;
    }
    return nbaction;
}



