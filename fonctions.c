#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


void affiche(int *a, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}


int compare(int *a, int *b, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            printf("Comparison FAILED at index %d\n\n", i);
            return i;
        }
    }
    printf("Comparison OK\n\n");
    return -1;
}


void swap(int *a, int *b) {
    int c;

    c = *a;
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
int insertionSort(int *table, int size) {

    int index;
    int index2;
    int varToSort;
    int nbaction = 0;
    for (index = 1; index < size; index++) {
        varToSort = *(table + index);
        index2 = index;
        nbaction++;
        while (index2 > 0 && varToSort < table[index2 - 1]) {// programme stable grâce à l'inégalité stricte.
            table[index2] = table[index2 - 1];
            index2--;
            nbaction++;
        }
        table[index2] = varToSort;
    }
    return nbaction;
}

int bulle(int *tab, int n) {
    int o = 0, i, l;
    int trie = 0;
    l = n;
    while (l > 0) {
        for (i = 0; i < l - 1; i++) {
            if (tab[i] > tab[i + 1]) { // programme stable grâce à l'inégalité stricte.
                swap(&tab[i], &tab[i + 1]);
                trie = 1;

            }
            o++;
        }
        if (!trie) //Si pas de swap pendant un tour de boucle alors le tableau est trié.
            return (o);
        trie = 0;
        l--;
    }
    return (o);
}

int asc(int a, int b) {
    return a > b;
}

int desc(int a, int b) {
    return b > a;
}

int custom_bulle(int *tab, int n, int (*fonction)(int, int)) {
    int o = 0, i, l;
    int trie = 0;
    l = n;
    while (l > 0) {
        for (i = 0; i < l - 1; i++) {
            if (fonction(tab[i], tab[i + 1])) {
                swap(&tab[i], &tab[i + 1]);
                trie = 1;
            }
            o++;
        }
        if (!trie) //Si pas de swap pendant un tour de boucle alors le tableau est trié.
            return (o);
        trie = 0;
        l--;
    }
    return (o);
}

void mergeSort(int *tab, int *tmp, int left, int right, int *cnt) {
    int mid;
    if (abs(left - right) > 0) { // do the condition if the table isn't a single tab
        mid = (left + right) / 2;
        mergeSort(tab, tmp, left, mid, cnt);
        mergeSort(tab, tmp, mid + 1, right, cnt);

        merge(tab, tmp, left, mid + 1, right, cnt);
    }
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

    }
}