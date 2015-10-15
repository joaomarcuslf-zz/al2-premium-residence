#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library/high_syntax.h"
#include "Library/variaveis.h"

int main() {
	float calculo_de_valor(int , int);

	calculo_de_valor(2, 1105);

	return 0;
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
