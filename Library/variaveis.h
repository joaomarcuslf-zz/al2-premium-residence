#include <time.h>
#define strsize 50
#include <stdio.h>
char apartamento[4][10][6];
char mp_garagem[400];
int garagem=0;
int apt_check[4][10][6];
clock_t t1, t2;

typedef struct solicita_dados //Dados do cliente
{
  char opca;
  char nome[50];
  char cpf[16];
  char telefone[10];
  int id;
}cliente;

typedef struct dados_vendedor //Dados do cliente
{
  char nome[50];
  int id;
  char arquivo[100];
}vendedor;

typedef struct preco_do_apt // Preco do apartamento
{
  int id;
  int bloco;
  int apt;
  int garagem;
  int vagas[2];
  float total;
  int parcela;
  int contrutora;
  float total_parcelado;

}valor;

cliente dados[240];
valor preco[240];
vendedor ven_atual;
int num_de_cliente=-1;

void mudar_status(int, int);

void preparar() {
  int i, j, k, x;
  int apt, aval;
  char arquivo[500], nome[500];
  FILE *filer;
  FILE *file;
  FILE *file2;

  file=fopen("banco/banco_apt.txt", "r");
  for(i=0;i<4;i++) {
    for(j=0;j<10;j++) {
      for(k=0;k<6;k++) {
        fscanf(file, "[%c]\n", &apartamento[i][j][k]);
        if(apartamento[i][j][k]!='D') {
          apt_check[i][j][k]=0;
          if(apartamento[i][j][k]=='R') {

            apt=((j+1)*100)+(k+1) ;

            sprintf(arquivo, "Reservado/b %i apt %i.bin", i+1, apt);

            t2=clock();
            clock_t *pt1;
            pt1 = &t1;
            filer = fopen(arquivo, "rb");
            t1 = fread(pt1, sizeof(t2), 1, filer);
            fclose (filer);


            x=(difftime(t2, t1)/CLOCKS_PER_SEC);

            if(x>172800) {
              printf("O apartamento %i do bloco %i foi comprado?\n0 - Sim\n1 - Não\n>>>", i+1, apt);
              scanf("%i", &aval);
              if(aval==0) {
                mudar_status(i+1, apt);
                apartamento[i][j][k]='C';
              }
              else {
                sprintf(nome, "Reservado/b %i apt %i.txt", i+1, apt);
                file2=fopen(nome, "w");//Reservar
                fclose(file2);
                apartamento[i][j][k]='D';
                k-=1;
              }
            }

          }
        }
        else {
          apt_check[i][j][k]=1;
        }
      }
    }
  }
  fclose(file);

  file=fopen("banco/banco_gar.txt", "r");
  for(i=0;i<400;i++) {
    fscanf(file, "[%c]\n", &mp_garagem[i]);
    if(mp_garagem[i]!='D') {
      garagem+=1;
    }
  }
  fclose(file);
}


void checar_diponibilidade() {
  int bloco, andar, coluna, apt;

  while(1){
  printf("\nDiga o numero do bloco que deseja checar: ");
  scanf("%i", &bloco);

  if(bloco>0 && bloco<5){
    break;
    }
  else {
    printf("\nBloco invalido\nDiga um numero entre: 1 e 4");
    }
  }

  while(1) {
    printf("\nDiga o numero do apartamento que deseja checar: ");
    scanf("%i", &apt);
    if(apt/100<11 && apt/100>0) {
      if(apt%10<7 && apt%10>0) {
        break;
      }
      else {
        printf("\nNumero da coluna invalido");
      }
    }
    else {
      printf("\nNumero da coluna invalido");
    }
  }
  bloco-=1;
  andar=apt/100 - 1;
  coluna=apt%10 - 1;
  printf("Status do apt %d, bloco %d: [%c]\n", apt, bloco+1, apartamento[bloco][andar][coluna]);
}

float percent(float percent, float valor_bruto, int andar) {
  // 100 - Valor bruto
  // per - X
  //X=(valor*(per*andar)/100;

  return (valor_bruto*(percent*andar))/100;
}

float calculo_de_valor(int vagas_na_garagem, int numero_do_apt) {
	float valor_final, valor_bruto;
	int andar=(numero_do_apt/100)-1;
	int coluna=numero_do_apt%10;

	if(coluna==3 or coluna==6) {
			valor_bruto=225000;
	}
	else if(coluna==1 or coluna==4) {
		valor_bruto=280000;
	}
	else {
		valor_bruto=375000;
	}

	valor_final=valor_bruto+percent(3.5, valor_bruto, andar)+(20000.00*vagas_na_garagem);
	return valor_final;
}

float parcelado(int num_de_parcelas, float valor) {
	float max_de_reducao = percent(15, valor, 1);

	if(valor/num_de_parcelas>=max_de_reducao) {
		return valor/num_de_parcelas;
	}
	else {
		return -1;
	}
}

