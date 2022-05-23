#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
void repeticao(float raioXY[], int n);
void ordem(float raioXY[], int n);
main(){
	system("color 70");
	setlocale(LC_ALL, "portuguese");
	float x=0,y=0, raioxy, repete=0;
	int n=0, i;
	printf("Digite o valor da coordenada x: ");
	scanf("%f", &x);
	printf("Digite o valor da coordenada y: ");
	scanf("%f", &y);
	printf("Quantos pontos serão verificados? ");
	scanf("%d", &n);
	raioxy = sqrt( pow((x-0),2) + pow((y-0),2) );
	printf("%.2f", raioxy);
	float X[n],Y[n], raioXY[n];
	for(i=0; i<n; i++){
		printf("\n\nDigite o valor da coordenada x do %d° ponto: ", i+1);
		scanf("%f", &X[i]);
		printf("Digite o valor da coordenada y do %d° ponto: ", i+1);
		scanf("%f", &Y[i]);
		raioXY[i] = sqrt(pow((x-X[i]), 2) + pow((y-Y[i]), 2) );
		printf("O raio de (%.2f,%.2f) é: %.2f", X[i], Y[i], raioXY[i]);
	}
	printf("\n\nOs raios das circunferências centradas no ponto (%.2f,%.2f) que passam por pelo menos um dos %d pontos são: ", x, y, n);
	ordem(raioXY, n);
}

void ordem(float raioXY[], int n){
	float aux;
	for(int k=0; k<n-2; k++){
		for(int i=0; i<n-2; i++){
			if(raioXY[i]>raioXY[i+1]){
				aux = raioXY[i];
				raioXY[i] = raioXY[i+1];
				raioXY[i+1] = aux;
			}
		}
	}
	repeticao(raioXY,n);
}

void repeticao(float raioXY[], int n){
	int repetidos = 1;
	float teste;
	teste = raioXY[0];
	for(int i=1; i<=n; i++){
		if(raioXY[i] != teste)
			printf("(%.2f) ", teste);
		teste = raioXY[i];
	}
}
