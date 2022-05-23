#include <stdio.h>
#include <stdlib.h>
int opcao;
float F, K, C;
void Celsius_Fahrenheits() {
	printf("\nDigite a temperatura em Celsius.: ");
	scanf("%f", &C);
	F=((9*C + 160)/5);
	printf("\nA temperatura em Fahrenheits = %.2f\n", F);
}
void Celsius_Kelvin() {
	printf("\nDigite a temperatura em Celsius.: ");
	scanf("%f", &C);
	K=C+273;
	printf("\nA temperatura em Kelvin = %.2f\n", K);
}
void Fahreinheit_Celsius() {
	printf("\nDigite a temperatura em Fahreinheit.: ");
	scanf("%f", &F);
	C=((5*(F-32))/9);
	printf("\nA temperatura em Celsius = %.2f\n", C);
}
void Fahrenheit_Kelvin() {
	printf("\nDigite a temperatura em Fahreinheit.: ");
	scanf("%f", &F);
	K=((5*F+2297)/9);
	printf("\nA temperatura em Kelvin = %.2f\n", K);
}
void Kelvin_Celsius() {
	printf("\nDigite a temperatura em Kelvin.: ");
	scanf("%f", &K);
	C=K-273;
	printf("\nA temperatura em Celsius = %.2f\n", C);
}
void Kelvin_Fahrenheit() {
	printf("\nDigite a temperatura em Kelvin.: ");
	scanf("%f", &K);
	F=((9*K-2297)/5);
	printf("\nA temperatura em Fahreinheit = %.2f\n", F);
}

main () {
	printf("\n1-Celsius -> Fahrenheits\n2-Celsius -> Kelvin\n3-Fahrenheits -> Celsius\n4-Fahrenheits -> Kelvin\n5-Kelvin -> Celsius\n6-Kelvin -> Fahrenheits\n7-Sair\n\nopcao.: ");
	scanf("%d", &opcao);
	switch (opcao) {
		case 1:
			Celsius_Fahrenheits();
			break;
		case 2:
			Celsius_Kelvin();
			break;
		case 3:
			Fahreinheit_Celsius();
			break;
		case 4:
			Fahrenheit_Kelvin();
			break;
		case 5:
			Kelvin_Celsius();
			break;
		case 6:
			Kelvin_Fahrenheit();
			break;
		case 7:
			printf("\nFinalizando o programa...\n");
			break;
		default:
			printf("\nErro! Opcao inexistente.\n");
			break;
	}
	system("PAUSE");
}
