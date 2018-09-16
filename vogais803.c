#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10000

int main(){
    char palavra[TAM], *p = palavra, vogal[TAM], *v = vogal;
    int j, a=0, e=0, i=0, o=0 , u=0;
    fgets(p, TAM, stdin);
    for(j=0; j<strlen(p); j++)
        switch(p[j]){
            case 'a': ++a;
                break;
            case 'A': ++a;
                break;
            case 'e': ++e;
                break;
            case 'E': ++e;
                break;
            case 'i': ++i;
                break;
            case 'I': ++i;
                break;
            case 'o': ++o;
                break;
            case 'O': ++o;
                break;
            case 'u': ++u;
                break;
            case 'U': ++u;
                break;
        }
    printf("a %d\n", a);
	printf("e %d\n", e);
	printf("i %d\n", i);
	printf("o %d\n", o);
	printf("u %d\n", u);
    return 0;
}
