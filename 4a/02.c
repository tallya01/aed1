#include <stdio.h>
#include <math.h>

double perimetro(double * raio);
double area(double * raio);

int main(){
    double raio;

    printf("Digite o raio da circunferência: ");
    scanf("%lf", &raio);

    printf("O perímetro e a área da circunferência de raio %.2lf são, respectivamente, %.2lf e %.2lf\n", raio, perimetro(&raio), area(&raio));

    return 0;
}

double perimetro(double * raio){
    return 2*M_PI*(*raio);
}

double area(double * raio){
    return M_PI*(*raio)*(*raio);
}