#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char prod[25];
    double valor;
} MATERIAL;

void swap(MATERIAL *a, MATERIAL *b){
    MATERIAL aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void lerMateriais(MATERIAL m[], int t){
    int i;
    for(i=0; i<t; i++){
        scanf(" %s %lf", m[i].prod, &m[i].valor);
    }
}

void ordena1(MATERIAL v[], int n){
	int i, j, contador=0, k=0;
	for (i = 0; i < n; ++i){
		for (j = i+1; j < n; ++j){
			if(v[i].valor > v[j].valor){
			    swap(&v[i], &v[j]);
            }
            if(v[i].valor == v[j].valor){
                if(strcmp(v[i].prod, v[j].prod)>0){
                    swap(&v[i], &v[j]);
                }
            }
		}
	}
}

int seleciona(MATERIAL m[], int t, double d){
    int i;
    double soma=0;
    for(i=0; i<t; i++){
        soma += m[i].valor;
        if(soma>d)
            break;
    }
    return i;
}

double calcTroco(MATERIAL m[], int t, double d){
    int i;
    double soma=0;
    for(i=0; i<t; i++){
        soma += m[i].valor;
    }
    return d-soma;
}

void ordena2(MATERIAL v[], int n){
	int i, j, contador=0, k=0;
	for (i = 0; i < n; ++i){
		for (j = i+1; j < n; ++j){
			if(v[i].prod[0] > v[j].prod[0]){
			    swap(&v[i], &v[j]);
            }
            if(v[i].prod[0] == v[j].prod[0]){
                if(strcmp(v[i].prod, v[j].prod)>0){
                    swap(&v[i], &v[j]);
                }
            }
		}
	}
}

void printaMaterial(MATERIAL m[], int t){
    int i;
    for(i=0; i<t; i++){
        printf("%s %.2lf\n", m[i].prod, m[i].valor);
    }
}

int main(){
    double dinheiro, troco;
    int n, l;
    MATERIAL *m=NULL;
    scanf("%lf", &dinheiro);
    scanf("%d", &n);
    m = (MATERIAL*)malloc(n*sizeof(MATERIAL));
    lerMateriais(m, n);
    ordena1(m, n);
    l = seleciona(m, n, dinheiro);
    troco = calcTroco(m, l, dinheiro);
    ordena2(m, l);
    printaMaterial(m, l);
    printf("%.2lf", troco);
    free(m);
    return 0;
}

