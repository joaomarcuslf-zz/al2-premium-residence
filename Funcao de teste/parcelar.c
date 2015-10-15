#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library/high_syntax.h"
#include "Library/variaveis.h"

int main() {
	float parcelado(int, float);

	return 0;
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