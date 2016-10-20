#include <stdlib.h>
#include <stdio.h>

typedef struct _aluno{
  int mat;
  struct _aluno *prox;
}Aluno;

typedef struct _h{
  int qt;
  Aluno *inicio,*fim;
}Header;


Header *inicializar(){
  Header *h=(Header*)malloc(sizeof(Header));
  h->inicio=NULL;
  h->fim=NULL;
  h->qt=0;

  return h;
}
 void ordena(Aluno *novo,Header *l){
  int aux;
  if(l->fim->mat > novo->mat){
    aux=novo->mat;
    novo->mat=l->fim->mat;
    l->fim->mat=aux;
  }
}
Aluno *inserir(Header *h){

  int x,aux;
  scanf("%d",&x);

  Aluno *novo = (Aluno*)malloc(sizeof(Aluno));

  novo->mat=x;
  novo->prox=NULL;

  if(h->inicio==NULL&& h->fim==NULL){
    h->inicio=novo;
    h->fim=novo;
    h->qt++;
  }

  else{
    ordena(novo,h);
    h->fim->prox=novo;
    h->fim=novo;
    h->qt++;
  }
}

void imprime(Header *l){
  Aluno *imp;
  for (imp=l->inicio; imp!=NULL ; imp=imp->prox) {
    printf("%d ",imp->mat);
  }
  printf("\n");
}

int main () {
    Header *head=inicializar();
    int i;
    for (i = 0; i < 5; i++) {
      inserir(head);
    }

    imprime(head);
  return 0;
}
