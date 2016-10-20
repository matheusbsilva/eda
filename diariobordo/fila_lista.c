#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int info;
  struct _node *prox;
}Node;

Node *inserir(Node *l,Node *ini){
  Node *novo = (Node*)malloc(sizeof(Node));

  scanf("%d",&novo->info);
  novo->prox=NULL;

  if(l==NULL)
    ini->prox=novo;

  else
    l->prox=novo;

  return novo;
}

void imprimir(Node *ini){
  Node *imp = ini;
  if(imp != NULL){
    printf("%d\t",imp->info);
    imprimir(imp->prox);
  }

}

void remover(Node *ini){
  if(ini->prox == NULL )
    printf("A lista está vazia!!\n");
  else{
    Node *aux = ini->prox;
    ini->prox=ini->prox->prox;
    free(aux);
  }
}

int main(int argc, char const *argv[]) {
  Node *l = NULL;
  Node *ini=(Node*)malloc(sizeof(Node));
  ini->prox=NULL;

  char op;

  while(scanf("%c",&op),op != 'F'){
    switch (op) {
      case 'I':l=inserir(l,ini);
               break;
      case 'P':imprimir(ini->prox);printf("\n");
               break;
      case 'R':remover(ini);
               break;
    }
  }
  return 0;
}
