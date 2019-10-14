#include "fonctions.c"


int main(){
	int ref[]  = {3,6,6,7,8,10,14,15,17,19,20,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,81,84,86,89,92,93,97,99};
	int tab1[] = {14,15,92,65,35,89,79,32,38,46,26,43,38,32,79,50,28,84,19,71,69,39,93,75,10,58,20,97,49,44,59,23,07,81,64,06,28,62,8,99,86,28,03,48,25,34,21,17,06,79};
	int tab2[] = {99,97,93,92,89,86,84,81,79,79,79,75,71,69,65,64,62,59,58,50,49,48,46,44,43,39,38,38,35,34,32,32,28,28,28,26,25,23,21,20,19,17,15,14,10,8,7,6,6,3};
	int tab3[] = {3,6,6,7,8,10,14,15,17,19,81,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,20,84,86,89,92,93,97,99};
	
	int n = sizeof(ref)/sizeof(int);
	///////Bubble Sort///////////////////
    /**
     * La complexité temporel global de cet algorithme est O(n²)
     * dans le pire des cas la compléxité est n² et dans le meilleurs des cas en O
     * L'algorithme est  adaptatif ?
     *L'algorithme a une complexité en place de n cet algorithme est stable
     */
    printf("Bubble Sort tab 1: operation counter = %d \t",bulle(tab1,n));///// O(n) 682 operation
    compare(ref,tab1,n);
    printf("Bubble Sort tab 2: operation counter = %d \t",bulle(tab2,n));////O(n²) 1216 operation
    compare(ref,tab2,n);
    printf("Bubble Sort tab 3: operation counter = %d \t",bulle(tab3,n));//////O(n) 63 opération
    compare(ref,tab3,n);
    printf("Bubble Sort tab ref: operation counter = %d \t",bulle(ref,n)); //// 0 operation
    compare(ref,ref,n);
    /////////////////////////////

    ///////////Insertion Sort////////////
    /**
     * La complexite de cet algorithme est O(n²) dans le pire des cas, et o() dans le meilleur des cas
     *
     * La complexite spacial  est de n, l'algorithme est stable en taille
     */
    printf("Insertion Sort tab1 : Operation Counter =  %d \t",insertionSort(tab1,n)); //// 691 operation
    compare(tab1,ref,n);
    printf("Insertion Sort tab2 : Operation Counter =  %d \t",insertionSort(tab2,n));////1225 operation
    compare(tab2,ref,n);
    printf("Insertion Sort tab3 : Operation Counter =  %d \t",insertionSort(tab3,n)); ////72 operation
    compare(tab3,ref,n);
    printf("Insertion Sort ref : Operation Counter =  %d \t",insertionSort(ref,n)); //// 0 opération
    compare(ref,ref,n);
    //////////////////////////////////////
    ///////////////////////////mergeSort///////////////////
    /**
     * la complexité temporel de cet algorithme est en log10(n) O(lg(n))
     * On remarque que le nombre d'opération  varie peux en fonction des different tableau au reste au alentour de 5n
     * la compléxité en taille de cet algorithme est de 2n
     */
    int *tmp;
    tmp =malloc(sizeof(ref));
    if( tmp== NULL)
        return  1;
    mergeSort(tab1,tmp,0,n-1,&conter);
    printf("MergeSort tab1 : counter = %d \t ",conter); //////counter = 259
    compare(tab1,ref,n);
    conter = 0;
    mergeSort(tab2,tmp,0,n-1,&conter);
    printf("MergeSort tab2 : counter = %d \t ",conter); ////counter = 286
    compare(tab2,ref,n);
    conter = 0;
    mergeSort(tab3,tmp,0,n-1,&conter);
    printf("MergeSort tab3 : counter = %d \t ",conter);////counter = 196
    compare(tab3,ref,n);
    conter = 0;
    printf("MergeSort ref : conter = %d \t ",conter);////counter = 0
    compare(ref,ref,n);
    /////////////////////////////////////
    free(tmp);
	return 0;


}


