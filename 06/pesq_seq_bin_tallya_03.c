#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void sequential_search(int vet[SIZE], int num);
void binary_search(int vet[SIZE], int num);

int main(){
    int vet[SIZE] = {6,15,29,29,29,44,61,70,70,92};

    sequential_search(vet, 6);
    binary_search(vet, 6);
    sequential_search(vet, 29);
    binary_search(vet, 29);
    sequential_search(vet, 35);
    binary_search(vet, 35);
    sequential_search(vet, 61);
    binary_search(vet, 61);
    sequential_search(vet, 70);
    binary_search(vet, 70);

    return 0;
}

void sequential_search(int vet[SIZE], int num){
    int i, j = 0;
    int * seq_pos;

    for(i=0; i<SIZE; i++){
        if(vet[i]==num){
            if(j==0){
                seq_pos = (int *) malloc(sizeof(int));
                seq_pos[j] = i;
                j++;
            }
            else{
                seq_pos = realloc(seq_pos, sizeof(int)*(j+1));
                seq_pos[j] = i;
                j++;
            }
        }
    }

    if(j==0) printf("Valor %d não encontrado no vetor com busca sequencial\n", num);
    else{
        printf("Valor %d encontrado com busca sequencial na(s) posição(ões): ", num);
        for(int k=0; k<j; k++) printf("%d ", seq_pos[k]);
        printf("\n");
    }

    free(seq_pos);
}

void binary_search(int vet[SIZE], int num){
    int index, begin, end, j=0, aux;
    int * bin_pos;

    begin = 0;
    end = SIZE - 1;

    while(begin<=end){
        index = begin + (end - begin) / 2;
        if(vet[index] == num){
            bin_pos = (int *) malloc(sizeof(int));
            bin_pos[j] = index;
            j++;

            aux=index-1;
            while(vet[aux] == num && aux>=0){
                bin_pos = realloc(bin_pos, sizeof(int)*(j+1));
                bin_pos[j] = aux;
                j++;
                aux--;
            }

            aux=index+1;
            while(vet[aux] == num && aux<SIZE){
                bin_pos = realloc(bin_pos, sizeof(int)*(j+1));
                bin_pos[j] = aux;
                j++;
                aux++;
            }

            break;
        } 
        else if(vet[index]<num) begin = index + 1;
        else end = index - 1;
    }
    if(j==0) printf("Valor %d não encontrado no vetor com busca binária\n", num);
    else{
        printf("Valor %d encontrado com busca binária na(s) posição(ões): ", num);
        for(int k=0; k<j; k++) printf("%d ", bin_pos[k]);
        printf("\n");
    }

    free(bin_pos);
}