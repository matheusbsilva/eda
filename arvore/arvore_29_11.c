#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    int fatorb;
    struct _no *esq,*dir;
}Arvore;

int altura(Arvore *raiz){
    if(raiz!=NULL){
        int he=0,hd=0;
        he=altura(raiz->esq) + 1;
        hd=altura(raiz->dir) + 1;
        if(he > hd)
            return he;
        else
            return hd;
    }
    else
        return 0;
}

Arvore *inserir(Arvore *raiz,int info){
    if(!raiz){
        raiz=(Arvore*)malloc(sizeof(Arvore));
        raiz->esq=raiz->dir=NULL;
        raiz->info=info;
        raiz->fatorb=0;

        return raiz;
    }
    else if(info > raiz->info){
        raiz->dir=inserir(raiz->dir,info);
        raiz->fatorb=altura(raiz->esq)-altura(raiz->dir);
    }
    else if(info < raiz->info){
        raiz->esq=inserir(raiz->esq,info);
        raiz->fatorb=altura(raiz->esq)-altura(raiz->dir);

    }
    return raiz;
}

void imprimir_ord(Arvore *raiz){
    if(raiz!=NULL){
      imprimir_ord(raiz->esq);
      printf("%d ",raiz->info);
      imprimir_ord(raiz->dir);
    }
}

int balanceada(Arvore *raiz){
    if(raiz!=NULL){
      balanceada(raiz->esq);
      if(raiz->fatorb > 1 || raiz->fatorb < -1 ){
          return 0;
      }
      else
          return 1;
      balanceada(raiz->dir);
    }

    return 0;
}

int main(){
    Arvore *raiz=NULL;
    int n,i,x;
    scanf("%d",&n);

    for (i = 0; i < n; i++) {
        scanf("%d",&x);
        raiz=inserir(raiz,x);
    }
    imprimir_ord(raiz);putchar('\n');

    if(balanceada(raiz))
      printf("Esta balanceada\n");
    else
      printf("Nao esta balanceada\n");
    return 0;
}
