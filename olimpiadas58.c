#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

typedef struct{
    int ouro, prata, bronze;
} MEDALHA;

typedef struct{
    int *cont, *info;
} INDEX;

void lerMedalhas(MEDALHA d[], int tam, INDEX c){
    int i;
    for(i=0; i<tam; ++i){
        scanf("%d %d %d", &d[i].ouro, &d[i].prata, &d[i].bronze);
        c.cont[d[i].ouro-1]+= 10000;
        c.cont[d[i].prata-1]+= 100;
        c.cont[d[i].bronze-1]+= 1;
    }
}

void ordena(INDEX v, int n){
	int i, j, aux;
	for (i = 0; i < n; ++i){
		for (j = i+1; j < n; ++j){
			if(v.cont[i] < v.cont[j]){
			    swap(&v.info[i], &v.info[j]);
			    swap(&v.cont[i], &v.cont[j]);
            }
            if(v.cont[i] == v.cont[j]){
                if(v.info[i] > v.info[j]){
                    swap(&v.info[i], &v.info[j]);
                    swap(&v.cont[i], &v.cont[j]);
                }
            }
		}
    }
}

int main(){
    int n, m, j;
    INDEX i;
    MEDALHA *d;
    scanf("%d %d", &n, &m);
    d = (MEDALHA*)malloc(m*sizeof(MEDALHA));
    i.cont = (int*)calloc(n, sizeof(int));
    i.info = (int*)calloc(n, sizeof(int));
    for(j=0; j<n; ++j){
        i.info[j] = j+1;
    }
    lerMedalhas(d, m, i);
    ordena(i, n);
    for(j=0; j<n; j++){
        printf("%d\n", i.info[j]);
    }
    free(d);
    free(i.cont);
    free(i.info);
    return 0;
}