void gravar() {
  int id=num_de_cliente;
  FILE *file, *f1;
  char nome[500], reservado[500];

  if(dados[id].opca=='C') {
    apartamento[preco[id].bloco-1][(preco[id].apt/100)-1][(preco[id].apt%10)-1]='C';
    sprintf(nome, "Comprado/b %i apt %i.txt", preco[id].bloco, preco[id].apt);
    file=fopen(nome, "w");
    fprintf(file, "----------------------------------------------------------------------\n");
    fprintf(file, "Status: Comprado");
  }
  else {
    apartamento[preco[id].bloco-1][(preco[id].apt/100)-1][(preco[id].apt%10)-1]='R';

    sprintf(reservado, "Reservado/b %i apt %i.bin", preco[id].bloco, preco[id].apt);
    clock_t *pt1;
    t1=clock();
    pt1 = &t1;
    file = fopen(reservado, "wb");
    int i = fwrite(pt1, sizeof(t1), 1, file);
    fclose (file);

    sprintf(nome, "Reservado/b %i apt %i.txt", preco[id].bloco, preco[id].apt);
    file=fopen(nome, "w");//Reservar
  }


  fprintf(file, "\nNome do cliente: %s", dados[id].nome);
  fprintf(file, "\nCPF: %s", dados[id].cpf);
  fprintf(file, "\nTelefone: %s", dados[id].telefone);
  fprintf(file, "\n----------------------------------------------------------------------");
  fprintf(file, "\nBloco: %2i Apt: %4i", preco[id].bloco, preco[id].apt);
  if (preco[id].garagem>0) {
    fprintf(file, "\nGaragem: Sim\n");
    int i;
    for(i=0; i<preco[id].garagem; i++) {
      fprintf(file, "G%3i ", preco[id].vagas[i]);
    }
  }
  fprintf(file, "\nPreco total a pagar: R$%.2f", preco[id].total);

  if(preco[id].parcela>0) {
    fprintf(file, "\nTipo de pagamento: Parcelado");
    fprintf(file, "\n%i parcelas de R$%.2f", preco[id].parcela, preco[id].total_parcelado);
  }
  else {
    fprintf(file, "\nTipo de pagamento: A vista");
  }

  fclose(file);

  f1 = fopen(ven_atual.arquivo, "a");
  fprintf(f1, "%i - %3i - %c     - R$%.2f", preco[id].bloco, preco[id].apt, dados[id].opca, percent(0.4, preco[id].total, 1));
  fclose(f1);


  int i;
  int j;
  int k;
  file=fopen("Relatorios/apartamentos.txt", "w");
  for(i=0;i<4;i++) {
    fprintf(file, "Bloco: %2i\n", i+1);
    for(j=0;j<10;j++) {
      fprintf(file, "Andar %2i:", j+1);
      for(k=0;k<6;k++) {
        fprintf(file, "[%c] ", apartamento[i][j][k]);
      }
      fprintf(file, "\n");
    }
    fprintf(file, "\n\n\n");
  }
  fclose(file);

  file=fopen("Relatorios/garagem.txt", "w");
  for(i=0;i<400;i++) {
    fprintf(file, "G%3i: [%c]\n", i, mp_garagem[i]);
  }
  fclose(file);

  file=fopen("banco/banco_apt.txt", "w");
  for(i=0;i<4;i++) {
    for(j=0;j<10;j++) {
      for(k=0;k<6;k++) {
        fprintf(file, "[%c]\n", apartamento[i][j][k]);
      }
    }
  }
  fclose(file);

  file=fopen("banco/banco_gar.txt", "w");
  for(i=0;i<400;i++) {
    fprintf(file, "[%c]\n", mp_garagem[i]);
  }
  fclose(file);

}

void mudar_status(int b, int apt) {
  char arq1[500], arq2[500], leitor[1000];
  FILE *f1, *f2;
  sprintf(arq1, "Reservado/b %i apt %i.txt", b, apt);
  sprintf(arq2, "Comprado/b %i apt %i.txt", b, apt);

  f2=fopen("arq2", "w");
  fprintf(f2, "----------------------------------------------------------------------\n");
  fprintf(f2, "Status: Comprado");
  fclose(f2);

  f1=fopen(arq1, "r");
  f2=fopen(arq2, "a");

  while(fgets(leitor, 1000, f1)!=nil) {
    fputs(leitor, f2);
  }

  fclose(f1);
  fclose(f2);

  f1=fopen("arq1", "w");
  fclose(f1);
}

void construtora(int bloco, int apt) {
  char nome[500];
  int i;
  int j;
  int k;
  FILE *file, *f1;
  sprintf(nome, "Construtora/b %i apt %i.txt", bloco, apt);
  file=fopen(nome, "w");
  fprintf(file, "----------------------------------------------------------------------\n");
  fprintf(file, "Status: Construtora");
  fprintf(file, "\n----------------------------------------------------------------------");
  fprintf(file, "\nBloco: %2i Apt: %4i", bloco, apt);
  fclose(file);

  f1 = fopen(ven_atual.arquivo, "a");
  fprintf(f1, "%i - %3i - O     - R$%.2f", bloco, apt, 0.00);
  fclose(f1);
  apartamento[bloco-1][(apt/100)-1][(apt%10)-1]='O';



  file=fopen("Relatorios/apartamentos.txt", "w");
  for(i=0;i<4;i++) {
    fprintf(file, "Bloco: %2i\n", i+1);
    for(j=0;j<10;j++) {
      fprintf(file, "Andar %2i:", j+1);
      for(k=0;k<6;k++) {
        fprintf(file, "[%c] ", apartamento[i][j][k]);
      }
      fprintf(file, "\n");
    }
    fprintf(file, "\n\n\n");
  }
  fclose(file);

  file=fopen("Relatorios/garagem.txt", "w");
  for(i=0;i<400;i++) {
    fprintf(file, "G%3i: [%c]\n", i, mp_garagem[i]);
  }
  fclose(file);

  file=fopen("banco/banco_apt.txt", "w");
  for(i=0;i<4;i++) {
    for(j=0;j<10;j++) {
      for(k=0;k<6;k++) {
        fprintf(file, "[%c]\n", apartamento[i][j][k]);
      }
    }
  }
  fclose(file);

  file=fopen("banco/banco_gar.txt", "w");
  for(i=0;i<400;i++) {
    fprintf(file, "[%c]\n", mp_garagem[i]);
  }
  fclose(file);
}
