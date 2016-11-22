#include <stdio.h>
#include <stdlib.h>


typedef struct no {
  int info;
  struct no *esq,*dir;
}No;

No* inserir(No* raiz,int info){
  if(!raiz){
    if(!(raiz = (No*)malloc(sizeof(No)))){
      perror("inserir:malloc()");
      return NULL;
    }
    raiz->info=info;
    raiz->esq=raiz->dir=NULL;

    return raiz;
  }
  else if(raiz->info < info)
    raiz->dir=inserir(raiz->dir,info);
  else
    raiz->esq=inserir(raiz->esq,info);

  return raiz;

}

void imprimir_ord(No *raiz){

}

int main(int argc, char const *argv[]) {
  No* raiz=NULL;
  int op,info;
  while(op){
    system("clear");
    printf("1-Inserir\n2-Imprimir\n3-Remover\n0-Sair\n");
    scanf("%d",&op);
    switch (op) {
      case 1: printf("Digite o valor a ser inserido: ");
              scanf("%d",&info);
              raiz=inserir(raiz,info);
              printf("%d\n",raiz->info);
              getchar();
              break;
      case 2:break;
      case 3:break;
      case 0:break;
      default:printf("Opção inválida\n");
    }
  }

  return 0;
}
