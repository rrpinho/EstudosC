#include <stdio.h>
#include <stdlib.h>
main () {
float K, F;
printf("Digite a temperatura em graus Kelvin: ");
scanf("%f", &K);
F=((9*K-2297)/5);
printf("Essa temperatura em Fahrenheit eh: %.2f\n", F);
system("PAUSE");
}
