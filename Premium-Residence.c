#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library/high_syntax.h"
#include "Library/variaveis.h"

int main() {
  int panel(); //declaracao de funcao
  void negociacao();
  void armazena_dados(char , int, int);
  preparar(); // Iniciar todas as vagas
  int validador;

  while(true) {
    while(true) {
			validador = panel(); //Painel principal

			if(validador==0) {
				break;
			}
			else if(validador==1){
				checar_diponibilidade();
			}
		}
		negociacao();
  }
}

int panel() {
	char opcoes[50];
  int validador;


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

void armazena_dados (char opt, int bloco, int apt)
{
  char tipopagamento[50];
  num_de_cliente+=1;
  int id=num_de_cliente;
  int validador;
  int vagas;

  dados[id].id=num_de_cliente;
  preco[id].id=id;
  preco[id].bloco=bloco;
  preco[id].apt=apt;

	printf("\n-- DADOS DO CLIENTE --\n");
	printf("\nNome: ");
	scanf(" %[^\n]s%*c", dados[id].nome);
	printf("\nCPF: ");
	scanf(" %[^\n]s%*c", dados[id].cpf);
	printf("\nTelefone: ");
	scanf("  %[^\n]s%*c", dados[id].telefone);

	if(apt%100 == 5 or 2)
		{
			while(true){
        printf("\nEscolha a quantidade de vagas da garagem:\n- 0\n- 1\n- 2\n- ");
			  scanf("%d", &vagas);
        if(vagas == 0 or vagas ==  1 or vagas ==  2)
          break;
        else
          printf("\nNum invalido!");
      }
		}

		else {
      while(true) {
        printf("\nEscolha a quantidade de vagas na garagem:\n- 0\n- 1\n- ");
        scanf("%d", &vagas);
        if(vagas == 0 or 1)
          break;
        else
          printf("\nNum invalido!");
      }
    }
    preco[id].garagem=vagas;
    if (vagas>0) {
      preco[id].vagas[0]=garagem;
      mp_garagem[garagem]='C';
      garagem+=1;
      if(vagas>1) {
        preco[id].vagas[1]=garagem;
        mp_garagem[garagem]='C';
        garagem+=1;
      }
    }
    preco[id].total=calculo_de_valor(preco[id].garagem, preco[id].apt);

		//calculo valor total a ser pago
    printf("Valor total a pagar: R$%.2f", preco[id].total);
		printf("\nSelecione a forma de pagamento: \n");
		printf("- A vista\n- Parcelado\n- ");
		scanf(" %[^\n]s%*c", tipopagamento);
		if(validador=strncmp(tipopagamento, "A vista", 50) == 0 )
		{
        preco[id].parcela=0;

		}
		else if(validador=strncmp(tipopagamento, "Parcelado", 50) == 0)
		{
      int num;
      float parcelar;
      int aval;
			while(true) {
        printf("\nDiga um numero de parcelas: ");
        scanf("%d", &num);

        parcelar=parcelado(num, preco[id].total);

        if(parcelar>-1)
          printf("\n%d parcelas de %.2f", num, parcelar);
        else
          continue;

        printf("\nEsta certo disso?\n0 - Nao\n1 - Sim\nNum: ");
        scanf("%d", &aval);
        if(aval==1)
          break;
        else
          continue;
      }
      preco[id].parcela=num;
      preco[id].total_parcelado=parcelar;
		}
    dados[id].opca=opt;

    gravar();
    printf("\nObrigado por negociar conosco!");

	}


void negociacao() {

	char opcao[50];
	int bloco, napto, andar, coluna, validador;

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
				armazena_dados('C', bloco, napto);
        return;
			}
			else if(validador=strncmp(opcao, "Reservar", 50) ==0)
			{
				armazena_dados('R', bloco, napto);
        return;
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
