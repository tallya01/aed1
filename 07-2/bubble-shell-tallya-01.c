#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int * vet, int size);

int main(){
    int size, * vet, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);
    
    vet = malloc(size*sizeof(int));

    printf("Digite os %d elementos do vetor:\n", size);
    for(i=0;i<size;i++) scanf("%d", &vet[i]);

    bubbleSort(vet, size);

    printf("Vetor ordenado:\n");
    for(i=0;i<size;i++) printf("%d ", vet[i]);
    printf("\n");

    free(vet);

    return 0;
}

void bubbleSort(int * vet, int size){
    int k, j, aux, comp = 0, flag;

    for (k = size - 1; k > 0; k--){
        comp++;
        flag = 0;
        for (j = 0; j < k; j++){
            comp++;
            if (vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
                flag = 1;
            }
        }
        if(flag==0) break;
    }
    printf("Bubble Sort - Comparacoes realizadas...: %d\n", comp);
}