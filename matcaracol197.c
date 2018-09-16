#include <stdio.h>

int main(){
    int c[100][100], m, i=0, j=0, cont=0, control = 0;
    scanf("%d", &m);
    for(i=0; i<m; i++){
        //printf("%d %d\n", i, j);
        scanf("%d", &c[i][j]);
        ++control;
    }
    i=i-1;
    do{
    for(j=j+1; j<(m-cont); j++){
        if(control == m*m){
            break;}
        //printf("%d %d\n", i, j);
        scanf("%d", &c[i][j]);
        control++;
    }
    j = j-1;
    for(i=i-1; i>=(0+cont); i--){
        if(control == m*m){
            break;}
        //printf("%d %d\n", i, j);
        scanf("%d", &c[i][j]);
        control++;
    }
    i = i+1;
    ++cont;
    for(j=j-1; j>=(0+cont); j--){
        if(control == m*m){
            break;}
        //printf("%d %d\n", i, j);
        scanf("%d", &c[i][j]);
        control++;
    }
    j=j+1;
    for(i=i+1; i<(m-cont); i++){
        if(control == m*m){
            break;}
        //printf("%d %d\n", i, j);
        scanf("%d", &c[i][j]);
        control++;
    }
    i=i-1;
    }while(control!=(m*m));
    for(i=0; i<m; i++){
        for(j=0; j<m; j++){
            printf("%d\n", c[i][j]);
        }
    }
return 0;
}

