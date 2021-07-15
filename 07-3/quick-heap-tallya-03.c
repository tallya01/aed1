#include <stdio.h>
#include <string.h>

#define LINES 10
#define COLS 31

void quickSortNames(char vet[LINES][COLS], int begin, int size);

int main(){
    char vet[LINES][COLS] = {"Juliana", "Adriele", "Bruno", "Davi", "Maria", "Luciana", "Ana", "Lucas", "Elena", "Giovana"};

    quickSortNames(vet, 0, LINES);

    for(int i=0; i<LINES; i++) printf("%s\n", vet[i]);

    return 0;
}

void quickSortNames(char vet[LINES][COLS], int begin, int size){
    int i, j;
    char aux[COLS], pivo[COLS];
    i = begin;
    j = size-1;
    strcpy(pivo, vet[(begin+size)/2]);

    while(i<=j){
        while(strcmp(vet[i], pivo)<0 && i<size) i++;
        while(strcmp(vet[j], pivo)>0 && j>begin) j--;

        if(i<=j){
            strcpy(aux, vet[i]);
            strcpy(vet[i], vet[j]);
            strcpy(vet[j], aux);
            i++;
            j--;
        }
    }

    if(j>begin) quickSortNames(vet, begin, j+1);
    if(i<size) quickSortNames(vet, i, size); 
}