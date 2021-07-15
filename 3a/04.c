#include <stdio.h>
#include <stdlib.h>

int biggestValue(int * vet, int sizeM1);

int main(){
    int size, count;
    int * vet;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    vet = malloc(sizeof(int)*size);

    printf("Digite os %d elementos do vetor: ", size);
    for(count=0;count<size;count++) scanf("%d", &vet[count]);

    printf("O maior valor encontrado no vetor é %d\n", biggestValue(vet, size-1));

    free(vet);

    return 0;
}

int biggestValue(int * vet, int sizeM1){
    int count, flag=0;

    /*
    *compara cada valor (começando do último) com cada um
    *dos valores anteriores. Se o valor for menor que qualquer
    *um dos outros, já se sabe que não é o maior do vetor.
    *Então a função é chamada novamente para comparar o elemento
    *anterior com os anteriores a ele.
    */
    for(count=0;count<sizeM1;count++){
        if(vet[sizeM1]<vet[count]) flag=1;
    }
    if(flag==0) return vet[sizeM1];
    else biggestValue(vet, sizeM1-1);
}