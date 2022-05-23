#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

	struct Ficha1{
		char nome_prod[180];
		int quantidade;
	};	

	struct Ficha2{
		char nome_compras[180];
		int quantidade_compras;	
	};

	int quantidade_produto_compras, quantidade_produto_armazem;
	struct Ficha1 arm[20];
	struct Ficha2 com[20];

void iniciar(){
	int i;
	setlocale(LC_ALL,"Portuguese");
	for(i=0;i<20;i++){
		strcpy(arm[i].nome_prod, " ");
		strcpy(com[i].nome_compras, " ");
		arm[i].quantidade=0;
		com[i].quantidade_compras=0;
		}
	}

void crir_aramazem(){	
		int i;
		setlocale(LC_ALL,"Portuguese");
		char SAIR = 0;
		FILE *armazem;
		armazem = fopen("Armazem.txt", "w");
		printf("Digite quantos produtos deseja colocar em seu armazem(M�ximo de 200 produtos): ");
		scanf("%d", &quantidade_produto_armazem);
		fflush(stdin);
		printf("Escreva o nome dos produtos desejados e sua quantidade: ");
			for(i=0; i<=quantidade_produto_armazem; i++){				
					gets(arm[i].nome_prod);
						fputs(arm[i].nome_prod, armazem);
							scanf(" %d", &arm[i].quantidade);
								fprintf(armazem, "- %d \n", arm[i].quantidade);
									
						}
		system("cls");
		fclose(armazem);
}

void criar_lista_compras(){ 
		int i;
		setlocale(LC_ALL,"Portuguese");
		char SAIR = 0;
		FILE *compras;
		compras = fopen("Lista de Compras.txt", "w");
		printf("Digite quantos produtos deseja colocar em sua lista(M�ximo de 200 produtos): ");
		scanf("%d", &quantidade_produto_compras);
		fflush(stdin);
		printf("Escreva o nome dos produtos desejados e sua quantidade: ");
			for(i=0; i<=quantidade_produto_compras; i++){				
					gets(com[i].nome_compras);
						fputs(com[i].nome_compras, compras);
							scanf(" %d", &com[i].quantidade_compras);
								fprintf(compras, "- %d \n", com[i].quantidade_compras);
						}
		system("cls");
		fclose(compras);
}

void ver_armazem_ou_lista(){
	setlocale(LC_ALL,"Portuguese");
	int z, i;
	printf("Escolha se deseja visualizar sua lista ou seu armaz�m(1 - Lista  | 2 - Armazem)");
	scanf("%d", &z);
	if(z=2){
		for(i=0; i<=quantidade_produto_armazem; i++){
			puts(arm[i].nome_prod);
			printf("\n");
			printf("%d", arm[i].quantidade);
			}
			system("pause");
			system("cls");
	}else
		for(i=0; i=quantidade_produto_compras;i++){
			puts(com[i].nome_compras);
			printf("\n");
			printf("%d", com[i].quantidade_compras);
		}
		system("pause");
		system("cls");
}

void alterar_armazem_ou_lista(){
	int i, x, z;
	setlocale(LC_ALL,"Portuguese");
	printf("Deseja alterar seu armaz�m ou sua lista de cmpras? (1 - ARMAZ�M | 2 - LISTA de COMPRAS)");
	printf("\n\nDigite sua escolha: ");
	scanf("%d", &x);
		if(x=1){
			for(i=0; i<=quantidade_produto_armazem; i++){
					printf("%d - ", i);
						puts(arm[i].nome_prod);
							printf("%d", arm[i].quantidade);
								printf("\n");
			}
			printf("Digite a linha que deseja alterar: ");
				scanf("%d", &z);
					printf("Digite o nome do produto: ");
						fflush(stdin);
							gets(arm[z].nome_prod);
								printf("Digite a quantidade do produto: ");
									scanf("%d", &arm[z].quantidade);
									system("cls");
		}else
			for(i=0; i=quantidade_produto_compras;i++){
				puts(com[i].nome_compras);
					printf("\n");
						printf("%d", com[i].quantidade_compras);
		}
		printf("Digite a linha que deseja alterar: ");
				scanf("%d", &z);
					printf("Digite o nome do produto: ");
						fflush(stdin);
							gets(com[z].nome_compras);
								printf("Digite a quantidade do produto: ");
									scanf("%d", &com[z].quantidade_compras);
									system("cls");
}

void excluir_armazem_ou_lista(){
	int i, x;
	setlocale(LC_ALL,"Portuguese");
	printf("Deseja excuir seu Armaz�m ou sua Lista? Caso tenha escolhido essa op��o por engano, apenas feche o programa.( 1 - Armaz�m | 2 - Lista )");
	printf("Op��o: ");
	scanf("%d", &x);
	if(x=1){
		for(i=0;i<20;i++){
			strcpy(arm[i].nome_prod, " ");
				arm[i].quantidade=0;
		}
	}else
		for(i=0;i<20;i++){
			com[i].quantidade_compras=0;
				strcpy(com[i].nome_compras, " ");
		}
		system("cls");
}

main()
{
	iniciar();
	setlocale(LC_ALL,"Portuguese");
	int x;
	do
	{
		printf("\tMENU	PRINCIPAL\n");
		printf("\n\n\t\t1 - Criar Armazem");
		printf("\n\n\t\t2 - Criar Lista de Compras");
		printf("\n\n\t\t3 - Visualizar Lista de Compras ou Armazem");
		printf("\n\n\t\t4 - Alterar Armazem ou Lista");
		printf("\n\n\t\t5 - Excluir Armazem ou Lista");
		printf("\n\n\t\t6 - Sair");
		printf("\n\n\n\t\t\tOp��o: ");
		scanf("%d", &x);
		fflush(stdin);
		system("cls");
			switch(x){
				case 1:	
					puts("\n\n\t\t\tOp��o Criar Armazem\n\n"); 
						crir_aramazem(); 
							break; 
				case 2: 
					puts("\n\n\t\t\tOp��o Criar Lista de Compras\n\n"); 
						criar_lista_compras(); 
							break;
				case 3: 
					puts("\n\n\t\t\tOp��o Visualizar Lista de Compras ou Armazem\n\n"); 
						ver_armazem_ou_lista(); 
							break;
				case 4:
					puts("\n\n\t\t\tOp��o Alterar Armazem/Lista\n\n");
						alterar_armazem_ou_lista();
							break;
				case 5:
					puts("\n\n\t\t\tOp��o Excluir Armazem/Lista\n\n");
						excluir_armazem_ou_lista();
							break;
				case 6:
						break; 
				default: 
					puts("\n\n\t\t\tOp��o invalida\n\n");
			}
	}
	while(x!=6);	
}	
