<<<<<<< HEAD
#define strsize 50
=======
>>>>>>> 934654488c7b9e73e31ed48f2b384eaadf2afdc3
char apartamento[4][10][6];

void preparar() {
  int i, j, k;

  for(i=0;i<4;i++)
    for(j=0;j<10;j++)
      for(k=0;k<6;k++)
        apartamento[i][j][k]='D';
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
<<<<<<< HEAD

float percent(float percent, float valor_bruto, int andar) {
  // 100 - Valor bruto
  // per - X
  //X=(valor*(per*andar)/100;

  return (valor_bruto*(percent*andar))/100;
}
=======
>>>>>>> 934654488c7b9e73e31ed48f2b384eaadf2afdc3
