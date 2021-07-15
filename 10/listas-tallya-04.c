#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *link;
} list;

list *p, *q, *first;
int qtd = 0;

void insert(int num) {
    p = (list *)malloc(sizeof(list));

    p->info = num;
    p->link = NULL;

    if (first == NULL) first = p;
    else q->link = p;
    q = p;
}

void print_list(){
    p = first;

    for(int i=1; i<=qtd; i++){
        printf("Elemento %d da lista: %d\n", i, p->info);
        p = p->link;
    }
}

void delete(int num) {
    p = q = first;
    for(int i=1;i<=qtd;i++) {
        if (i == num) {
            q->link = p->link;
            free(p);
            qtd--;
            return;
        }
        q = p;
        p = p->link;
    }
}

void destroy_list(){
    p = first;
    for(int i=1; i<=qtd; i++){
        q = p;
        p = p->link;
        free(q);
        //printf("Elemento %d deletado\n", i);
    }
}

int main() {
    int element;

    first = NULL;

    printf("Informe a quantidade de elementos: ");
    scanf("%u", &qtd);
    for (int i = 1; i <= qtd; i++) {
        printf("Digite o valor do elemento %d: ", i);
        scanf("%d", &element);
        insert(element);
    }

    printf("\n");
    print_list();

    printf("\nInforme a posição para deletar: ");
    scanf("%d", &element);
    delete(element);

    print_list();

    destroy_list();

    return 0;
}