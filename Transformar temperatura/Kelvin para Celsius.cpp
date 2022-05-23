#include <stdio.h>
#include <stdlib.h>
main () {
float K, C;
printf("Digite a temperatura em graus Kelvin: ");
scanf("%f", &K);
C=K-273;
printf("Essa temperatura em Celsius eh: %.2f\n", C);
system("PAUSE");
}
