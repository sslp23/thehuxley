#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[1000], cor[15], tam;
    int valor, vt;
} CAMISETAS;

void lerD(CAMISETAS d[], int t){
    int i, j, k=0;
    CAMISETAS aux;
    for(i=0; i<t; i++){
        scanf(" %[^\n]", d[i].nome);
        scanf(" %s %c", d[i].cor, &d[i].tam);
        if(d[i].tam == 'P'){
            d[i].vt = 1;}
            else{
                if(d[i].tam == 'M')
                    d[i].vt = 2;
            else
                d[i].vt = 3;
            }
        d[i].valor = (d[i].cor[0]*1000) + d[i].nome[0]*1 + (d[i].vt*100);
    }
    for (i = 0; i < t; ++i){
		for (j = i+1; j < t; ++j){
			if(d[i].valor > d[j].valor){
			    aux = d[i];
			    d[i] = d[j];
			    d[j] = aux;}
            if(d[i].valor == d[j].valor){
                while(d[i].nome[k]==d[j].nome[k])
                    k++;
                if(d[i].nome[k]>d[j].nome[k]){
                    aux = d[i];
                    d[i] = d[j];
                    d[j] = aux;}
            }
        k=0;
		}
	}
}

void printaD(CAMISETAS d[], int t){
    int i;
    for(i=0; i<t; i++){
        printf("%s %c %s\n", d[i].cor, d[i].tam, d[i].nome);
    }
}

int main(){
    int n;
    CAMISETAS d[120];
    do{
        scanf("%d", &n);
        if(n==0)
            break;
        lerD(d, n);
        printf("\n");
        printaD(d, n);
    }while(n!=0);
    return 0;
}
