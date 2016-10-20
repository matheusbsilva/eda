/* MATHEUS BATISTA SILVA - 150018029 */


#include <stdio.h>
#include <stdlib.h>


typedef struct _cid{
  int tickets;
  char nome[32];
}Cidadao;

typedef struct _f{
  Cidadao cidadao;
}Fila;

int main(){

  int cestas,num,i,ini=0,fim=ini;
  Fila *fila;

  scanf("%d %d",&cestas,&num);
  fila=(Fila *)malloc((num+1)*sizeof(Fila));

  for(i = 0;i < num; i++){
    scanf("%s %d",fila[fim].cidadao.nome,&fila[fim].cidadao.tickets);
    fim++;
  }
  while(cestas > 0 && fim!=ini ){
    if(ini==num+1)
      ini=0;

    if(fila[ini].cidadao.tickets > 0){
      if(fim==num+1)
        fim=0;
      fila[ini].cidadao.tickets--;
      fila[fim]=fila[ini];
      ini++;
      fim++;

      cestas--;
    }
    else{
      ini++;
    }
  }
  if(cestas > 0)
    printf("AS CESTAS ATENDERAM A TODOS OS CIDADAOS\n");
  else
    printf("%s RECEBEU A ULTIMA CESTA\n",fila[fim-1].cidadao.nome);

  return 0;
}
