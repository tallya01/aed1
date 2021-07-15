#include <stdio.h>

int MinDC(int n1, int n2, int menor, int divInicial);
int menorNum(int n1, int n2);

int main(){
    int a, b;

    printf("Digite dois números inteiros:\n");
    scanf("%d %d", &a, &b);

    printf("O Mínimo Divisor Comum de %d e %d (diferente de 1, caso exista) é %d\n", a, b, MinDC(a, b, menorNum(a,b),2));

    return 0;
}

int menorNum(int n1, int n2){
    if(n1<n2) return n1;
    else return n2;
}

int MinDC(int n1, int n2, int menor, int divInicial){
    if(divInicial>=menor) return 1;
    else if(n1%divInicial==0 && n2%divInicial==0) return divInicial;
    else MinDC(n1,n2,menorNum(n1,n2),++divInicial);
}