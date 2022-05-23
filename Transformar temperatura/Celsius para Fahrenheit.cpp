#include <stdio.h>
#include <stdlib.h>
main () {
float C, F;
printf("Digite a temperatura em graus celsius: ");
scanf("%f", &C);
F=(C/5)*9+32;
printf("Essa temperatura em Fahrenheit eh: %.2f\n", F);
system("PAUSE");
}
