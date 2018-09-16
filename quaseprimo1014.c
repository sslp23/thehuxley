#include <stdio.h>
#include <math.h>

int primo (int num){
    int contador, raizq, ehPrimo, res;
    raizq = sqrt(num);
    contador = 2;
    for(contador; contador <= raizq; ++contador){
        if(num % contador == 0){
            ehPrimo = 0;
            contador = num;}
        else
            ehPrimo = 1;
        }
    if(num == 2 || num == 3)
        ehPrimo = 1;

    if(ehPrimo == 1)
        ehPrimo = 1;
    else
        ehPrimo = 0;

    res = ehPrimo;

    return res;
}

int main(){
    int numero, teste, contador, ehQSP, verificador, testador, raiz;
    scanf("%d", &teste);
    contador = 0;
    for(contador; contador < teste; ++contador){
    scanf("%d", &numero);
    ehQSP = numero;
    raiz = sqrt(numero);
    if(primo(numero) == 1)
        printf("Primo\n");
    else
        if(numero % 2 == 0){
            if(primo(numero/2) == 1 && numero/2 != 2)
                printf("Quase primo\n");
            else
                printf("Nem primo nem quase primo\n");}
        else{
            for(ehQSP; ehQSP > raiz; ehQSP = ehQSP = -- ehQSP){
                if(numero % ehQSP == 0 && ehQSP != raiz){
                    testador = numero/ehQSP;
                    if(primo(ehQSP) == 1){
                        if(primo(testador) == 1){
                            verificador = 1;
                            ehQSP = -1;}
                        else{
                            verificador = 0;}}
                    else{
                        verificador = 0;}}
                else{
                    verificador = 0;}
            }
            if(numero == 1)
                verificador = 0;
            if(verificador != 1){
                printf("Nem primo nem quase primo\n");}
            else
                printf("Quase primo\n");
            }
    }
    return 0;
}

