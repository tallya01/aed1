#include <stdio.h>
#include <string.h>

#define SIZE 51

int count = 0;

void findChar(char * str, char c, int index);

int main(){
    char str[SIZE], c;

    printf("Digite uma palavra ou frase (max. %d caracteres):\n", SIZE);
    scanf("%[^\n]", str);
    printf("Digite um caractere para ser localizado na string: ");
    scanf("%*c%c", &c);

    findChar(str, c, 0);

    printf("O caractere '%c' foi encontrado na string %d vez(es)\n", c, count);

    return 0;
}
void findChar(char * str, char c, int index){
    if(index<strlen(str)){
        findChar(str, c, index+1);
        if(str[index]==c) count++;
    }
}