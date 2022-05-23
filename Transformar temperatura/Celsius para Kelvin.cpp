#include <stdio.h>
#include <stdlib.h>
main () {
float C, K;
printf("Digite a temperatura em graus celsius: ");
scanf("%f", &C);
K=C+273;
printf("Essa temperatura em Kelvin eh: %.2f\n", K);
system("PAUSE");
}
