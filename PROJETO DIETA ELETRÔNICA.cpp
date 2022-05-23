GRUPO: ADRIANA SAMPAIO, TAMMY PASTORI E GABRIEL MASCARENHAS!!

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

struct dados {
		char refeicao[255];
		char nome[30];
		int  sexo;
		float peso, altura, idade;
		bool Registrado;
		float calorias_diarias, calorias_boas, proteinas, calorias_proteicas, carboidratos, calorias_carboidratos, calorias_pc, agua;
			}; 

 struct dados Pessoa[255];
 struct dados Refeicao[7][6];
 
	 	void Solicitar_dados(int i){
     	printf("Digite seu Nome: ");
	 	gets(Pessoa[i].nome);
	 	fflush(stdin);

	 	printf("Digite seu sexo(1 -Masculino/2 - Feminino): ");
	 	scanf("%d", &Pessoa[i].sexo);
	 	fflush(stdin);
    
	 while (Pessoa[i].sexo!=1 && Pessoa[i].sexo!=2){
        printf("O sexo está incorreto!\n");     
	 	printf("Digite seu sexo(1 -Masculino/2 - Feminino): ");
	 	scanf("%d", &Pessoa[i].sexo);
	 	fflush(stdin);}

	 	printf("Digite sua altura: ");
	 	scanf("%f", &Pessoa[i].altura);
	 	fflush(stdin);
	
	 	printf("Digite sua idade: ");
	 	scanf("%f", &Pessoa[i].idade);
	 	fflush(stdin);	
 	
	 	printf("Digite seus peso: ");
	 	scanf("%f", &Pessoa[i].peso);
	 	fflush(stdin);
	 	Pessoa[i].Registrado = true;
    	if(Pessoa[i].sexo = 1)
	          Pessoa[i].calorias_diarias = 66 + 13.7*Pessoa[i].peso + 5*Pessoa[i].altura - 6.8*Pessoa[i].idade; 
     	else 
	    	  Pessoa[i].calorias_diarias = 655 + 9.6*Pessoa[i].peso + 1.8*Pessoa[i].altura - 4.7*Pessoa[i].idade;
	    
	   	Pessoa[i].proteinas = 2*Pessoa[i].peso;
       	Pessoa[i].calorias_boas = Pessoa[i].calorias_diarias*0.15;
       	Pessoa[i].calorias_proteicas = 4*Pessoa[i].proteinas;
       	Pessoa[i].calorias_pc = Pessoa[i].calorias_diarias - Pessoa[i].calorias_boas;
	   	Pessoa[i].calorias_carboidratos = Pessoa[i].calorias_pc - Pessoa[i].calorias_proteicas;
       	Pessoa[i].carboidratos = (Pessoa[i].calorias_carboidratos*0.1)/(4*0.1);
       	Pessoa[i].agua = Pessoa[i].peso*0.035; 
	   	}
	   
    	void Inserir_dados(){
    	int i;
	    
		printf("Digite um número para o cadastro entre (0 e 255): ");
		scanf("%d", &i);
		fflush(stdin);
		 while (!(i>=0 && i<=255)){
        printf("O número é inválido!\n");     
	 	printf("Digite um numero para o cadastro entre (0 e 255): ");
	 	scanf("%d", &i);
	 	fflush(stdin);}
		
		if(Pessoa[i].Registrado)
			printf("Essa pessoa já foi registrada!\n");
	
		else{
			Solicitar_dados(i);
			}
  			system("Pause");
 	 		}
   	 	void Zerar_vetor (){
    	int i;
		for(i = 0; i < 255; i++){ 
    	strcpy(Pessoa[i].nome, " ");
    	Pessoa[i].sexo = 0;
 		Pessoa[i].idade = 0;
 		Pessoa[i].peso = 0;
 		Pessoa[i].altura = 0;
 		Pessoa[i].calorias_diarias = 0;
 		Pessoa[i].calorias_boas = 0;
    	Pessoa[i].proteinas = 0;
		Pessoa[i].calorias_proteicas = 0; 
		Pessoa[i].calorias_pc = 0; 					   
		Pessoa[i].calorias_carboidratos = 0;
		Pessoa[i].carboidratos = 0;						
		Pessoa[i].agua = 0;					
						}
                        }
    	void Visualizar_dados(){
 		int i;
	    int posicao;	
		printf("Digite um número para o cadastro entre (0 e 255): ");
		scanf("%d", &i);
		fflush(stdin);
		if(!(Pessoa[i].Registrado))
		printf("Essa pessoa não foi registrada!\n");
		else{
    
	   	printf("Você deve consumir %.2f calorias por dia.\nVocê deve consumir %.2f g de proteinas por dia.\n", Pessoa[i].calorias_diarias, Pessoa[i].proteinas); 
	   	printf("Você deve consumir %.2f calorias boas por dia.\n", Pessoa[i].calorias_boas);
	   	///printf("Você tem %.2f calorias proteicas e de carboidrato \nVocê tem %.2f calorias de carboidratos\n", calorias_pc, calorias_carboidratos); 
       	printf("Você deve consumir %.2f g de carboidratos por dia.\n", Pessoa[i].carboidratos);
       	printf("Você deve consumir cerca de %.1f l de água por dia.\n", Pessoa[i].agua);
	   	fflush(stdin);
	    system("Pause");
		     }
		system("Pause");
		               }
 		void Alterar_dados(){
 		int i;
 		printf("Digite um número para o cadastro entre (0 e 255): ");
		scanf("%d", &i);
		fflush(stdin);
		if(!(Pessoa[i].Registrado))
		printf("Essa pessoa ainda não foi registrada!\n");
	
		else{
		Solicitar_dados(i);
			}
    	system("Pause");
    		}  
  
		void Excluir_dados(){
		int i;
	    printf("Digite um número para o cadastro entre (0 e 255): ");
	    scanf("%d", &i);
		if(!(Pessoa[i].Registrado))
		printf("Essa pessoa ainda não foi registrada!\n");
	
		else{
    	strcpy(Pessoa[i].nome, " ");
    	Pessoa[i].sexo = 0;
 		Pessoa[i].idade = 0;
 		Pessoa[i].peso = 0;
 		Pessoa[i].altura = 0;
 		Pessoa[i].calorias_diarias = 0;
 		Pessoa[i].calorias_boas = 0;
    	Pessoa[i].proteinas = 0;
		Pessoa[i].calorias_proteicas = 0; 
		Pessoa[i].calorias_pc = 0; 					   
		Pessoa[i].calorias_carboidratos = 0;
		Pessoa[i].carboidratos = 0;						
		Pessoa[i].agua = 0;
       		}
       	system("Pause");
	   		}

		void Refeicao_dados(){
		int i,j;
	    system("color f1");
		system("cls");
		printf("\n0. Domingo\n");
    	printf("\n1. Segunda-Feira\n");
		printf("\n2. Terca-Feira\n");
	    printf("\n3. Quarta-Feira\n");
	    printf("\n4. Quinta-Feira\n");
	    printf("\n5.  Sexta-Feira\n");
		printf("\n6. Sábado\n");
	
		printf("\nEscolha um dia da semana: ");
		scanf("%d", &i);
		fflush(stdin);
		system("cls");
		printf("\nAs refeições poderão ter alimentos substituidos por outros que tenham os mesmos valores nutricionais!");
		printf("\n\n0. Cafe\n");
		printf("\n1. Lanche da manhã\n");
		printf("\n2. Almoço\n");
		printf("\n3. Lanche da tarde\n");
		printf("\n4. Janta\n");
		printf("\n5. Ceia\n");

		printf("\nEscolha uma refeição: ");
		scanf("%d", &j);
		fflush(stdin);
        system("cls");    
    	printf("%s\n", Refeicao[i][j].refeicao);
		system("Pause");
					}	
    							
	    void refeicoes_tipos(){
		strcpy (Refeicao[0][0].refeicao, "\nSeu melhor café da manhã para hoje é:\n\n\nBatata doce cozida/Banana da terra cozida\nTorrada integral com queijo Ricota\nSuco de fruta ou Iogurte com Granola\n");
    	strcpy (Refeicao[0][1].refeicao, "\nSeu melhor lanche da manhã para hoje é:\n\nSanduíche natural com queijo Cottage\nIogurte ou Suco\nFruta\nAveia em flocos");                                                                  
    	strcpy(Refeicao[0][2].refeicao, "\nSeu melhor almoço para hoje é:\n\nFeijão cozido\nArroz integral com couve-flor ou Macarrao integral(2X semana)\nFile de frango grelhado ou Carne vermelha ou Peixe\nSalada:\nAlface\nAcelga\nTomate\nPepino\nBeterraba\nCenoura crua\nAzeite de Oliva");
    	strcpy(Refeicao[0][3].refeicao, "\nSeu melhor lanche da tarde para hoje é:\n\nClara de ovo cozida\nBatata doce cozida\nFruta\nSuco de fruta\n");
		strcpy(Refeicao[0][4].refeicao, "\nSua melhor janta para hoje é:\n\nTapioca de queijo Ricota com frango\nClara de ovo cozida\nSuco de fruta\n");
		strcpy(Refeicao[0][5].refeicao, "\nSua melhor ceia para hoje é:\n\nVitamina: Leite + Fruta + Granola + Farinha láctea + Neston\n");           
		strcpy(Refeicao[1][0].refeicao, "\nSeu melhor café da manhã para hoje é:\n\nMamão\nChia\nInhame\nQueijo branco\nFatia pão integral\nSuco de fruta");
		strcpy(Refeicao[1][1].refeicao, "\nSeu melhor lanche da manhã para hoje é:\n\nSanduíche natural\nFruta\nAveia em flocos\nSuco de frutas");
		strcpy(Refeicao[1][2].refeicao, "\nSeu melhor almoço para hoje é:\n\nPurê de batata ou de aipim\nChia\nArroz integral\nFile de frango ou Peixe grelhado\nSuco de fruta\nSalada:\nAlface\nAcelga\nTomate\nPepino\nCenoura crua\nAzeite de Oliva");
		strcpy(Refeicao[1][3].refeicao, "\nSeu melhor lanche da tarde para hoje é:\n\nBatata doce cozida\nClara de ovo cozida\nSuco ou Iogurte natural");
		strcpy(Refeicao[1][4].refeicao, "\nSua melhor janta para hoje é:\n\nSopa de verdura\nTorrada integral com patê de frango\nSuco de fruta");
		strcpy(Refeicao[1][5].refeicao, "\nSua melhor ceia para hoje é:\n\nFrutas\nAveia\nCereais\nSuco de Frutas");
    	strcpy(Refeicao[2][0].refeicao, "\nSeu melhor café da manhã para hoje é:\n\nTapioca de queijo branco com peito de peru\nBanana da terra cozida ou Batata doce cozida\nSuco de fruta");
		strcpy(Refeicao[2][1].refeicao, "\nSeu melhor lanche da manhã para hoje é:\n\nSalada de frutas");
		strcpy(Refeicao[2][2].refeicao, "\nSeu melhor almoço para hoje é:\n\nSalmão grelhado\nArroz com brócolis\nPurê de batata\nChia\nSalada de verduras\nSuco de fruta");
    	strcpy(Refeicao[2][3].refeicao, "\nSeu melhor lanche da tarde para hoje é:\n\nBatata doce cozida\nFrango desfiado\nClara de ovo cozida\n1 fruta\nSuco de fruta");
    	strcpy(Refeicao[2][4].refeicao, "\nSua melhor janta para hoje é:\n\nTapioca de queijo branco com frango\nClara de ovo cozida\nSuco de fruta");
    	strcpy(Refeicao[2][5].refeicao, "\nSua melhor ceia para hoje é:\n\nFrutas variadas\nAveia ou Chia"); 
    	strcpy(Refeicao[3][0].refeicao, "\nSeu melhor café da manhã para hoje é:\n\nMelancia\nPêra\nAmeixa\nTapioca de queijo branco\nSuco de fruta ou Iogurte natural");
    	strcpy(Refeicao[3][1].refeicao, "\nSeu melhor lanche da manhã para hoje é:\n\nIogurte com frutas\nChia ou Vitamina de frutas");
    	strcpy(Refeicao[3][2].refeicao, "\nSeu melhor almoço para hoje é:\n\nArroz integral\nLentilha\nChia\nBife Bovino\nSalada:\nAlface\nAcelga\nTomate\nPepino\nCenoura crua\nAzeite de Oliva");
    	strcpy(Refeicao[3][3].refeicao, "\nSeu melhor lanche da tarde para hoje é:\n\nOmelete com Aveia integral\nIorgurte desnatado com granola ou Suco de frutas"); 
    	strcpy(Refeicao[3][4].refeicao, "\nSua melhor janta para hoje é:\n\nInhame\nQueijo branco\nPeito de peru\nSalada com linhaça dourada\nSuco de frutas");
    	strcpy(Refeicao[3][5].refeicao,"\nSua melhor ceia para hoje é:\n\nTorrada com queijo branco e geleia\nSuco de frutas"); 
    	strcpy(Refeicao[4][0].refeicao,"\nSeu melhor café da manhã para hoje é:\n\nSalada de fruta com chia\nGranola ou Linhaça adoçada com Mel");
    	strcpy(Refeicao[4][1].refeicao,"\nSeu melhor lanche da manhã para hoje é:\n\nPão integral\nPeito de frango ou atum\nQueijo Cottage ou Ricota\n Iogurte natural");
    	strcpy(Refeicao[4][2].refeicao,"\nSeu melhor almoço para hoje é:\n\nFeijão branco\nCarne de Soja\nArroz integral com cenoura\nSalada de verdura\nSuco de frutas");
    	strcpy(Refeicao[4][3].refeicao,"\nSeu melhor lanche da tarde para hoje é:\n\nClara de ovo cozida\nBatata doce cozida\nPeixe cozido\nSuco de fruta");
    	strcpy(Refeicao[4][4].refeicao,"\nSua melhor janta para hoje é:\n\nBatata doce gratinada com recheio de carne\nArroz integral com brócolis\nSalada\nSuco de fruta");
    	strcpy(Refeicao[4][5].refeicao,"\nSua melhor ceia para hoje é:\n\nSalada de frutas com queijo Cottage\n");
    	strcpy(Refeicao[5][0].refeicao,"\nSeu melhor café da manhã para hoje é:\n\nCrepioca de queijo branco\nFrutas variadas\nAipim ou inhame\nSuco de fruta");
    	strcpy(Refeicao[5][1].refeicao,"\nSeu melhor lanche da manhã para hoje é:\n\nSanduíche natural\nQueijo branco\nPeito de peru\nSalada\nIorgurte ou Suco de fruta");
    	strcpy(Refeicao[5][2].refeicao,"\nSeu melhor almoço para hoje é:\n\nMacarrão integral ou Arroz integral\nGrão de bico\nFigado grelhado ou Peito de frango grelhado\nSuco de fruta\nSalada:\nAlface\nAcelga\nTomate\nPepino\nCenoura crua\nAzeite de Oliva");
    	strcpy(Refeicao[5][3].refeicao,"\nSeu melhor lanche da tarde para hoje é:\n\nFrango grelhado\nBanana terra cozida\nVagem\nBatata doce cozida\nSuco de fruta");
    	strcpy(Refeicao[5][4].refeicao,"\nSua melhor janta para hoje é:\n\nPicadinho de verduras com frango cozido\nArroz integral com cenoura\nSuco de frutas");
    	strcpy(Refeicao[5][5].refeicao,"\nSua melhor ceia para hoje é:\n\nAbacate ou Melão com aveia\nIogurte natural");
    	strcpy(Refeicao[6][0].refeicao,"\nnSeu melhor café da manhã para hoje é:\n\nVitamina de frutas\nCereais");
    	strcpy(Refeicao[6][1].refeicao,"\nSeu melhor lanche da manhã para hoje é:\n\nSanduíche natural\nQueijo Cottage ou Ricota\nSuco de fruta");
    	strcpy(Refeicao[6][2].refeicao,"\nSeu melhor almoço para hoje é:\n\nFeijão de caldo\nMacarrão integral\nFile de frango grelhado ou carne vermelha\nSuco de fruta\nSalada de verdura ou folhas");
    	strcpy(Refeicao[6][3].refeicao,"\nSeu melhor lanche da tarde para hoje é:\n\nOmelete de tomate com espinafre\nQueijo de búfula\nBanana\nSuco de fruta");
    	strcpy(Refeicao[6][4].refeicao,"\nSua melhor janta para hoje é:\n\nSopa de verduras\nTorrada integral com geleia\nSuco de fruta");
    	strcpy(Refeicao[6][5].refeicao,"\nSua melhor ceia para hoje é:\n\nVitamina: Leite + Fruta + Granola + Farinha láctea + Neston\n");
        }

    
        main(){
   	    Zerar_vetor();
        refeicoes_tipos();
   	    setlocale(LC_ALL, "portuguese");
        int Opcao = 0;
        while(Opcao != 6){
        system("color f1");
	    system("cls");
	    printf("\t\t\t      >>>>>DIETA ELETRÔNICA<<<<<\n\n\n\n");
	 	printf("Menu de opções: \n");
	 	printf("\n1. Inserir Dados\n");
	 	printf("2. Alterar Dados\n");
	 	printf("3. Visualizar Dados\n");
	 	printf("4. Excluir Dados\n");
	 	printf("5. Visualizar Refeições\n");
	 	printf("6. Encerrar\n");	
     	printf("\nDigite a opção que deseja: ");
  	 	scanf("%d", &Opcao);
	 	fflush(stdin);
	
	 		switch (Opcao){
		 		case 1: Inserir_dados();
					break;
         		case 2: Alterar_dados(); 	
                	break;
	     		case 3: Visualizar_dados();
                	break;
	     		case 4: Excluir_dados();
                	break;
         		case 5: Refeicao_dados(); 
                	break;
                   }  
                   }
	               }   

