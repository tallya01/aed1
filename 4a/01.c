#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findstr(char * str1, char * str2);

int main(){
    char str[51];
    char * str1, * str2;
    int i, pos;

    printf("Digite a primeira string:\n");
    scanf("%[^\n]", str);
    str1 = malloc((strlen(str)+1)*sizeof(char));
    for(i=0; i<strlen(str); i++){
        *str1 = str[i]; 
        str1++;
    }
    str1 -= i;

    printf("Digite a segunda string:\n");
    scanf("%*c%[^\n]", str);
    str2 = malloc((strlen(str)+1)*sizeof(char));
    for(i=0; i<strlen(str); i++){
        *str2 = str[i]; 
        str2++;
    }
    str2 -= i;

    pos = findstr(str1, str2);

    if(pos != -1) printf("O início da string 2 na string 1 está na posição %d, no endereço %p\n", pos, str1+pos);
    else printf("String 2 não encontrada na string 1\n");

    free(str1);
    free(str2);

    return 0;
}

int findstr(char * str1, char * str2){
    int i, j, k;

    for(i=0; *str1!='\0' && *str2!='\0'; i++){
        if(*str1==*str2){
            for(j=i, k=1; *str1!='\0' && *str2!='\0'; j++, k++){
                str1++;
                str2++;
                if(*str1==*str2) continue;
                str2 -= k;
            }
            if(*str2=='\0'){
                str1 -= j;
                str2 -= k;
                return i;
            }
        }
        else str1++;
    }

    return -1;
}