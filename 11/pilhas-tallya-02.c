#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int i = 0;
    char word[20];
    char *p;

    printf("Digite uma palavra: ");
    scanf("%[^\n]", word);

    p = (char *) malloc(sizeof(char)*strlen(word));

    for(i=0; i<strlen(word); i++)
        p[i] = word[i];

    printf("\nDesempilhando:\n ");
    for(i=strlen(word)-1; i>=0; i--)
        printf("[%c] ", p[i]);

    return 0;
}