#include "fonctions.c"


int main(){
	int ref[]  = {3,6,6,7,8,10,14,15,17,19,20,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,81,84,86,89,92,93,97,99};
	int tab1[] = {14,15,92,65,35,89,79,32,38,46,26,43,38,32,79,50,28,84,19,71,69,39,93,75,10,58,20,97,49,44,59,23,07,81,64,06,28,62,8,99,86,28,03,48,25,34,21,17,06,79};
	int tab2[] = {99,97,93,92,89,86,84,81,79,79,79,75,71,69,65,64,62,59,58,50,49,48,46,44,43,39,38,38,35,34,32,32,28,28,28,26,25,23,21,20,19,17,15,14,10,8,7,6,6,3};
	int tab3[] = {3,6,6,7,8,10,14,15,17,19,81,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,20,84,86,89,92,93,97,99};

	int conter=0;

    int n = sizeof(ref)/sizeof(int);
    int *tmp;
    tmp =malloc(sizeof(ref));
    if( tmp== NULL)
        return  1;

    ///////////////////////////mergeSort///////////////////
    /**
     * la complexité temporel de cet algorithme est en log10(n) O(lg(n))
     * On remarque que le nombre d'opération  varie peux en fonction des different tableau au reste au alentour de 5n
     * la compléxité en taille de cet algorithme est de 2n
     */
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


