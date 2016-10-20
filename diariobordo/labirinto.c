#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define MAX 100 //capacidade de armazenamento da pilha e da fila
#define N 7 //tamanho da matriz que representa o labirinto
#define LIVRE 0// marca a posicao livre no labirinto
#define PAREDE 32767//marca de posicao com parede no labirinto

typedef struct _f{
  int x,y;
}Tipo;

void cria(int L[N][N]){ //funcao para a criação de um labirinto
  int i, j;
  for(i=0;i<N;i++){ //MARCA OS LADOS DA MATRIZ COM PAREDE
    L[i][0]=PAREDE;
    L[i][N-1] = PAREDE;
  }
  for(j=0;j<N;j++){ //MARCA OS LADOS DA MATRIZ COM PAREDE
    L[0][j]=PAREDE;
    L[N-1][j] = PAREDE;
  }

  for(i=1;i<N-1;i++)
    for(j=1;j<N-1;j++)
      if( rand()%3==0)L[i][j]=PAREDE; //GERA O LABIRINTO
      else L[i][j]=LIVRE;
    // L[1][2]=PAREDE;
    // L[2][2]=PAREDE;
    // L[3][2]=PAREDE;
    // L[5][2]=PAREDE;
    // L[2][4]=PAREDE;
    // L[3][4]=PAREDE;
    // L[4][4]=PAREDE;
    //
    // L[3][5]=LIVRE;
    //
    // for(i=1;i<N-1;i++)
    //   for(j=1;j<N-1;j++)
    //     if(L[i][j]!=PAREDE)
    //       L[i][j]=LIVRE;

  L[1][1]=LIVRE;
  L[N-2][N-2] = LIVRE;
}//fim-cria//

void exibe(int L[N][N]){ //funcao para exibição de um labirinto
  int i, j;
  for(i=0;i < N;i++){
    for(j=0;j < N;j++)
      switch(L[i][j]){
        case LIVRE : putchar(' ');break;
        case PAREDE: putchar('#');break;
        default : putchar(126);//printf("%d",L[i][j]);
      }
  printf("\n");
  }
}

void anota(int L[N][N]){
  Tipo fila[MAX];
  int ini,fim,c=0;

  L[1][1]=1;
  fila[0].x = 1;fila[0].y = 1;
  ini=0; fim=1;
  while(ini!=fim){
    int i,j;

    c=L[fila[ini].x][fila[ini].y];
    ini++;
    for (i = 0; i < N; i++)
      for (j = 0; j < N; j++)
        if(L[i][j]==LIVRE && (L[i-1][j]==c || L[i][j-1]==c)){
          L[i][j]=++c;
          fila[fim].x=i;fila[fim].y=j;
          fim++;
        }

    // printf("fila=%d %d\n",fila[ini].x, fila[ini].y);
  }

}
int extrai(int L[N][N]){
  // exibe(L);
  if(L[N-2][N-2]==0){
    printf("Não há como sair do labirinto\n");
    return 0;
  }

  Tipo pilha[MAX];
  int topo=0;
  pilha[topo].x=N-2;pilha[topo].y=N-2;
  topo++;
  while(pilha[topo].x!=1 && pilha[topo].y!=1){
    int i,j;
    for(i=N-2;i>=1;i--)
      for(j=N-2;j>=1;j--){
        if(L[i][j]==L[i][j]-1){
          pilha[topo].x=i;pilha[topo].y=j;
          topo++;
        }
      }
  }
  while(topo >=0){
    // int i,j;
    // for(i=0;i<N;i++)
    //   for(j=0;j<N;j++){
    //
    //   }

    int i, j;

    for(i=0;i < N;i++){
      for(j=0;j < N;j++){
        switch(L[i][j]){
          case LIVRE : putchar(' ');break;
          case PAREDE: putchar('#');break;
          // default : putchar(126);//printf("%d",L[i][j]);
        }
        // if(L[i][j]==L[pilha[topo].x][pilha[topo].y])
        //   putchar('x');
      }

    printf("\n");
    }
    topo--;
  }

}


int main(){
  int L[N][N];
  char r;
  srand(time(NULL));
  do{
    system("clear");
    cria(L);
    anota(L);
    exibe(L);
    extrai(L);

    printf("Continua? (s/n)\n");
    scanf("%c*c",&r);

  }while(toupper(r)!='N');
  return 0;
}
