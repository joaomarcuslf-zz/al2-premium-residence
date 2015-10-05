#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library/high_syntax.h"
#include "Library/variaveis.h"
int validador;
int nquarto;

int main (void)
{
 int validador;

	preparar();
	int panel(); //declaracao de funcao
	void principal_panel();
	
	while(true) {
	
		while(true) {
			validador = panel();
	
			if(validador==0) {
				break;
			}
			else if(validador==1){
				checar_diponibilidade();
			}
		}
		principal_panel();
	}
	



	return 0;
}

int panel() {
	char opcoes[50];
	

	printf("\nDiga o que deseja fazer:");
	printf("\nOpcoes:\n - Disponibilidade\n - Registrar\n - ");
	scanf(" %[^\n]s%*c", opcoes);


	if(validador=strncmp(opcoes, "Disponibilidade", 50) == 0) {
		return 1;
	}
	else if(validador=strncmp(opcoes, "Registrar", 50) == 0) {
		return 0;
	}
	else {
		printf("\nOpcao indisponivel");
		return 2;
	}
}

void principal_panel() {
	
	char opcao[50];
	int bloco, napto, andar, coluna;
	
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
			printf("\nO que deseja fazer?\n- Comprar\n- Reservar\n- Cancelar\n- ");
			scanf(" %[^\n]s%*c", opcao);
			
			if(validador=strncmp(opcao, "Comprar", 50) == 0 )
			{
				armazena_dados('C');
			}
			else if(validador=strncmp(opcao, "Reservar", 50) ==0)
			{
				armazena_dados('R');
			}
			else if(validador=strncmp(opcao, "Cancelar", 50) ==0)
			{
				return;
			}

			
		}
		else
		{
			if(apartamento[bloco-1][andar-1][coluna-1]=='R') {
				printf("\nO apartamento está reservado");
				return;
			}
			else {
				printf("\nApartamento vendido");
				return;
			}
		}
	}
}

void armazena_dados (char opt) 
{
	int vagas, perc;
	char tipopagamento[50];
	typedef struct solicita_dados
	{
		char nome[50];
		char cpf[16];
		char telefone[10];
	}; 

	struct solicita_dados dados;

	printf("\n-- DADOS DO CLIENTE --\n");
	printf("\nNome: ");
	scanf(" %[^\n]s%*c", dados.nome);
	printf("\nCPF: ");
	scanf(" %[^\n]s%*c", dados.cpf);
	printf("\nTelefone: ");
	scanf("  %[^\n]s%*c", dados.telefone);

	if(opt=='C')
	{
		if(nquarto<3)
		{
				printf("\nEscolha a quantidade de vagas:\n- 0\n- 1\n- ");
				scanf("%d", vagas);
		}
		else if(nquarto==3)
		{
			printf("\nEscolha a quantidade de vagas:\n- 0\n- 1\n- 2\n- 3\n- ");
			scanf("%d", vagas);
		}	

		//calculo valor total a ser pago

		printf("\nSelecione a forma de pagamento: \n");
		printf("- À vista\n- Financiado", );
		scanf(" %[^\n]s%*c", tipopagamento);
		if(validador=strncmp(tipopagamento, "À vista", 50) == 0 ) 
		{
				printf("O valor pode ser reduzido em até 15%.Qual sera a porcentagem?");
				scanf("%d", perc);
				//calculo de novo total com redução
		}
		else if(validador=strncmp(tipopagamento, "Financiado", 50) == 0)
		{
			//não soube o que escrever aqui
		}


	}


}

