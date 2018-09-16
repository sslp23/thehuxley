#include <stdio.h>

int main(){
	int a[1000][1000], i, j, verify, n, zero=0, one=0;
	scanf("%d", &n);
	for (j = 0; j < n; ++j){
		for (i = 0; i < n; ++i){
			scanf("%d", &a[i][j]);
		}
	}
	for (j = 0; j < n; ++j){
		for (i = 0; i < n; ++i){
			if(a[i][j] == 0)
				zero++;
			if(a[i][j] == 1){
				one++;
				if(a[i][j-1] == 1)
					one = 0;}
	}}
	if(zero == (n-1)*n && one == n)
		verify = 0;
	else
		verify = 1;
	for (j=0; j < n; ++j){
		for (i = 0; i < n; ++i){
			if (i!=n-1){
				printf("%d ", a[i][j]);
			}
			else
				printf("%d \n", a[i][j]);
		}
	}
	if(verify == 1)
		printf("False");
	else
		printf("True");
return 0;
}
