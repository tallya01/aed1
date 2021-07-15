#include <stdio.h>

#define SIZE 8

int sequential_search(int vet[SIZE], int num);
int binary_search(int vet[SIZE], int num);
void search_and_print_info(int vet[SIZE], int num);

int main(){
    int vet[SIZE] = {3, 6, 15, 29, 32, 50, 61, 85};

    search_and_print_info(vet, 15);
    search_and_print_info(vet, 50);
    search_and_print_info(vet, 39);
    search_and_print_info(vet, 5);
    search_and_print_info(vet, 100);

    return 0;
}

int sequential_search(int vet[SIZE], int num){
    int i;
    for(i=0; i<SIZE; i++){
        if(vet[i]==num) break;
    }
    if(i!=SIZE){
        i++;
        printf("Número de comparações - Pesquisa sequencial: %d\n", i);   
        return i-1;
    }
    else{
        printf("Número de comparações - Pesquisa sequencial: %d\n", i);
        return -1;
    }
    
}

int binary_search(int vet[SIZE], int num){
    int index, begin, end, comp = 0;

    begin = 0;
    end = SIZE - 1;

    while(begin<=end){
        index = begin + (end - begin) / 2;
        comp++;
        if(vet[index] == num){
            printf("Número de comparações - Pesquisa binária: %d\n", comp);
            return index;
        } 
        else if(vet[index]<num) begin = index + 1;
        else end = index - 1;
    }
    
    printf("Número de comparações - Pesquisa binária: %d\n", comp);
    return -1;
}

void search_and_print_info(int vet[SIZE], int num){
    int seq, bin;
    printf("Valor buscado: %d\n", num);
    seq = sequential_search(vet, num);
    if(seq!=-1) printf("Valor encontrado na posição %d com busca sequencial\n", seq);
    else printf("Valor não encontrado com busca sequencial\n");

    bin = binary_search(vet, num);
    if(bin!=-1) printf("Valor encontrado na posição %d com busca sequencial\n", bin);
    else printf("Valor não encontrado com busca binária\n");

    printf("\n");
}