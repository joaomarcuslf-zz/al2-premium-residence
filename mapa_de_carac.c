#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	
	int i, j, k, e=0;
	
	char apartamento[4][10][6];
	char garagem[400];

  	for(i=0;i<4;i++)
    	for(j=0;j<10;j++)
      	for(k=0;k<6;k++)
        	apartamento[i][j][k]='D';
  
  	for(i=0;i<400;i++) {
    	garagem[i]='D';
	}
	
	j=1;
	k=1;
	
	e+=1;
    printf("\n\nG%i\n\n", e);
	printf("\n|================================================|\n");
	
 	 for(i=0;i<400;i++) {
    	printf("[ %c ]", garagem[i]);
    
	if(i%3==0) {
		garagem[i+(j-j/2)]='C';
	}
   	 if(j==10) {
   	   printf("\n|================================================|\n");
   	   garagem[i+j/2]='R';
   	   j=0;
   	 }
    	j+=1;
    	if(k==50) {
    		e+=1;
    		printf("\n\nG%i\n\n", e);
    		k=0;
		}
		k+=1;
    
	}
	
	return 0;
}


void preparar() {
  int i, j, k;

  for(i=0;i<4;i++)
    for(j=0;j<10;j++)
      for(k=0;k<6;k++)
        apartamento[i][j][k]='D';
  
  for(i=0;i<400;i++) {
    garagem[i]='0';

	}
}

void mapa_de_vagas_garagem() {
  int i, j=1, k, e;

  k=1;
	
	e+=1;
    printf("\n\nG%i\n\n", e);
	printf("\n|================================================|\n");
	
 	 for(i=0;i<400;i++) {
    	printf("[ %c ]", garagem[i]);

   	 if(j==10) {
   	   printf("\n|================================================|\n");
   	   j=0;
   	 }
    	j+=1;
    	if(k==50) {
    		e+=1;
    		printf("\n\nG%i\n\n", e);
    		k=0;
		}
		k+=1;
    
	}
  
}

