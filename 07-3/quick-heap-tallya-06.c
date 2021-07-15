#include <stdio.h>
#include <ctype.h>

void swap(char * vet, int i, int j);
void heapify(char vet[], int n, int i);
void heapSort(char vet[], int n);

int main(){
    char str[] = {"Ordenando com Heap Sort"};

    heapSort(str, sizeof(str)/sizeof(char));

    printf("%s\n", str);

    return 0;
}

void swap(char * vet, int i, int j){
    char tmp = vet[i];
    vet[i] = vet[j];
    vet[j] = tmp;
}

void heapify(char vet[], int n, int i){
    int min = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && tolower(vet[leftChild]) < tolower(vet[min])) min = leftChild;
    if (rightChild < n && tolower(vet[rightChild]) < tolower(vet[min])) min = rightChild;

    if (min != i){
        swap(vet, i, min);
        heapify(vet, n, min);
    }
}

void heapSort(char vet[], int n){
    for (int i = n / 2 - 1; i >= 0; i--) heapify(vet, n, i);
    for (int i = n - 1; i >= 0; i--){
        swap(vet, 0, i);
        heapify(vet, i, 0);
    }
}