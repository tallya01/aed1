#include <stdio.h>
#include <stdlib.h>

int main(){
    int size, count;
    int * vet;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    vet = (int *) malloc(sizeof(int)*size);

    if(vet == NULL){
        printf("Não foi possível alocar a memória\n");
        return 0;
    }

    for(count=1; count<=size; count++){
        *vet = count;
        vet++;
    }

    vet -= size;

    //for(count=0; count<size; count++){
    //    printf("%d\n", vet[count]);
    //}

    free(vet);

    return 0;
}