#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int info;
  struct _node *prox;
}Node;


Node *inicio(){
  Node *ini=(Node*)malloc(sizeof(Node));
  ini->prox=NULL;
  return ini;
}
Node *inserir(Node *l,Node *ini){
  Node *novo = (Node*)malloc(sizeof(Node));

  scanf("%d",&novo->info);
  novo->prox=NULL;

  if(ini->prox==NULL){
    ini->prox=novo;
}
  else{
    l->prox=novo;
    novo->prox=ini->prox;
  }

  return novo;
}

int imprimir(Node *ini){
  Node *imp=ini->prox,*init=ini->prox;
  printf("0");
  if(ini->prox==NULL){
    printf("1");
    printf("A lista está vazia!!\n");
    return 0;
  }
  do{
    printf("2");
    printf("%d\t",imp->info);
    imp=imp->prox;
  }while(imp!=init);



}

void remover(Node *ini,Node *l){
  Node *aux;

  if(ini->prox == NULL )
    printf("A lista está vazia!!\n");

  else if(ini->prox==l){
    aux= ini->prox;
    ini->prox=aux->prox;
    l->prox=ini->prox;

    ini->prox=NULL;

    free(aux);
  }
  else{
    aux= ini->prox;
    ini->prox=aux->prox;
    l->prox=ini->prox;

    free(aux);
  }
}

int main(int argc, char const *argv[]) {
  Node *l = NULL;
  Node *ini=inicio();
  char op;

  while(scanf("%c",&op),op != 'F'){
    switch (op) {
      case 'I':l=inserir(l,ini);printf("UUUU");
               break;
      case 'P':printf("sadas");imprimir(ini);printf("\n");
               break;
      case 'R':remover(ini,l);
               break;
    }
  }
  return 0;
}
