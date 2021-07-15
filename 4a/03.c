#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    if(atoi(argv[1])>31) printf("dia inválido ");
    else printf("%s de ", argv[1]);
    
    switch(atoi(argv[2])){
        case 1:
            printf("janeiro");
            break;
        case 2:
            printf("fevereiro");
            break;
        case 3:
            printf("março");
            break;
        case 4:
            printf("abril");
            break;
        case 5:
            printf("maio");
            break;
        case 6:
            printf("junho");
            break;
        case 7:
            printf("julho");
            break;
        case 8:
            printf("agosto");
            break;
        case 9:
            printf("setembro");
            break;
        case 10:
            printf("outubro");
            break;
        case 11:
            printf("novembro");
            break;
        case 12:
            printf("dezembro");
            break;
        default: printf("mês inválido");
    }

    printf(" de %s\n", argv[3]);

    return 0;
}