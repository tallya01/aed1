#include <stdio.h>

void swap(int * a, int * b);

int main(){
    int a, b;

    printf("Digite dois inteiros: ");
    scanf("%d %d", &a, &b);

    swap(&a, &b);

    printf("A: %d e B: %d\n", a, b);

    return 0;
}

void swap(int * a, int * b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}