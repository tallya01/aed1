#include <stdio.h>
#include <stdlib.h>

void read_vet(int size, float * vet);
void print_vet(int size, float * vet);

int main(){
    int count;
    int size;

    for(count=0;count<5;count++){
        float * vet;

        printf("Digite o tamanho do %dº vetor: ", count+1);
        scanf("%d", &size);

        vet = malloc(sizeof(float)*size);
        read_vet(size, vet);
        print_vet(size, vet);

        free(vet);
    }

    return 0;
}

void read_vet(int size, float * vet){
    int count;

    printf("Digite os %d elementos do vetor:\n", size);
    for(count=0;count<size;count++){
        scanf("%f", &vet[count]);
    }
}

void print_vet(int size, float * vet){
    int count;

    printf("Os %d elementos do vetor são:\n", size);
    for(count=0;count<size;count++){
        printf("%.2f ", vet[count]);
    }
    printf("\n");
}