#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *link;
} list;

list *p, *q, *r, *first;
int qtd = 0;

void insert(int num) {
    p = (list *)malloc(sizeof(list));

    p->info = num;
    p->link = NULL;

    if (first == NULL) first = p;
    else r->link = p;
    r = p;
    p->link = first;
}

void print_list(){
    p = first;

    for(int i=1; i<=qtd; i++){
        printf("Elemento %d da lista: %d\n", i, p->info);
        p = p->link;
    }
}

void delete_by_value(int num) {
    p = q = first;
    while (p != NULL) {
        if (p->info == num) {
            q->link = p->link;
            free(p);
            qtd--;
            return;
        }
        q = p;
        p = p->link;
    }
}

void delete_by_position(int num) {
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
    int element, option, num;

    first = NULL;

    while(1){
        printf("Escolha uma opção:\n");
        printf("1. Inserir elementos:\n");
        printf("2. Ver lista:\n");
        printf("3. Deletar por valor:\n");
        printf("4. Deletar por posição:\n");
        printf("5. Sair:\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Digite a quantidade de elementos que deseja inserir: ");
                scanf("%d", &num);
                for(int i=1;i<=num;i++){
                    printf("\nDigite o elemento %d: ", i);
                    scanf("%d", &element);
                    insert(element);
                }
                qtd+=num;
                break;
            case 2: 
                print_list();
                break;
            case 3:
                printf("\nDigite o valor que deseja deletar: ");
                scanf("%d", &num);
                delete_by_value(num);
                break;
            case 4:
                printf("\nDigite a posição que deseja deletar: ");
                scanf("%d", &num);
                delete_by_position(num);
                break;
            case 5:
                destroy_list();
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }
}