#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define LIMITE 5
main(){
	system("color 70");
	setlocale(LC_ALL, "portuguese");
	int i, t=0, passageiros=0, x=0;
	printf("Digite quantas viajens ir�o ocorrer: ");
	scanf("%d", &t);
	int hh[t], mm[t], X[t];
	for( i=0; i<t; i++) //Zerando o vetor, para solucionar um problema com o Buffer
		X[i]=0;
	for( i=0; i<t; i++ ){
		printf("Informe o hor�rio de partida do %d� �nibus: ", i+1);
		scanf("%d:%d", &hh[i],&mm[i]);
	}
	printf("Informe a quantidade de passageiros que ir�o viajar: ");
	scanf("%d", &passageiros);
	system("cls");
	printf("\n\tOs hor�rios dispon�veis para viajem s�o os seguintes:\n");
	for( i=0; i<t; i++ )
		printf(" %d ---- %.2d:%.2d\n",i+1, hh[i], mm[i]);
	
	for( i=0; i<passageiros; i++ ){
		printf("Passageiro n�:%d digite o n�mero correspondente da viajem desejada: ", i+1);
		scanf("%d", &x);
		x--;
		X[x]+=1;
		if(X[x]>LIMITE){
			printf("Este �nibus est� cheio, por favor selecione outro.\n");
			i--;
		}
	}
	printf("\nO limite de passageiros por �nibus �: %d\n\n", LIMITE);
	for( i=0; i<t; i++)
		printf("%d passageiros ir�o viajar no �nibus %d ---- %.2d:%.2d\n", X[i], i+1, hh[i], mm[i]);
}
