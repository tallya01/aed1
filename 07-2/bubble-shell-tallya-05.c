#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int * vet, int size);

int main(){
    int vet[100];
    int i;

    srand(time(NULL));
    
    for(i=0; i<100; i++){
        vet[i] = rand() % 501; //valores entre 0 e 501
    }

    shellSort(vet, 100);

    printf("Vetor ordenado:\n");
    for(i=0; i<100; i++) printf("%d ", vet[i]);
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
            while (j > h - 1 && num >= vet[j - h]){
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = num;
        }
        h = h / 3;
    }
}