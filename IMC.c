#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main () {
float P, H;
float IMC;
printf("Digite seu Peso: ");
scanf("%f", &P);
printf("Digite sua Altura: ");
scanf("%f", &H);
IMC=P/pow(H, 2);
printf("Seu IMC e: %.2f", IMC);
if (IMC<18.5){
  printf("\nVoce esta abaixo do Peso \n");
}else
  if ((IMC>=18.5)&&(IMC<25)){
  printf("\nSeu peso esta ideal\n");
}else
  if ((IMC>=25)&&(IMC<30)){
  printf("\nVoce esta acima do peso\n");
}else
  if (IMC>=30){
  printf("\nVoce esta obeso(a)\n");}
system("PAUSE");
}
