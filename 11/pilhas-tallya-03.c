#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int num;
    struct no *link;
} pile;

pile *p, *q, *top;
int qtd = 0;


void delete_element(int info);
void print_pile();

int main(){
    int i = 0, element;
    p = NULL;
    q = NULL;
    top = NULL;

    printf("Digite a quantidade de elementos da pilha: ");
    scanf("%d", &qtd);

    printf("Digite os %d números: ", qtd);
    for(i=0; i<qtd; i++){
        scanf("%d", &element);
        p = (pile*) malloc(sizeof(pile));
        p->num = element;
        p->link = q;
        top = p;
        q = p;
    }
    print_pile();
    printf("Digite o elemento que deseja excluir: ");
    scanf("%d", &element);
    delete_element(element);

    return 0;
}

void delete_element(int info){
    p = top;
    while (p != NULL) {
        if(p -> num == info){
            q -> link = p -> link;
            free(p);
            break;
        }
        q = p;
        p = p -> link;
    }
    print_pile();
}

void print_pile(){
    p = top;
    printf("Pilha criada: \n");
    while(p!=NULL){
        printf("[%d] ", p->num);
        p = p->link;
    }
}