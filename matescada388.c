#include <stdio.h>

int main(){
    int e[500][500], i, j, m, n, contador=0, verificador=0, esc=0, k, control=0;
    scanf("%d %d", &m, &n);
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &e[i][j]);
        }
    }
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(control == 0){
                for(k=(i+1); k<m; k++){
                    if(e[k][j] != 0){
                        esc = 1;
                        k = m+10;
                        control++;
                        j = n+10;
                        i = k;}
                    else
                        esc = 0;
                }
                if(e[i][j] != 0){
                    ++control;}
            }
        }
        control = 0;
    }
    if(esc==0)
        printf("S");
    else
        printf("N");
return 0;
}
