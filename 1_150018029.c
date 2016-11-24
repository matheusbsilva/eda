#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *esq,*dir;
}No;

No* inserir(No *raiz,int info){
    if(!raiz){
        raiz=(No*)malloc(sizeof(No));
        raiz->info=info;
        raiz->esq=raiz->dir=NULL;

        return raiz;
    }
    else if(info > raiz->info){
        raiz->dir=inserir(raiz->dir,info);

    }else if(info < raiz->info){
        raiz->esq=inserir(raiz->esq,info);

    }

    return raiz;
}
int altura (No* r) {
   if (r == NULL)
      return 0;
   else {
      int he = altura (r->esq);
      int hd = altura (r->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}
int totalNos(int alt){
    int total=1,i;
    for(i=0;i<alt;i++){
        total=total*2;
    }
    return total-1;
}
int main(){
    No* raiz=NULL;
    int i,n,x,total;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        raiz=inserir(raiz,x);
    }
    total=totalNos(altura(raiz));
    
    return 0;
}
