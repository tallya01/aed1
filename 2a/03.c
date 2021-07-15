#include <stdio.h>
#include <stdlib.h>

void read_mat(int * lines, int * cols, int ** mat);
void print_mat(int * lines, int * cols, int ** mat);

int main(){
    int lines, cols, count, count2;
    int ** mat;

    printf("Digite a quantidade de linhas e colunas separadas por um espaço: ");
    scanf("%d %d", &lines, &cols);

    mat = (int**) malloc(sizeof(int*)*lines);

    for(count=0;count<lines;count++){
        mat[count] = (int*) malloc(sizeof(int)*cols);
    }

    read_mat(&lines, &cols, mat);
    print_mat(&lines, &cols, mat);

    for(count=0;count<lines;count++){
        free(mat[count]);
    }

    free(mat);

    return 0;
}

void read_mat(int * lines, int * cols, int ** mat){
    int i, j;

    printf("Digite os elementos da matriz:\n");
    for(i=0;i<*lines;i++){
        for(j=0;j<*cols;j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

void print_mat(int * lines, int * cols, int ** mat){
    int i, j;
    for(i=0;i<*lines;i++){
        for(j=0;j<*cols;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}