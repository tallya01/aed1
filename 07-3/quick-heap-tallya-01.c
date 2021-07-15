#include <stdio.h>

#define SIZE 8

int size2 = SIZE;

void quickSort(int * vet, int begin, int size);

int main(){
    int vet[SIZE] = {5,13,7,20,12,9,1,4};

    quickSort(vet, 0, SIZE);

    return 0;
}

void quickSort(int * vet, int begin, int size){
    int i, j, aux, pivo;
    i = begin;
    j = size-1;
    pivo = vet[(begin+size)/2];

    while(i<=j){
        while(vet[i]<pivo && i<size) i++;
        while(vet[j]>pivo && j>begin) j--;

        if(i<=j){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }
    for(int k=0; k<size2; k++) printf("%d ", vet[k]);
    printf("\n");

    if(j>begin) quickSort(vet, begin, j+1);
    if(i<size) quickSort(vet, i, size); 
}