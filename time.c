#include <time.h>
#include <stdio.h>
#include "Library/variaveis.h"

clock_t t1, t2;

int main() {
  void gravar_hora(char []);

  t2=clock();
  x=(difftime(t2, t1)/CLOCKS_PER_SEC);
  printf("Tempo em segundos: %.5f",x);
  return 0;
}


void gravar_hora(char arquivo[strsize]) {
  t1=clock();
  FILE *filer = fopen(arquivo, 'a');

}
