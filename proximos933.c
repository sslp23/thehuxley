#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, i;
    double soma = 0, media, difmenor, menor;
    double *p = NULL, *dif = NULL;
    scanf("%d", &n);
    p = (double *)malloc(n*sizeof(double));
    dif = (double *)malloc(n*sizeof(double));
    for(i=0; i<n; ++i){
        scanf("%lf", &p[i]);
        soma = soma + p[i];
    }
    media = soma/n;
    for(i=0; i<n; ++i){
        dif[i] = fabs(p[i] - media);
        if(dif[i] < difmenor || i==0){
            difmenor = dif[i];
            menor = p[i];
        }
    }
    printf("MEDIA: %.2lf\n", media);
    printf("MAIS PROXIMO: %.2lf\n", menor);
    printf("DIFERENCA: %.2lf\n", difmenor);
    free(p);
    free(dif);
    return 0;
}
