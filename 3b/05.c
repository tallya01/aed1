#include <stdio.h>

int MaxDC(int n1, int n2, int divInicial);
int menorNum(int n1, int n2);

int main(){
    int a, b;

    printf("Digite dois números inteiros:\n");
    scanf("%d %d", &a, &b);

    printf("O Máximo Divisor Comum de %d e %d é %d\n", a, b, MaxDC(a, b, menorNum(a,b)/2));

    return 0;
}

int menorNum(int n1, int n2){
    if(n1<n2) return n1;
    else return n2;
}

int MaxDC(int n1, int n2, int divInicial){
    if(divInicial<=1) return 1;
    else if(n1%divInicial==0 && n2%divInicial==0) return divInicial;
    else MaxDC(n1,n2,--divInicial);
}