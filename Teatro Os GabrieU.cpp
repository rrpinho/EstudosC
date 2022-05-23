/*______________________________________________________
Universidade Salvador
Matéria: Linguagem de Programação
Professor(a): Christianne Dalforno

Aluno:										Curso:							Matricula:
Rafael Pinho de Sousa Ribeiro				Engenharia Mecatrônica			149161022
Diego Luz Gusmão Braga						Engenharia Mecatrônica			149161003
Gabriel Cardoso Barreto dos Santos          Engenharia Mecatrônica          149161011
Gabriel Mascarenhas Silveira                Engenharia Mecatrônica          149161044
______________________________________________________*/
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#define TAM 8

struct sessao{
	char fileira;
	int assento;
	bool disponivel;
};

void inicializar(struct sessao cadeiras[TAM][TAM]);
void carregarArquivo(struct sessao cadeiras [TAM][TAM]);
void boasVindas(struct sessao cadeiras[TAM][TAM]);
int ingresso(struct sessao cadeiras[TAM][TAM]);
int verificar(struct sessao cadeiras[TAM][TAM], char fileira, int assento);
void salvarArquivo(struct sessao cadeiras [TAM][TAM]);

int continteiras=0, contmeias=0;
float contvalor=0, contvalor2=0;

main(){
	system("color 70");
	setlocale(LC_ALL,"portuguese");
	int sair=1, opc=0;
	struct sessao cadeiras[TAM][TAM];
	inicializar(cadeiras);
	carregarArquivo(cadeiras);
	do{
		system("cls");
		printf("\t\t####### Teatro Os GabrieU ######\n\n");
		printf("Você deseja comprar ingressos? {1 -- Sim} || {2 -- Não}  ");
		scanf("%d", &opc);
		fflush(stdin);
		if(opc == 1){
			boasVindas(cadeiras);
			printf("\n");
			sair = ingresso(cadeiras);
			if(sair == 0)
				break;
			printf("\n");
		}
	}while(opc!=2);
	contvalor2 += contvalor;
	system("cls");
	printf("\t\t ###### Teatro Os GabrieU ######\n\n");
	printf("Foram vendidos %d ingressos inteiras e %d ingressos meias = %d ingressos vendidos\n", continteiras, contmeias, continteiras+contmeias);
	printf("A bilheteria arrecadou R$%.2f no dia de hoje\nE arrecadou R$%.2f com a peça no total\n\n", contvalor, contvalor2);
	salvarArquivo(cadeiras);
	system("pause");
}

void inicializar(struct sessao cadeiras[TAM][TAM]){
	for (int i=0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			cadeiras[i][j].fileira = 65+i;
			cadeiras[i][j].assento = j+1;
			cadeiras[i][j].disponivel = false;
		}
	}
}

void boasVindas(struct sessao cadeiras[TAM][TAM]){
	system("cls");
	printf("\n\t\tBem-Vindo ao Teatro Os GabrieU.");
	printf("\n\tO espetáculo da semana será: As Peripécias dos Algoritmos\n");
	printf("\tDigite 100 a qualquer momento para fechar o programa\n\n");
	printf("\nAs cadeiras disponíveis são:\n");
	for(int i=0;i<TAM;i++){
		printf("\t");
		for(int j=0;j<TAM;j++){
			if(cadeiras[i][j].disponivel == false){
			printf("%c%d\t", cadeiras[i][j].fileira,cadeiras[i][j].assento);
			}
			else
				printf("**\t");
	 	}
		printf("\n");
	}
}

int ingresso(struct sessao cadeiras[TAM][TAM]){
	char fileira[99], fileira2[99];
	int assento[99], assento2[99], i, j, inteiras=0, meias=0, total=0, cont=0, repete=1, confirmacao=0;
	float valor=0;
	printf("Digite a quantidade de ingressos inteiros desejado: ");
	scanf("%d", &inteiras);
	if(inteiras == 100)
		return 0;
	printf("Digite a quantidade de ingressos meias desejado: ");
	scanf("%d", &meias);
	if(meias == 100)
		return 0;
	total = inteiras + meias;
	valor = (inteiras*14) + (meias*7);
	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			if(cadeiras[i][j].disponivel == false)
				cont++;
		}
	}
	if(total>=cont){
		printf("\n\tNão possuimos essa quantidade de cadeiras disponíveis\n\n");
		system("pause");
		return 1;
	}
	for(i=0; i<total; i++){
		do{
		fflush(stdin);	
		printf("Digite a %d° cadeira desejada: ", i+1);
		scanf("%c%d", &fileira[i], &assento[i]);
		if(fileira[i] && assento[i] == 100)
			return 0;
		repete = verificar(cadeiras, fileira[i], assento[i]);
		if(repete == 2){
			strcpy(fileira2, fileira);
			assento2[i] = assento[i];
		}
		}while(repete==1);
	}
	printf("Os seus ingressos ficaram no valor de R$%.2f\n\n", valor);
	printf("Deseja confirmar sua compra? {1--Sim} || {2--Não}  ");
	scanf("%d", &confirmacao);
	if(confirmacao == 1){
		continteiras += inteiras;
		contmeias += meias;
		contvalor += valor;
		for(i=0; i<total; i++){
			if(fileira[i]<97)
				cadeiras[fileira2[i]-65][assento2[i]-1].disponivel = true;
			else
				cadeiras[fileira2[i]-97][assento2[i]-1].disponivel = true;
		}
	}
	system("pause");
	return 1;
}

int verificar(struct sessao cadeiras[TAM][TAM], char fileira, int assento){
	if(!cadeiras[fileira][assento].disponivel){
		if(((fileira>72 && fileira<97) || fileira>104 ) || assento>TAM){
			printf("\tOPA! DIGITE UMA CADEIRA VALIDA!\n\n");
			system("pause");
			return 1;
		}else
			return 2;
	}else{
		printf("Esta cadeira já está ocupada. Digite uma outra cadeira.\n");
		system("pause");
		return 1;
	}
	return 0;
}

void carregarArquivo(struct sessao cadeiras[TAM][TAM]){
	FILE *arq;
	arq = fopen("Teatro.dat", "r");
	for(int i = 0; i < TAM; i++){
		for(int j = 0; j < TAM; j++)
			fread(&cadeiras[i][j], sizeof(cadeiras[i][j]), 1, arq);
	}
	fscanf(arq, "%f", &contvalor2);
	fclose(arq);
}

void salvarArquivo(struct sessao cadeiras[TAM][TAM]){
	FILE *arq;
	arq = fopen("Teatro.dat", "w");
	for(int i = 0; i < TAM; i++){
		for(int j = 0; j < TAM; j++)
			fwrite(&cadeiras[i][j], sizeof(cadeiras[i][j]), 1, arq);		
	}
	fprintf(arq, "%f", contvalor2);
	fclose(arq);
}
