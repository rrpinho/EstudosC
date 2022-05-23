#include <stdio.h>
#include <stdlib.h>
main () {
float F, C;
printf("Digite a temperatura em graus Fahrenheit: ");
scanf("%f", &F);
C=((5*(F-32))/9);
printf("Essa temperatura em Celsius eh: %.2f\n", C);
system("PAUSE");
}
