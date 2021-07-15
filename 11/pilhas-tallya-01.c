#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int i=0, size=0;
    char word[21];

    printf("Digite uma palavra: ");
    scanf("%[^\n]", word);
    size = strlen(word);

    printf("\nDesempilhando:\n ");
    for(i=size-1; i>=0; i--)
        printf("[%c] ", word[i]);
    
    return 0;
}