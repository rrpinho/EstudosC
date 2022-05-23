/***********************************************************************************
                            AGENDA VIRTUAL 1.0
Projeto desenvolvido por alunos do primeiro semestre de Eng. Mecatrônica da UNIFACS.
Solicitado pela matéria de Algoritmos e programação.
Desenvolvedores:
Italo Hiago Lopes da Silva;
Tiago Santos Cruz;
Gabriel Abud Hereda Byron;
************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>


struct Dados{
	char Compromisso[255];
	char Observacao[255];
	bool Agendado;
};

	struct Dados Data[31][12][250][24];


void Cabecalho(){
	system("cls");
   	printf("\n\n\t\t_*_*_*_*_*_*_*_*_AGENDA VIRTUAL_*_*_*_*_*_*_*_*_ \n\n\n\n");
    printf("\t\t\t\t    ");
    system("date/t");
    printf("\n\t\t\t\t      ");
    system("time/t");   	
    printf("\n\n\n");
}


void Zerar_Struct(int i, int j, int k, int w){
	strcpy(Data[i][j][k][w].Compromisso, " ");
	strcpy(Data[i][j][k][w].Observacao, " ");
	Data[i][j][k][w].Agendado = false;
}


void Zerar_Matriz(){
	int i, j, k, w;
	
	for(i = 0; i < 31; i++){
		for(j = 0; j < 12; j++ ){
			for(k = 0; k < 250; k++){
				for(w = 0; w < 24; w++)
					Zerar_Struct(i, j, k, w);
			}			
		}
	}
}


void Solicitar_Senha(){
	char senha[10];
		
	printf("Insira a senha: ");
	scanf("%s", &senha);
	fflush(stdin);
	
	while(strcmp(senha, "Adm123") != 0){
	  printf("Senha incorreta, tente novamente!\n");
	  printf("Insira a senha novamente: ");
	  scanf("%s", &senha);
	  fflush(stdin);
                                       }
}


int Retornar_ao_Menu(){
	char Retorno[250];
   	printf("\n\n[Digite 1 para Retornar ao menu]\n");
   	gets(Retorno);
   	if(strcmp(Retorno, "1") == 0)
   	    return 1;
   	else
   		return 5;
}


bool Verificar_Data(int dia, int mes, int ano, int *Dia, int *Mes, int *Ano){
	
	*Dia = dia - 1;
	*Mes = mes - 1;
	*Ano = ano - 2016;
	
	if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
		if(!(dia >= 1 && dia <= 31))
			printf("Dia inválido... Verifique e tente novemente!\n");														
		else
			return true;

																				   }
	
	else if(mes == 2){
		if(ano%4 == 0){
			if(!(dia >= 1 && dia <= 29))
				printf("Dia inválido... Verifique e tente novemente!\n");
			else
				return true;
					  }
		else {
			if(!(dia >= 1 && dia <= 28))
				printf("Dia inválido... Verifique e tente novemente!\n");
			else
				return true;
			 }
					 }
	
	else if(mes == 4|| mes == 6|| mes == 9|| mes == 11){
		if(!(dia >= 1 && dia <= 30))
			printf("Dia inválido... Verifique e tente novemente!\n");														
		else
			return true;
		}
	else{
		if(!(dia >= 1 && dia <= 31))
			printf("Dia e mês inválidos... Verifique e tente novemente!\n");
		else
			printf("Mês inválido... Verifique e tente novemente!\n");
	}
	return false;
}


void Solicitar_Matriz(int *Dia, int *Mes, int *Ano, int *Horario){
	printf("Qual a data do compromisso?[Formato DD.MM.AAAA]\n");
	scanf("%d.%d.%d", &*Dia, &*Mes, &*Ano);
	fflush(stdin);
	
	while(!(Verificar_Data(*Dia, *Mes, *Ano, &*Dia, &*Mes, &*Ano))){
		printf("Qual a data do compromisso?[Formato DD.MM.AAAA]\n");
		scanf("%d.%d.%d", &*Dia, &*Mes, &*Ano);
		fflush(stdin);
	}
	
	printf("Em qual horário iniciará esse compromisso? [00 - 23]\n");
	scanf("%d", &*Horario);
	fflush(stdin);
	while(*Horario < 0 || *Horario > 23){
		printf("Por favor digite um horário entre 0 e 23!\n");
		printf("Em qual horário iniciará esse compromisso? [00 - 23]\n");
		scanf("%d", &*Horario);
		fflush(stdin);
	}
}


void Agendar_Compromisso(){
	int Dia, Mes, Ano, Horario;
	
	printf("\t\t\tAgendamento de compromisso\n\n\n");
	Solicitar_Matriz(&Dia, &Mes, &Ano, &Horario);
	
	if(!(Data[Dia][Mes][Ano][Horario].Agendado)){
		
		Solicitar_Senha();
		
		printf("Qual o compromisso que gostaria de agendar?\n");
		gets(Data[Dia][Mes][Ano][Horario].Compromisso);
		fflush(stdin);
		
	
		printf("Qual observação deseja adicionar ao compromisso?\n");
		gets(Data[Dia][Mes][Ano][Horario].Observacao);
		fflush(stdin);
	
		Data[Dia][Mes][Ano][Horario].Agendado = true;
		printf("Compromisso agendado com sucesso!\n");
	}
	
	else
		printf("Desculpe, já existe compromisso agendado para esse horário!\n");
	
}	


void Visualizar_Compromissos(){
	int Opcao;
	int Dia, Mes, Ano, Horario;
	bool Existe_Compromisso = false;
	
	printf("\t\t\tVisualização de compromissos\n\n\n");
	printf("1.Ver data\n");
	printf("2.Ver específico\n");
	printf("3.Ver todos\n");
	printf("\nDigite a opção desejada: ");
	scanf("%d", &Opcao);
	fflush(stdin);
	
	switch(Opcao){
		
		case 1: 
				
				printf("Qual a data do compromisso?[Formato DD.MM.AAAA]\n");
				scanf("%d.%d.%d", &Dia, &Mes, &Ano);
				fflush(stdin);
				Dia--;
				Mes--;
				Ano -= 2016;
				
				for(Horario = 0; Horario <= 23; Horario++){
					if(Data[Dia][Mes][Ano][Horario].Agendado)
						Existe_Compromisso = true;
				}
				
				Dia++;
				Mes++;
				Ano += 2016;
				
				if(Existe_Compromisso){
					Solicitar_Senha();
					printf("-------------------------------------------------------------------------------\n");
					printf("\t\t\t\t");
					if(Dia < 10)
						printf("0%d.", Dia);
					else
						printf("%d.", Dia);
					if(Mes < 10)
						printf("0%d.", Mes);
					else
						printf("%d.", Mes);
					printf("%d", Ano);
										
					Dia--;
					Mes--;
					Ano -= 2016;
					for(Horario = 0; Horario <= 23; Horario++){
						if(Data[Dia][Mes][Ano][Horario].Agendado){
							printf("\n\n\n");
							if(Horario < 10)
								printf("Horário de início: 0%dHrs\nCompromisso: %s.\n", Horario, Data[Dia][Mes][Ano][Horario].Compromisso);					
							else
								printf("Horário de início: %dHrs\nCompromisso: %s.\n", Horario, Data[Dia][Mes][Ano][Horario].Compromisso);
							printf("Observação: %s.", Data[Dia][Mes][Ano][Horario].Observacao);
						}					
					}	
				}
				else
					printf("Desculpe, não existe compromisso agendado nesta data!\n");	
					
				break;
				
		case 2:
			
				printf("Qual a data do compromisso?[Formato DD.MM.AAAA]\n");
				scanf("%d.%d.%d", &Dia, &Mes, &Ano);
				fflush(stdin);
				
				printf("Em qual horário iniciará esse compromisso? [00 - 23]\n");
				scanf("%d", &Horario);
				fflush(stdin);
				
				Dia--;
				Mes--;
				Ano -= 2016;
				
					if(Data[Dia][Mes][Ano][Horario].Agendado){
			                Solicitar_Senha();
							Dia++;
							Mes++;
							Ano += 2016;
							
							printf("-------------------------------------------------------------------------------\n");
							printf("\t\t\t\t");
							if(Dia < 10)
								printf("0%d.", Dia);
							else
								printf("%d.", Dia);
							if(Mes < 10)
								printf("0%d.", Mes);
							else
								printf("%d.", Mes);
							printf("%d", Ano);
							
							Dia--;
							Mes--;
							Ano -= 2016;
							
							printf("\n\n\n");
							if(Horario < 10)
								printf("Horário de início: 0%dHrs\nCompromisso: %s.\n", Horario, Data[Dia][Mes][Ano][Horario].Compromisso);					
							else
								printf("Horário de início: %dHrs\nCompromisso: %s.\n", Horario, Data[Dia][Mes][Ano][Horario].Compromisso);
							printf("Observação: %s.", Data[Dia][Mes][Ano][Horario].Observacao);
						}
					
					else
						printf("Desculpe, não existe este compromisso agendado!\n");
					
					break;	
		
		
		case 3:  
				Solicitar_Senha();
				for(Dia = 0; Dia < 31; Dia++){
					for(Mes = 0; Mes < 12; Mes++){
						for(Ano = 0; Ano < 250; Ano++){
							for(Horario = 0; Horario < 24; Horario++){
								
								if(Data[Dia][Mes][Ano][Horario].Agendado){
									Dia++;
									Mes++;
									Ano += 2016;
							
									printf("\n-------------------------------------------------------------------------------\n");
									printf("\t\t\t\t");
									if(Dia < 10)
										printf("0%d.", Dia);
									else
										printf("%d.", Dia);
									if(Mes < 10)
										printf("0%d.", Mes);
									else
										printf("%d.", Mes);
									printf("%d", Ano);
							
									Dia--;
									Mes--;
									Ano -= 2016;
									for(Horario; Horario < 24; Horario++){
								
									if(Data[Dia][Mes][Ano][Horario].Agendado){
									printf("\n\n\n");
									if(Horario < 10)
										printf("Horário de início: 0%dHrs\nCompromisso: %s.\n", Horario, Data[Dia][Mes][Ano][Horario].Compromisso);					
									else	
										printf("Horário de início: %dHrs\nCompromisso: %s.\n", Horario, Data[Dia][Mes][Ano][Horario].Compromisso);
									printf("Observação: %s.", Data[Dia][Mes][Ano][Horario].Observacao);
										}
									}					
								}								
							}
						}
					}
				}
				break;			
		
		default: printf("\n\nOpção inválida!\n");					
	}
}


void Alterar_Compromisso(){
	int Dia, Mes, Ano, Horario;
	
	printf("\t\t\tAlteração de compromisso\n\n\n");
	Solicitar_Matriz(&Dia, &Mes, &Ano, &Horario);
	
	if(Data[Dia][Mes][Ano][Horario].Agendado){
		Solicitar_Senha();
		Zerar_Struct(Dia, Mes, Ano, Horario);
		
		printf("Qual o compromisso que gostaria de agendar?\n");
		gets(Data[Dia][Mes][Ano][Horario].Compromisso);
		fflush(stdin);
		
		printf("Qual observação deseja adicionar ao compromisso?\n");
		gets(Data[Dia][Mes][Ano][Horario].Observacao);
		fflush(stdin);
		
		Data[Dia][Mes][Ano][Horario].Agendado = true;
		printf("Compromisso alterado com sucesso!");
	}	
	else
		printf("Desculpe, não existe este compromisso agendado!\n");
}


void Cancelar_Compromissos(){
	int Opcao;
	int Dia, Mes, Ano, Horario;
	
	printf("\t\t\tCancelamento de compromissos\n\n\n");
	printf("1.Cancelar data\n");
	printf("2.Cancelar específico\n");
	printf("3.Cancelar todos\n");
	printf("\nDigite a opção desejada: ");
	scanf("%d", &Opcao);
	fflush(stdin);

	switch(Opcao){
		
		case 1: 
				Solicitar_Senha();
				printf("Qual a data que deseja cancelar?[Formato DD.MM.AAAA]\n");
				scanf("%d.%d.%d", &Dia, &Mes, &Ano);
				fflush(stdin);
				Dia--;
				Mes--;
				Ano -= 2016;
				
				for(Horario = 0; Horario < 23; Horario++)
					Zerar_Struct(Dia, Mes, Ano, Horario);
				
				printf("Data cancelada com sucesso!\n");
				break;
				
		case 2:
				Solicitar_Senha();
				Solicitar_Matriz(&Dia, &Mes, &Ano, &Horario);
				if(Data[Dia][Mes][Ano][Horario].Agendado){
					Zerar_Struct(Dia, Mes, Ano, Horario);
					printf("Compromisso cancelado com sucesso!\n");
				}
					
				else
					printf("Desculpe, não existe este compromisso agendado!\n");
				break;
		
		case 3: 
				Solicitar_Senha();
				Zerar_Matriz();
				printf("Compromissos cancelados com sucesso!\n");
				break;
		
		default: 
				printf("Opção inválida!\n");	
	}
}


main(){
	bool Tentativa = false;
	int Opcao;
	
	setlocale(LC_ALL, "portuguese");
	Zerar_Matriz();
	Cabecalho();
	Solicitar_Senha();
	
	system("color f0");
	while(Opcao != 5){
		Cabecalho();
		if(!(Tentativa))
			printf("\a\nBem-vindo Usuário, escolha o que deseja fazer ==>\n\n"); 
		else
			printf("\a\nOpção inválida, tente novamente!\n\n");
		printf("Menu de opções:\n");
		printf("1.Agendar Compromisso\t");
		printf("2.Cancelar Compromissos\n");
		printf("3.Alterar Compromisso\t");
		printf("4.Visualizar Compromissos\n");
		printf("5.Encerrar programa\n\n");
		
		printf("Digite o número correspondente a tarefa: ");
		scanf("%d", &Opcao);
		fflush(stdin);
		
		if(!(Opcao >= 1 && Opcao <= 5))
			Tentativa = true;
		else
			Tentativa = false;
		
		switch(Opcao){
			
			case 1: Cabecalho();
					Agendar_Compromisso();
					Opcao = Retornar_ao_Menu();
					break;
			
			case 2:	Cabecalho();
					Cancelar_Compromissos();
					Opcao = Retornar_ao_Menu();
					break;
					
			case 3: Cabecalho();
					Alterar_Compromisso();
					Opcao = Retornar_ao_Menu();
					break;
					
					
			case 4: Cabecalho();
					Visualizar_Compromissos();
					Opcao = Retornar_ao_Menu();
					break;
				
								
					 }
		
				  }
}
