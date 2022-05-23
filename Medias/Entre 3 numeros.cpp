#include <stdio.h>
#include <stdlib.h>
main () {
float x1, x2, x3;
float M;
printf("Digite o primeiro numero: ");
scanf("%f", &x1);
printf("Digite o segundo numero: ");
scanf("%f", &x2);
printf("Digite o terceiro numero: ");
scanf("%f", &x3);
M=(x1+x2+x3)/3;
printf("A media eh: %.2f\n", M);
system("PAUSE");
}
