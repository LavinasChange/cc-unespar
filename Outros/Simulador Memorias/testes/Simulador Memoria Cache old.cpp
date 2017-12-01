//	Trabalho Pr�tico do 1� Bimestre
// 	Simulador de mem�ria cache
//
//  2� Ano Ci�ncias da Computa��o - UNESPAR
//
//	Bianca Lee Azuma
//	Henrique Alves da Silva

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

//Fun��o para cria��o da simula��o de uma memoria principal de tamanho 1000.
struct MemoriaPrincipal {
	int dado;
};
struct MemoriaPrincipal MP[1000];

//Fun��o para cria��o da simula��o de uma memoria cache de tamanho 10.
struct MemoriaCache {
	int dado;
	//Ponto da mem�ria principal que foi recebido o dado.
	int pontoMP;
	//Disponibilidade de utiliza��o da cache, usada de indentificador com 0 ou 1.
	int disponivel;
}; 
struct MemoriaCache MC[10];

//Fun��o para preenchimento automatico da mem�ria principal em cada posi��o.
//PMP = Preenchimento da Memoria Principal.
//PM = Posicionamento da Principal.
void PMP () {
	srand(time (NULL));
	for(int i=0;i<1000;i++){
		MP[i].dado=rand () % 100000;
	}
}

//Fun��o para preenchimento automatico da mem�ria cache em cada posi��o.
//PMC = Preenchimento da Memoria Cache.
void PMC (){
	for (int i=0;i<10;i++){
		MC[i].dado = NULL;
		MC[i].disponivel = 0;
	}
}

//Fun��o para realizar a limpeza da mem�ria cache depois de cheia, recebe o valor x para diferenciar com leitura [0] e leitura/modifica��o [1].
//c1LC = Contador 1 da Limpeza da Cache, utiliza-se para contagem de quando come�a efetuar a limpeza.
int c1LC = 0;
//c2LC = Contador 2 da Limpeza da Cache, utiliza-se para contagem de qual posi��o da cache efetuar a limpeza.
int c2LC = 0;
//LC = Limpeza da Cache.
void LC (int x){
	if (c2LC == 10) {
		c2LC = 0;
	}
	if (x == 0) {
		MC[c2LC].disponivel = 0;
		c2LC = c2LC +1;
	}
	if (x == 1){
		MP[MC[c2LC].pontoMP].dado = MC[c2LC].dado;
		MC[c2LC].disponivel = 0;
		c2LC = c2LC +1;
	}
}

//Fun��o para realizar o mapeamento associativo para armazenar dados na memoria cache.
//MA = Mapeamento Associativo.
void MA (int x, int y) {
	for (int j=0;j<10;j++){
		if (MC[j].disponivel == 0) {
			MC[j].dado = x;
			MC[j].pontoMP = y;
			MC[j].disponivel = 1;
			c1LC = c1LC +1;
			j = 10;
		} 
	}
	
}

//Fun��o para leitura de um dado.
//LD = Leitura de Dado.
void LD () {
	int p;
	printf("Informe uma posicao [0-999] da memoria principal para leitura:");
	scanf("%i",&p);
	if (p > 999){
		printf("Valor maior que 999 ou menor que 0, por favor informe novamente um valor valido !");
		getch();
		system("CLS");
		LD();
	} else {
		if (c1LC == 10) {
			c1LC = 9;
			LC(0);
		}
		MA(MP[p].dado, p);
		system("CLS");
		printf("Sua escolha retornou: \n\n");
		printf("        Memoria Principal      \n");
		printf("------------------------------\n");
		printf(" %i - %i\n", p, MP[p].dado);
		printf("------------------------------\n\n");
		printf("         Memoria Cache        \n");
		printf("------------------------------\n");
		for(int i=0;i<10;i++){
			printf(" %i - %i\n", i, MC[i].dado);
			printf("------------------------------\n");
		}
		getch();
		system("CLS");
	}
}

//Fun��o para leitura e modifica��o de um dado.
//LMD = Leitura e Modifica��o de Dado.
void LMD () {
	int p;
	printf("Informe uma posicao [0-999] da memoria principal para leitura/modificacao:");
	scanf("%i",&p);
	if (p > 999){
		printf("Valor maior que 999 ou menor que 0, por favor informe novamente um valor valido !");
		getch();
		system("CLS");
		LD();
	} else {
		if (c1LC == 10) {
			c1LC = 9;
			LC(1);
		}
		srand(time (NULL));
		int novodado=rand () % 100000;
		MA(novodado, p);
		system("CLS");
		printf("Sua escolha modificou: %i \n\n");
		printf("        Memoria Principal      \n");
		printf("------------------------------\n");
		printf(" %i - %i\n", p, MP[p].dado);
		printf("------------------------------\n\n");
		printf("         Memoria Cache        \n");
		printf("------------------------------\n");
		for(int i=0;i<10;i++){
			printf(" %i - %i\n", i, MC[i].dado);
			printf("------------------------------\n");
		}
	}
	getch();
	system("CLS");
}

//Menu para visualiza��o e intera��o com o usuario.
void Menu () {
		printf("Simulador de Memoria Cache !\n\n");
		printf("Escolha uma opcao:\n");
		printf("[1] Leitura de um dado.\n");
		printf("[2] Leitura e modificacao.\n");
		printf("[3] Finalizar.\n");
		int escolha;
		printf(">");
		scanf("%i",&escolha);
		switch (escolha) {
			case 1: {
				system("CLS");
				LD ();
				Menu ();
				break;
			}
			case 2: {
				system("CLS");
				LMD ();
				Menu ();
				break;
			}
			case 3: {
				system("CLS");
				printf("Programado por: \n\n");
				printf("Bianca Lee Azuma\n");
				printf("Henrique Alves da Silva\n\n");
				printf("2 ano, Ciencias da Computacao - UNESPAR\n\n");
				system("PAUSE");
				break;
			}
			default : {
				printf("Opcao inexistente !\n");
				getch();
				system("CLS");
				Menu ();
				break;
			}
		}
}
	
int main () {
	//Inicializando a simula��o das memorias principal e cache.
	PMP ();
	PMC ();
	//Inicializa��o do menu.
	Menu();
}
