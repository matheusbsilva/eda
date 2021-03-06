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

Arvore *rod_esq(Arvore *raiz){
  Arvore *q,*temp;
  q=raiz->dir;
  temp=q->esq;
  q->esq=raiz;
  raiz->dir=temp;
  q->fatorb=altura(raiz->esq)-altura(raiz->dir);
  return q;
}

Arvore *rod_dir(Arvore *raiz){
  Arvore *q,*temp;
  q=raiz->esq;
  temp=q->dir;
  q->dir=raiz;
  raiz->esq=temp;
  q->fatorb=altura(raiz->esq)-altura(raiz->dir);
  return q;
}

Arvore *rod_dir_esq(Arvore *raiz){
  raiz->dir=rod_dir(raiz->dir);
  return rod_esq(raiz);
}

Arvore *rod_esq_dir(Arvore *raiz){
  raiz->esq=rod_esq(raiz->esq);
  return rod_dir(raiz);
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

    if(raiz->fatorb > 1){
      if(raiz->esq->fatorb < 0){
        raiz=rod_esq_dir(raiz);
      }
      else{
        raiz=rod_dir(raiz);
      }
    }
    if(raiz->fatorb < -1){
      if(raiz->dir->fatorb > 0){
        raiz=rod_dir_esq(raiz);
      }
      else{
        raiz=rod_esq(raiz);
      }
    }
    return raiz;
}

Arvore *busca(Arvore *raiz,int x){
  if(raiz->info == x|| raiz==NULL)
    return raiz;
  else if(raiz->info < x)
    return busca(raiz->dir,x);
  else
    return busca(raiz->esq,x);
}

Arvore *menorDireita(Arvore *raiz){
  Arvore *atual=raiz;
  while(atual->esq!=NULL){
    atual=atual->esq;
  }
  return atual;
}

Arvore *deleta(Arvore *raiz){
  if(raiz==NULL)
    return raiz;
  else{

    if(raiz->dir==NULL){
      Arvore *temp=raiz->esq;
      free(raiz);
      return temp;
    }
    else if(raiz->esq==NULL){
      Arvore *temp=raiz->dir;
      free(raiz);
      return temp;
    }

    Arvore *temp=menorDireita(raiz->dir);
    raiz->info=temp->info;
    raiz->dir=deleta(busca(raiz->dir,temp->info));
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
    int n,i,x,d;
    scanf("%d",&n);

    for (i = 0; i < n; i++) {
        scanf("%d",&x);
        raiz=inserir(raiz,x);
    }
    imprimir_ord(raiz);putchar('\n');

    if(balanceada(raiz)){

      printf("Esta balanceada\n");
    }
    else{

      printf("Nao esta balanceada\n");
    }



    scanf("%d",&d );
    deleta(busca(raiz,d));

    imprimir_ord(raiz);putchar('\n');

    if(balanceada(raiz)){

      printf("Esta balanceada\n");
    }
    else{

      printf("Nao esta balanceada\n");
    }

    return 0;
}
