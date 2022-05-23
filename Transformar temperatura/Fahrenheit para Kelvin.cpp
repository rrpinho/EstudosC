#include <stdio.h>
#include <stdlib.h>
main () {
float F, K;
printf("Digite a temperatura em graus Fahrenheit: ");
scanf("%f", &F);
K=((5*F+2297)/9);
printf("Essa temperatura em Kelvin eh: %.2f\n", K);
system("PAUSE");
}
