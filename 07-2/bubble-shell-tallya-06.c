#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int * vet, int size);
void shellSort(int * vet, int size);

int main(){
    int v1[5000], v2[5000], i;
    clock_t inicio, bubble, shell;

    srand(time(NULL));
    for(i=0;i<5000;i++) v1[i] = rand();
    for(i=0;i<5000;i++) v2[i] = v1[i];

    inicio = clock();
    bubbleSort(v1, 5000);
    bubble = clock();

    printf("Tempo demorado com Bubble Sort: %lf segundos\n", (double)(bubble-inicio)/CLOCKS_PER_SEC);

    inicio = clock();
    shellSort(v2, 5000);
    shell = clock();

    printf("Tempo demorado com Shell Sort: %lf segundos\n", (double)(shell-inicio)/CLOCKS_PER_SEC);

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