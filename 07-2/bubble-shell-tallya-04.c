#include <stdio.h>

void shellSort(int * vet, int size);

int main(){
    int A[10] = {12,42,1,6,56,23,52,9,5,24};
    int i;

    shellSort(A, 10);

    printf("Vetor ordenado:\n");
    for(i=0; i<10; i++) printf("%d ", A[i]);
    printf("\n");

    return 0;
}

void shellSort(int * vet, int size){
    int i, j, num, h = 1;
    while (h < size){
        h = 3 * h + 1;
    }
    while (h > 0){
        for (i = h; i < size; i++){
            num = vet[i];
            j = i;
            while (j > h - 1 && num <= vet[j - h]){
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = num;
        }
        h = h / 3;
    }
}