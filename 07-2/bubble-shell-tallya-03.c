#include <stdio.h>
#include <stdlib.h>

int aux = 0;

void recursiveBubbleSort(int * vet, int size);

int main(){
    int size, * vet, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);
    
    vet = malloc(size*sizeof(int));

    printf("Digite os %d elementos do vetor:\n", size);
    for(i=0;i<size;i++) scanf("%d", &vet[i]);

    recursiveBubbleSort(vet, size);

    printf("Vetor ordenado:\n");
    for(i=0;i<size;i++) printf("%d ", vet[i]);
    printf("\n");

    free(vet);

    return 0;
}

void recursiveBubbleSort(int * vet, int size){
    if (size == 1) return;

    for (int i=0; i<size-1; i++)
        if (vet[i] > vet[i+1]){
            aux=vet[i];
            vet[i]=vet[i+1];
            vet[i+1]=aux;
        }
        
    recursiveBubbleSort(vet, size-1);
}