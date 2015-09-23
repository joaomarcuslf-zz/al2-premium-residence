#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library/high_syntax.h"
#include "Library/variaveis.h"

int main (void)
{
	int bloco, nquarto, napto, andar, coluna, validador;

	preparar();

	int panel();
	while(true) {
		validador = panel();

		if(validador==0) {
			break;
		}
		else if(validador==1){
			checar_diponibilidade();
		}
	}
	while(true)
	{
		printf("\nDigite o bloco desejado: ");
		scanf("%d", &bloco);

		if(bloco>=5 or bloco<=0)
		{
			printf("\nErro. Bloco inexistente.\nDigite o bloco desejado(de 1 a 4): ");
			scanf("%d", &bloco);
		}
		else
		{
			break;
		}
	}

	//mostra quantidade de apartamentos disponiveis no bloco (b)

		while(true)
	{
		printf("\nQuantidade de quartos desejada: ");
		scanf("%d", &nquarto);

		if(nquarto>=4 or nquarto<=0)
		{
			printf("\nErro.\nDigite uma quantidade de quartos valida (de 1 a 3): ");
			scanf("%d", &nquarto);
		}
		else
		{
			break;
		}
	}
	//quantidade de apartamentos disponiveis por numero de quartos
	while(true) {
		printf("\nDigite o numero do apartamento desejado: ");
		scanf("%d", &napto);
		andar=(napto/100);
		coluna=(napto/10);

		if(apartamento[bloco-1][andar-1][coluna-1]=='D')
		{
			printf("\nDisponivel");
		}
		else
		{
			if(apartamento[bloco-1][andar-1][coluna-1]=='R') {
				printf("\nO apartamento está reservado");
			}
			else {
				printf("\nApartamento vendido");
			}
		}
	}



	return 0;
}

int panel() {
	char opcoes[50];
	int validador;

	printf("\nDiga o que deseja fazer:");
	printf("\nOpcoes:\n - disponibilidade\n - registrar\n - ");
	scanf(" %[^\n]s%*c", opcoes);


	if(validador=strncmp(opcoes, "disponibilidade", 50) == 0) {
		return 1;
	}
	else if(validador=strncmp(opcoes, "registrar", 50) == 0) {
		return 0;
	}
	else {
		printf("\nOpcao indisponivel");
		return 2;
	}
}
