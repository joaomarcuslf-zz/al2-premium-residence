#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define strsize 50

clock_t t1, t2;

int main() {
  double x;
  void gravar_hora(char []);
  void ler_hora(char []);

  ler_hora("time");

  t2=clock();
  x=(difftime(t2, t1)/CLOCKS_PER_SEC);
  printf("Tempo em segundos: %.5f\n",x);
  return 0;
}


void gravar_hora(char arquivo[strsize]) {
  clock_t *pt1;
  t1=clock();
  pt1 = &t1;
  FILE *filer = fopen(arquivo, "wb");
  int i = fwrite(pt1, sizeof(t1), 1, filer);
  fclose (filer);

}


void ler_hora(char arquivo[strsize]) {
  clock_t *pt1;
  t1=clock();
  pt1 = &t1;
  FILE *filer = fopen(arquivo, "rb");
  t1 = fread(pt1, sizeof(t1), 1, filer);

  fclose (filer);

}
