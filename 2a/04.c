#include <stdio.h>

void swap(int * a, int * b);

int main(){
    int a, b;

    printf("Entre dois valores inteiros separados por um espaço: ");
    scanf("%d %d", &a, &b);

    swap(&a, &b);

    //printf("%d %d\n", a, b);

    return 0;
}

void swap(int * a, int * b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}