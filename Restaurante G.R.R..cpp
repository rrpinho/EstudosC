/*______________________________________________________
Unifacs
Curso: Engenharia Mecatr�nica
Mat�ria: Algoritmos e Programa��o
Alunos:                              - Matricula:
Rafael Pinho de Sousa Ribeiro        - 149161022
Rodrigo de Jesus Cirqueira de Ara�jo - 149161043
Grabriel Cardoso Barreto dos Santos  - 149161011

               Restaurante G.R.R
______________________________________________________*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
char nome [50];
char telefone [50];
int X,Y,Z,opc;
float x=0,y=0,z=0;
int contX=1,contY=1,contZ=1,contA=0;
float Total,Conta;
void cadastro(){
  printf("Digite seu nome: ");
  gets(nome);
  contA++;
  printf("Digite seu telefone: ");
  gets(telefone);
                }
void Refeicao(){
 while(contX==1){
  printf("\nRefei��es: ");
  printf("\nOp��es\t\t\tValor");
  printf("\n1-Feijoada \t\tR$18\n2-Lasanha \t\tR$15\n3-Macarronada \t\tR$14\n4-Churrasco \t\tR$25\n5-Moqueca de Peixe \tR$32\n6-Estrogonofe \t\tR$15\n7-Cozido \t\tR$22\n8-Bife Acebolado \tR$18\n\n");
  scanf("%d", &X);
  switch(X) {
    case 1:
	  printf("A Op��o escolhida foi: Feijoada\n\n");
	  x=18;
	  contX++;
	  break;
	case 2:
	  printf("A Op��o escolhida foi: Lasanha\n\n");
	  x=15;
	  contX++;
	  break;
	case 3:
	  printf("A Op��o escolhida foi: Macarronada\n\n");
	  x=14;
	  contX++;
	  break;
	case 4:
	  printf("A Op��o escolhida foi: Churrasco\n\n");
	  x=25;
	  contX++;
	  break;
	case 5:
	  printf("A Op��o escolhida foi: Moqueca de Peixe\n\n");
	  x=32;
	  contX++;
	  break;
	case 6:
	  printf("A Op��o escolhida foi: Estrogonofe\n\n");
  	  x=15;
	  contX++;
	  break;
	case 7:
	  printf("A Op��o escolhida foi: Cozido\n\n");
	  x=22;
	  contX++;
	  break;
	case 8:
	  printf("A Op��o escolhida foi: Bife Acebolado\n\n");
	  x=18;
	  contX++;
	  break;
	default:
	  printf("Digite uma das op��es v�lidas.\n");
               }
                }
				}
void Bebida(){
 while(contY==1){
  printf("Bebidas: ");
  printf("\nOp��es\t\t\tValor");
  printf("\n1-Pepsi \t\tR$4.50\n2-Coca-Cola \t\tR$4.50\n3-Ant�rtica \t\tR$4.50\n4-Suco de Lim�o \tR$5.50\n5-Skol Beats \t\tR$4.00\n6-Schin \t\tR$4.00\n7-Nenhuma Bebida\n\n");
  scanf("%d", &Y);
  switch(Y) {
   case 1:
	printf("A Op��o escolhida foi: Pepsi\n\n");
	y=4.50;
	contY++;
	break;
   case 2:
	printf("A Op��o escolhida foi: Coca-Cola\n\n");
	y=4.50;
	contY++;
	break;
   case 3:
	printf("A Op��o escolhida foi: Antartica\n\n");
	y=4.50;
	contY++;
	break;
   case 4:
	printf("A Op��o escolhida foi: Suco de Lim�o\n\n");
	y=5.50;
	contY++;
	break;
   case 5:
	printf("A Op��o escolhida foi: Skol Beats\n\n");
	y=4;
	contY++;
	break;
   case 6:
	printf("A Op��o escolhida foi: Schin\n\n");
	y=4;
	contY++;
	break;
   case 7:
	printf("Voc� n�o quer nenhuma Bebida.\n\n");
	y=0;
	contY++;
	break;
   default:
	printf("Digite uma das op��es v�lidas.\n");
             }
              }   
			  }
void Sobremesa(){
 while(contZ==1){
  printf("Sobremesas: ");
  printf("\nOp��es\t\t\tValor");
  printf("\n1-Bolo de Chocolate \tR$4.00\n2-Pudim \t\tR$5.00\n3-Mousse de Maracuj� \tR$5.00\n4-Nenhuma Sobremesa\n\n");
  scanf("%d", &Z);
  switch(Z) {
   case 1:
	printf("A Op��o escolhida foi: Bolo de Chocolate\n\n");
	z=4;
	contZ++;
	break;
   case 2:
	printf("A Op��o escolhida foi: Pudim\n\n");
	z=5;
	contZ++;
	break;
   case 3:
	printf("A Op��o escolhida foi: Mousse de Maracuja\n\n");
	z=5;
	contZ++;
	break;
   case 4:
	printf("Voce n�o quer nenhuma Sobremesa.\n\n");
	z=0;
	contZ++;
	break;
   default:
	printf("Digite uma das op��es v�lidas.\n");
            }
              }
	}
main () {
setlocale(LC_ALL, "portuguese");
system("color 70");
printf("\t\t\tBem Vindo ao restaurante G.R.R\n");
while(contA==0){
	printf("\nDigite o n�mero correspondente a op��o desejada e em seguida aperte Enter:\n\n 1-Cadastro\n 2-Cardapio\n\n ");
	scanf("%d", &opc);
	fflush(stdin);
	switch (opc){
	 	case 1:
	 		cadastro();
	 		system("cls");
	 		printf("\n\t\tAgora escolha sua refei��o: ");
	 		printf("\nDigite o n�mero correspondente a op��o desejada:\n\n ");
	 		Refeicao();
	 		Bebida();
	 		Sobremesa();
	 		contA++;
	 		break;
		case 2:
			system("cls");
	 		printf("\n\t\tAgora escolha sua refei��o: ");
	 		printf("\nDigite o n�mero correspondente a op��o desejada:\n\n ");
		 	Refeicao();
		 	Bebida();
		 	Sobremesa();
			contA++;
		 	break;
	 		default:
	 		printf("Digite uma das op��o v�lida");
	 		break;
			}
			  } 
Total=x+y+z;
 if(Total<25){
  Conta=Total;
  printf("\n\nSr(a)%s a sua conta ficou no valor de: R$%.2f\n\n", nome, Conta);
 }else
  if ((Total>=25)&&(Total<31)) {
    Conta=Total-(Total*0.10);
  	printf("\n\nSr(a)%s a sua conta com um desconto de 10%% ficou no valor de: R$%.2f\n\n", nome, Conta);
  }if (Total>=31) {
  	Conta=Total-(Total*0.15);
	printf("\n\nSr(a)%s a sua conta com um desconto de 15%% ficou no valor de: R$%.2f\n\n", nome, Conta);
                  }
system("PAUSE");
}
