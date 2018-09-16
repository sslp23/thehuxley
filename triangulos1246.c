#include <stdio.h>
unsigned long long int somatorio(unsigned long long int linha){
	unsigned long long int contador, result, testador, novocontador, soma;
	contador = 1;
	testador = 1;
	for (testador; testador < linha; ++testador){
		contador = contador + testador;}
	novocontador = linha + contador;
	for (contador; contador < novocontador; ++contador){
		soma = contador + soma;}
	return soma;


}
int main(){
	unsigned long long int soma;
	unsigned long long int teste, linha, contador;
	contador = 0;
	scanf("%llu", &teste);
	for (contador; contador < teste; ++contador){
		scanf("%llu", &linha);
		soma = somatorio(linha);
		printf("%llu\n", soma);}

	return 0;
}
