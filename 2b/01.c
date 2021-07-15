#include <stdio.h>
#include <math.h>

float y = 1;

void solve_eq(int x);
unsigned long int fatorial(int num);

int main(){
    int x;

    scanf("%d", &x);

    solve_eq(x);

    printf("O resultado da equação é: %f\n", y);

    return 0;
}

void solve_eq(int x){
    int n;
    
    for(n=1;n<=x;n++){
        y += (n*pow(x,n+1)) / fatorial(n+1);
    }
}

unsigned long int fatorial(int num){
    unsigned long int fat = num;

    num--;
    while(num>0){
        fat *= num--;
    }

    return fat;
}