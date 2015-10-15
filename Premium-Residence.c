#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library/high_syntax.h"
#include "Library/variaveis.h"

int main() {
  int panel(); //declaracao de funcao
  void negociacao();
  void armazena_dados(char , int, int);
  void logar_vendedor();
  preparar(); // Iniciar todas as vagas
  int validador;

  while(true) {
    while(true) {
			validador = panel(); //Painel principal

			if(validador==1) {
				break;
			}
			else if(validador==0){
				checar_diponibilidade();
			}
      else if(validador==2){
				logar_vendedor();
			}
      else {
        printf("\nOpcao invalida");
      }
		}
		negociacao();
  }
}

int panel() {
  int validador;


	printf("\nDiga o que deseja fazer:");
	printf("\nOpcoes:\n0 - Disponibilidade\n1 - Registrar\n2 - Vendedor\n >>> ");
	scanf(" %i", &validador);

  return validador;
}

void armazena_dados (char opt, int bloco, int apt)
{
  int tipopagamento;
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
        printf("\nEscolha a quantidade de vagas da garagem:\n- 0\n- 1\n- 2\n>>> ");
			  scanf("%d", &vagas);
        if(vagas == 0 or vagas ==  1 or vagas ==  2)
          break;
        else
          printf("\nNum invalido!");
      }
		}

		else {
      while(true) {
        printf("\nEscolha a quantidade de vagas na garagem:\n- 0\n- 1\n>>> ");
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
    printf("Valor total a pagar: R$%.2f\n", preco[id].total);
		printf("\nSelecione a forma de pagamento: \n");

    while(true) {
      printf("0 - A vista\n1 - Parcelado\n>>> ");
  		scanf("%d", &tipopagamento);

      if(tipopagamento==0 or tipopagamento==1)
        break;
      else
        printf("\nOpcao invalida\n");
    }

		if(tipopagamento == 0 )
		{
        preco[id].parcela=0;

		}
		else if(tipopagamento == 1)
		{
      int num;
      float parcelar;
      int aval;
			while(true) {
        printf("\nDiga um numero de parcelas: ");
        scanf("%d", &num);

        parcelar=parcelado(num, preco[id].total);

        if(parcelar>-1)
          printf("\n%d parcelas de %.2f\n", num, parcelar);
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
    printf("\n\nObrigado por negociar conosco!\n");

	}


void negociacao() {

	int opcao;
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
		coluna=(napto%10);

		if(apt_check[bloco-1][andar-1][coluna-1]==true)
		{
			printf("\nDisponivel\n");
			printf("\nO que deseja fazer?\n0 - Comprar\n1 - Reservar\n2 - Cancelar\n>>> ");
			scanf("%i", &opcao);

			if(opcao == 0 )
			{
				armazena_dados('C', bloco, napto);
        return;
			}
			else if(opcao == 1)
			{
				armazena_dados('R', bloco, napto);
        return;
			}
			else if(opcao == 2)
			{
				return;
			}


		}
		else
		{
		    printf("\n\nApartamento indisponivel!\n");
				return;
		}
	}
}

void logar_vendedor() {
  FILE *f1;
  printf("\nDiga seu nome: ");
  scanf(" %[^\n]s%*c", ven_atual.nome);
  printf("\nDiga seu id: ");
  scanf("%i", &ven_atual.id);
  sprintf(ven_atual.arquivo, "Vendedor/%s_%i.txt", ven_atual.nome, ven_atual.id);

  if(fopen(ven_atual.arquivo, "r")==nil) {
    f1 = fopen(ven_atual.arquivo, "w");
    fprintf(f1, "Nome do vendedor: %s", ven_atual.nome);
    fprintf(f1, "\nid: %i", ven_atual.id);
    fprintf(f1, "\n---------------------------------------------------\nB - Apt - Status\n");
    fclose(f1);
  }
}
