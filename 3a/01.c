#include <stdio.h>
#include <string.h>

#define SIZE 51

void invertString(char * string, int firstIndex, int lastIndex);

int main(){
    char str[SIZE];

    printf("Digite uma palavra ou frase (max. %d caracteres): ", SIZE-1);
    scanf("%[^\n]", str);

    invertString(str, 0, (strlen(str)-1));

    printf("%s\n", str);

    return 0;
}

void invertString(char * string, int firstIndex, int lastIndex){
    char aux;

    /*
    *se a string tiver um número ímpar de caracteres, a inversão 
    *estará pronta quando o índice inicial for igual ao final
    *se a string tiver um número par de caracteres, a inversão
    *estará pronta quando o índice inicial ultrapassar o final
    */
    if(firstIndex==lastIndex || firstIndex-1==lastIndex) return;
    else{
        aux = string[firstIndex];
        string[firstIndex] = string[lastIndex];
        string[lastIndex] = aux;
        invertString(string, firstIndex+1, lastIndex-1);
    }
}