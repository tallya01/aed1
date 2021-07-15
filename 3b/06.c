#include <stdio.h>

double squareRoot(double n, double a, double b);
double findInitA(unsigned int n);
double mod(double num);

int main(){
    unsigned int n;
    double initA, initB;

    printf("Digite um inteiro positivo para calcular a raiz quadrada: ");
    scanf("%u", &n);

    initA = findInitA(n);
    initB = n/initA;

    printf("A raiz quadrada de %u com erro menor que 0,0001 é %lf\n", n, squareRoot(n, initA, initB));

    return 0; 
}

double findInitA(unsigned int n){
    int count = 1;
    while(count){
        if(count*count>=n) return (count + --count)/2.0;
        else count++;
    }
}

double mod(double num){
    if(num>=0) return num;
    else return -num;
}

double squareRoot(double n, double a, double b){
    a = (a+b)/2;
    b = n/a;
    if(mod(b*b-n)>0.0001) squareRoot(n, a, b);
    else return b;
}