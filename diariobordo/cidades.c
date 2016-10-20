#include <stdio.h>
#include <stdlib.h>

int *distancias(int A[][6], int c){
  int *d,j;
  int fila[6], ini,fim;
  d=(int*)malloc(6*sizeof(int));

  for(j=0;j<6;j++) d[j]=6;          //preenche o vetor de distancias com 6, que significa que a cidade não pode ser visitada

  d[c]=0;                           //preeche no vetor de distancias a distancia de c a ela mesma
  fila[0]=c; ini=0; fim=1;          //inclui c na fila de cidades a serem visitadas

  while (ini!=fim) {
    int i,di;
    i=fila[ini++];                  //pega a proxima cidade a ser visitada
    di=d[i];                        //pega a distancia de c ate essa cidade a ser visitada

    for(j=0;j<6;j++){
      if(A[i][j] == 1 && d[j]>=6){  //verifica se existe ligação entre c e j e se j não foi visitada ainda
        fila[fim++]=j;              //inclui j na fila de cidades a serem visitadas por ser vizinha de uma cidade anterior
        d[j] = di + 1;              // preenche o vetor de distancias com a distância de c até j
      }
    }
  }
  return d;
}

int main(){
  int A[6][6];
  int i,j,*d;

  for(i=0;i<6;i++)
    for(j=0;j<6;j++)
      A[i][j]=0;

  A[0][1]=1;
  A[1][2]=1;
  A[2][4]=1;
  A[3][2]=1; A[3][4]=1;
  A[4][0]=1;
  A[5][1]=1;

  int c=3;

  d=distancias(A,c);

  for(i=0;i<6;i++)
    printf("%d ",d[i]);

  return 0;
}
