#include <stdio.h>

/* Parâmetros
* n = número de discos
* O = torre de origem
* D = torre de destino
* T = torre intermediária
*/
void Hanoi(int n, int O, int D, int T);

int main(){
    int n;

    printf("Digite o número de discos: ");
    scanf("%d", &n);

    printf("Movendo discos da torre 1 para a torre 3\n");
    Hanoi(n,1,3,2);

    return 0;
}

void Hanoi(int n, int O, int D, int T){
    if(n>0){
        Hanoi(n-1, O, T, D);
        printf("Mover disco superior da torre %d para a torre %d\n", O, D);
        Hanoi(n-1, T, D, O);
    }
}