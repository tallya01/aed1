#include <stdio.h>

#define T1 0
#define T2 1

unsigned long int fibonacci(int termo);

int main(){
    int termo;

    printf("Digite o termo da sequência que deseja visualizar: ");
    scanf("%d", &termo);

    printf("O %dº termo da sequência de Fibonacci é %lu\n", termo, fibonacci(termo));

    return 0;
}

unsigned long int fibonacci(int termo){
    if(termo == 1 || termo==2) return 1;
    else return (fibonacci(termo-1) + fibonacci(termo-2));
}