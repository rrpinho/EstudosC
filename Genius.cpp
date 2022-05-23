/*______________________________________________________
Universidade Salvador
Curso: Engenharia Mecatrônica
Matéria: Linguagem de Programação
Professor(a): Christianne Dalforno
Aluno: Rafael Pinho de Sousa Ribeiro
Matricula: 149161022
______________________________________________________*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include<windows.h>
int Jogo(int nivel, int dificuldade);
void gerarSequencia(int subNivel, int aleatorio[], int dificuldade);
main (){
	system("color 70");
	setlocale(LC_ALL, "portuguese");
	printf("\t\t\tBem-vindo ao Gênius!!!\n\n");
	printf("Este é um jogo da memória. Será apresentado uma sequência, e em seguida o Srº(a) irá repetir a sequência.\n");
	printf("Sempre que acertar, uma nova sequência será gerada. A cada acerto será adicionado um número. E a cada 10 acertos os números serão maiores.\n\n");
	printf("\t\t\tBoa sorte e vamos ao jogo\n\n");
	printf("Digite 0 (zero) a qualquer momento para sair\n\n");
	system("PAUSE");
	int nivel=1, dificuldade=3, sair=1;
	while(sair!=0){
	sair = Jogo(nivel, dificuldade);
	nivel++;
	dificuldade = nivel*3;
	}
	printf("\n\n\t\tObrigado por jogar Gênius, até a próxima\n\n");
	system("PAUSE");
}
int Jogo(int nivel, int dificuldade){
	int i, j, k, aleatorio[10], leitura[10], subNivel=1, confirmacao=0, tempo=3000;
	while(subNivel<11){
	system("cls");
	printf("\t\t\t###Gênius###\n\n");
	if((subNivel > 1) && (confirmacao == subNivel-1))
		printf("Você acertou!\n\n");
	else 
		if((subNivel > 1) && (confirmacao != subNivel-1))
			printf("Você errou!\n\n");
	confirmacao=0;
	printf("Nível: %d\n", nivel);
		gerarSequencia(subNivel, aleatorio, dificuldade);
		Sleep(tempo);
		system("cls");
		printf("\t\t\t###Gênius###\n\n");
		for(j=0; j<subNivel; j++){
			printf("Digite o %d° número da sequência: ", j+1);
			scanf("%d", &leitura[j]);
			if(leitura[j] == 0)
			return 0;
		}
		for(k=0; k<subNivel; k++){
			if(leitura[k] == aleatorio[k])
				confirmacao++;
		}
		if(confirmacao != subNivel){
			subNivel--;
			tempo-=1000;
		}
		tempo+=1000;
		subNivel++;
	}
	printf("\n\n\n\t\tParabéns, você completou o nível %d\n", nivel);
	printf("\t\tVamos para o próximo nível\n\n");
	system("PAUSE");
	return 1;
}
void gerarSequencia(int subNivel, int aleatorio[], int dificuldade){
    srand(time(NULL));
    printf("A sequência %d é: ", subNivel);
    for(int i=0; i<subNivel; i++){
             aleatorio[i] = 1 + (rand() %dificuldade);
             printf("%d ", aleatorio[i]);
    }
}
