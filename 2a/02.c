#include <stdlib.h>
#include <stdio.h>

int main(){
    int lines, cols;
    int count, aux;
    int ** mat;

    printf("Insira a quantidade de linhas e colunas separadas por um espaço: ");
    scanf("%d %d", &lines, &cols);

    mat = (int **) malloc(sizeof(int *)*lines);

    if(mat == NULL){
        printf("Não foi possível alocar a memória\n");
        return 0;
    }

    for(count = 0; count<lines; count++){
        mat[count] = (int *) malloc(sizeof(int)*cols);
        if(mat[count] == NULL){
            printf("Não foi possível alocar a memória\n");
            for(aux=count-1; aux>=0; aux--){
                free(mat[aux]);
            }
            free(mat);
            return 0;
        }
    }

    for(count=0; count<lines; count++){
        for(aux=0;aux<cols;aux++){
            mat[count][aux] = aux;
        }
    }

    //for(count=0; count<lines; count++){
    //    for(aux=0;aux<cols;aux++){
    //        printf("%d ", mat[count][aux]);
    //    }
    //    printf("\n");
    //}

    for(count=0; count<lines; count++){
        free(mat[count]);
    }

    free(mat);

    return 0;
}