/*______________________________________________________
Universidade Salvador
Curso: Engenharia Mecatr�nica
Mat�ria: Linguagem de Programa��o
Professor(a): Christianne Dalforno
Aluno: Rafael Pinho de Sousa Ribeiro
Matricula: 149161022
______________________________________________________*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define T 2
struct Carro{
	char marca[15];
	int ano;
	char cor[10];
	float preco;
};
int preenche(struct Carro vet[]);
void mostrar(int i, struct Carro vet[]);
void imprimirPreco(float p, struct Carro vet[]);
void imprimirMarca(char m[], struct Carro vet[]);
void imprimirMarcaAnoCor(char m[], int a, char c[], struct Carro vet[]);
main(){
	system("color 70");
	setlocale(LC_ALL, "portuguese");
	struct Carro vet[20];
	int opc, i, a;
	float p;
	char m[15], c[10];
	preenche(vet);
	do{
		printf("1------\tPesquisar por pre�o\n2------\tPesquisar pela Marca\n3------\tVerificar se Existe um carro\n4------\tSair\n\n");
		printf("Digite a op��o desejada: ");
		scanf("%d", &opc);
		printf("\n");
		switch (opc){
			case 1:
				printf("Digite o pre�o buscado em um carro: ");
				scanf("%f", &p);
				fflush(stdin);
				printf("\n");
				imprimirPreco(p, vet);
				break;
			case 2:
				printf("Digite a Marca de interesse em um carro: ");
				scanf("%s", m);
				printf("\n");
				imprimirMarca(m, vet);
				break;
			case 3:
				printf("Para verificar se o carro existe, digite a Marca,o Ano e a Cor:\n");
				printf("Marca: ");
				scanf("%s", m);
				printf("Ano: ");
				scanf("%d", &a);
				printf("Cor: ");
				scanf("%s", c);
				printf("\n");
				imprimirMarcaAnoCor(m, a, c, vet);
				break;
			case 4:
                 printf("Saindo\n\n");
                 break;
			default:
				printf("Op��o inv�lida, digite novamente.\n\n");
		}
	}while(opc!=4);
	system("PAUSE");
}
int preenche(struct Carro vet[]){
	int i;
	for(i=0; i<T; i++){
		printf("Marca: ");
		gets(vet[i].marca);
		printf("Ano: ");
		scanf("%d", &vet[i].ano);
		fflush(stdin);
		printf("Cor: ");
		gets(vet[i].cor);
		printf("Pre�o: ");
		scanf("%f", &vet[i].preco);
		fflush(stdin);
		printf("\n");
	}
}
void mostrar(int i, struct Carro vet[]){
	printf("A marca �: %s\n", vet[i].marca);
	printf("O ano �: %d\n", vet[i].ano);
	printf("A cor �: %s\n", vet[i].cor);
	printf("O pre�o �: %.2f\n\n", vet[i].preco);
}
void imprimirPreco(float p, struct Carro vet[]){
	int i, v=0;
	for(i=0; i<T; i++){
		if(vet[i].preco <= p)
			mostrar(i, vet);
		else
		    v++;
	}
	if(v==T)
       printf("N�o foi encontrado um carro nessa faixa de pre�o.\n\n");
}
void imprimirMarca(char m[], struct Carro vet[]){
	int i, x, v=0;
	for(i=0; i<T; i++){
		x = strcmp(vet[i].marca, m);
		if(x == 0)
			mostrar(i, vet);
		else
		    v++;
	}
	if(v==T)
	   printf("N�o foi encontrado um carro com esta Marca.\n\n");
}
void imprimirMarcaAnoCor(char m[], int a, char c[], struct Carro vet[]){
	int i, x, y, v=0;
	for(i=0; i<T; i++){
		x = strcmp(vet[i].marca, m);
		y = strcmp(vet[i].cor, c);
		if (x == 0){
			if(vet[i].ano == a){
				if(y == 0)
					mostrar(i, vet);
			}
		}else
             v++;
	}
	if(v==T)
	  printf("Este carro n�o existe.\n\n");
}
