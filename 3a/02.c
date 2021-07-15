#include <stdio.h>

double pot(double base, int exp);

int main(){
    int exp;
    double base;

    printf("Digite uma base e um expoente inteiro: ");
    scanf("%lf %d", &base, &exp);

    printf("%.2lf elevado a %d resulta em: %.2lf\n", base, exp, pot(base,exp));

    return 0;
}

double pot(double base, int exp){
    if(exp==0) return 1;
    else return (base * pot(base, exp-1));
}