#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

//função do prof, não testada
void delete(int num) {
    p = first;
    while (p != NULL) {
        if (p->info == num) {
            q->link = p->link;
            free(p);
        }
        q = p;
        p = p->link;
    }
}

void print_list(){
    p = first;

    for(int i=1; i<=qtd; i++){
        printf("Elemento %d da lista: %d\n", i, p->info);
        p = p->link;
    }
}

int sequential_search(int num){
    p = first;
    for(int i=1; i<=qtd; i++){
        if(p->info==num) return i;
        p = p->link;
    }
    return -1;
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
    int element, index;
    time_t t;

    srand(time(&t));
    first = NULL;

    printf("Informe a quantidade de elementos: ");
    scanf("%u", &qtd);
    for (int i = 1; i <= qtd; i++) {
        insert(rand() % 101); //preenche a lista com valores aleatórios de 0 a 100
    }

    printf("\n");
    print_list();
    
    printf("\nDigite um número para buscar: ");
    scanf("%d", &element);
    index = sequential_search(element);
    if(index!=-1) printf("Valor %d encontrado na posição %d da lista\n", element, index);
    else printf("Valor %d não encontrado na lista\n", element);

    destroy_list();

    return 0;
}