/*
* nesse código, o conceito de posição refere-se
* à posição na matriz, não na lista, visto que 
* é possível inserir valores em qualquer posição da
* matriz e a segunda coluna indica em qual índice se
* encontra o próximo elemento da lista
*
* foi feito dessa forma pois, se a ordem da lista
* seguir a ordem dos índices da matriz, não faz sentido
* guardar a posição do próximo elemento, visto que
* bastaria acrescentar uma unidade
*/
#include <stdio.h>

void clear_list(int list[10][2]);
void insert(int list[10][2], int pos, int val);
void delete(int list[10][2], int pos);
void show_list(int list[10][2]);

//guarda a posição do primeiro elemento
//se a lista não existir, vale -1
int firstposition = -1;

int main(){
    int list[10][2];
    int i, option, pos, val;

    for(i=0;i<10;i++) list[i][1] = -1;

    while(1){
        printf("Bem vindo(a). Escolha uma opção:\n");
        printf("1. Limpar a lista\n");
        printf("2. Inserir um elemento\n");
        printf("3. Deletar um elemento\n");
        printf("4. Exibir lista\n");
        printf("5. Sair\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                clear_list(list);
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &val);
                printf("\n");
                printf("Digite a posição da matriz em que deseja inserir esse valor(1-10): ");
                scanf("%d", &pos);
                insert(list, pos, val);
                printf("\n");
                break;
            case 3:
                printf("Digite a posição da matriz que deseja deletar(1-10): ");
                scanf("%d", &pos);
                delete(list, pos);
                printf("\n");
                break;
            case 4:
                show_list(list);
                printf("\n");
                break;
            case 5:
                return 0;
            default:
                printf("Opção inválida! Digite uma das opções disponíveis.");
                printf("\n");
        }
    }
}

void clear_list(int list[10][2]){
    int i;
    for(i=0;i<10;i++) list[i][0] = 0;
    firstposition = -1;
}

void insert(int list[10][2], int pos, int val){
    int i, j, k, aux;

    if(firstposition==-1){
        firstposition = pos-1;
        list[pos-1][0] = val;
        //se a posição do próximo elemento for
        //-1, o elemento analisado não existe.
        //se for -2, é o último elemento da lista
        list[pos-1][1] = -2;
        printf("Elemento inserido\n");
    }
    else{
        i=firstposition;
        for(j=1;j<=10;j++){
            if(list[pos-1][1]==-2){
                printf("O elemento de posição %d já existe. Ele será substituído pelo novo valor\n", pos);
                list[pos-1][0] = val;
                break;
            }
            else if(pos==j){
                if(list[pos-1][1]!=-1){
                    printf("O elemento de posição %d já existe. Os elementos seguintes da lista serão reposicionados\n", j);

                    for(k=i;;){
                        aux=list[k][0];
                        list[k][0] = val;
                        if(list[k][1]==-2) break;
                        val=aux;
                        k=list[k][1];
                    }
                }
                else{
                    for(k=0;k<10;k++){
                        if(list[k][1]==-2){
                            list[k][1] = pos-1;
                            list[pos-1][0] = val;
                            list[pos-1][1] = -2;
                            printf("Elemento inserido\n");
                            return;
                        } 
                    }
                }
            }
            else if(list[i][1]==-2 || list[i][1]==-1) i=pos-1;
            else i = list[i][1];
        }
    }
}

void delete(int list[10][2], int pos){
    if(list[pos-1][1]==-1) printf("O elemento buscado não existe!\n");
    else{
        for(int i=0;i<10;i++){
            if(list[i][1]==pos-1){
                list[i][1] = list[pos-1][1];
                list[pos-1][0] = 0;
                list[pos-1][1] = -1;
                printf("Elemento removido.\n");
                break;
            }
        }
    }
}
void show_list(int list[10][2]){
    int i, j;
    for(i=firstposition, j=1;;j++){
        if(list[i][1]==-1){
            if(j==1) printf("Lista vazia!\n");
            break;
        }
        printf("Elemento %d: %d\n", j, list[i][0]);
        if(list[i][1]==-2) break;
        i=list[i][1];
    }
}