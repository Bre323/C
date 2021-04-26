#include <stdio.h>
#include <stdlib.h>

char Refrigerantes[4][7] = {"Pepsi", "Fanta", "Sprite", "Kuat"};
float ValRefri[4] = {1.50, 1.75, 2.00, 1.75};  
int opt;
float M025 = 0.25;
float M050 = 0.50;
float M100 = 1.00;
float x = 0;

int main(){
	
printf("MAQUINA DE REFRI\n");
printf("Valor: R$0,00\n\n\n");
printf("Botao 1\t");
printf("Botao 2\t");
printf("Botao 3\t");
printf("Botao 4\t");
scanf("%d", &opt);

  if(opt == 1){
  	do{
    x = x + M025;
    system("cls");
    printf("MAQUINA DE REFRI\n");
    printf("Valor: R$%f\n\n\n", x);
    printf("Botao 1\t");
	printf("Botao 2\t");
	printf("Botao 3\t");
	printf("Botao 4\t");
	scanf("%d", &opt);
	}while(opt == 1);
}
  else if(opt == 2){
  	do{
    x = x + M050;
    system("cls");
    printf("MAQUINA DE REFRI\n");
    printf("Valor: R$%d\n\n\n", x);
    printf("Botao 1\t");
	printf("Botao 2\t");
	printf("Botao 3\t");
	printf("Botao 4\t");
	scanf("%d", &opt);
	}while(opt == 2);
}
  else if(opt == 3){
  	do{
    x = x + M100;
    system("cls");
    printf("MAQUINA DE REFRI\n");
    printf("Valor: R$%f\n\n\n", x);
    printf("Botao 1\t");
	printf("Botao 2\t");
	printf("Botao 3\t");
	printf("Botao 4\t");
	scanf("%d", &opt);
	}while(opt == 3);
}
  else if(opt == 4){
  	system("cls");
    printf("\tSERIAL PRINT\n");
    printf("========================\n");
    printf("Saldo Recebido: ");
    printf("R$%d\n", x);
    printf("========================\n");
    printf("\nEscolha um refri\n");
    
  }
  else{
  	printf("MAQUINA DE REFRI\n");
	printf("Valor: R$0,00\n\n\n");
	printf("Botao 1\t");
	printf("Botao 2\t");
	printf("Botao 3\t");
	printf("Botao 4\t");
	scanf("%d", &opt);
  }
}
