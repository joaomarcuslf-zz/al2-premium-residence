#include <time.h>
#include <stdio.h>

clock_t t1, t2;

int main() {
  int i=0;
  float x;
  t1=clock();

  while(i!=1) {
      printf("\n >> ");
      scanf("%i", &i);
  }
  t2=clock();
  x=(difftime(t1, t2)/CLOCKS_PER_SEC);
  printf("Tempo em mins: %.5f",x);
  return 0;
}
