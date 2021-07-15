#include <stdio.h>

double square_root(int n);

int main(){
    int n;

    printf("Digite um número para calcular a raiz quadrada: ");
    scanf("%d", &n);

    printf("A raiz quadrada do número informado é: %lf\n", square_root(n));

    return 0;
}

double square_root(int n){
    double root;
    int count;

    for(count=0;count<10;count++){
        if(count==0) root = (1/2) + (n/2);
        else root = (root/2) + (n/(2*root)); 
    }

    return root;
}