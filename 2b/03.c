#include <stdio.h>

unsigned long int fatorial(int num);
double somatorio(int n);

int main(){
    int n;

    printf("Digite um inteiro: ");
    scanf("%d", &n);

    printf("Resultado do somatório: %lf\n", somatorio(n));

    return 0;
}

unsigned long int fatorial(int num){
    unsigned long int fat = num;

    num--;
    while(num>0){
        fat *= num--;
    }

    return fat;
}

double somatorio(int n){
    int count;
    double soma;

    soma = 0;
    for(count=1;count<=n;count++){
        soma += 1.0/fatorial(count);
    }

    return soma;
}