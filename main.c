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
    printf("Bubble Sort tab 1: operation counter = %d \t",custom_bulle(tab1,n,&asc));///// O(n) 682 operation
    compare(ref,tab1,n);
    printf("Bubble Sort tab 2: operation counter = %d \t",custom_bulle(tab2,n,&asc));////O(n²) 1216 operation
    compare(ref,tab2,n);
    printf("Bubble Sort tab 3: operation counter = %d \t",custom_bulle(tab3,n,&asc));//////O(n) 63 opération
    compare(ref,tab3,n);
    printf("Bubble Sort tab ref: operation counter = %d \t",custom_bulle(ref,n,&asc)); //// 0 operation
    compare(ref,ref,n);
    /////////////////////////////



	return 0;
}


