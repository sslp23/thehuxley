#include <stdio.h>
#include <math.h>

int main(){
    int numero, fator = 2, ehPrimo = 1, soma = 0;
    double raizq;
    scanf("%d", &numero);
    while(numero != 0){
    raizq = sqrt(numero);
    if(numero == 1){
        printf("0\n");
        scanf("%d", &numero);}
    else{
    for(fator; fator <= raizq; ++fator){
        if(numero % fator == 0){
            soma = soma + fator;
            numero = numero/fator;
            ehPrimo = 0;
            if(numero % fator == 0){
            fator = fator - 1;}
            //printf("%d", fator);}
            if(numero == 1){
                break;}}
    }
    if(fator > raizq){
        soma = soma + numero;}
    if(ehPrimo == 1){
        printf("%d\n", numero);}
    else
        printf("%d\n", soma);

    scanf("%d", &numero);
    soma = 0;
    fator = 2;
    }}
    return 0;
}

