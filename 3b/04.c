#include <stdio.h>

void printInBinary(float n);

int main(){
    int num;
    float n;

    printf("Digite um número para ser impresso em binário: ");
    scanf("%d", &num);
    n=num;

    printInBinary(n);
    putchar('\n');

    return 0;
}

void printInBinary(float n){
    if(n==0) printf("%d", 0);
    else if(n/2>=1){
        printInBinary(n/2);
        printf("%d", (int)n%2);
    }
    else{
        printf("%d", 1);
        return;
    } 
}