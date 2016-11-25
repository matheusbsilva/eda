#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
    int info;
    struct _no *esq,*dir;
}No;

No* inserir(No* raiz, int info){
    if(!raiz){
        raiz=(No*)malloc(sizeof(No));
        raiz->info=info;
        raiz->esq=raiz->dir=NULL;

        return raiz;
    }
    else if(info > raiz->info){
        raiz->dir=inserir(raiz->dir,info);
    }
    else
        raiz->esq=inserir(raiz->esq,info);

    return raiz;
}

void busca(No* raiz,int pesq){
    No *p=raiz;
    int i=0;
    while(p!=NULL){
        if(p->info==pesq){
            printf("%d\n",i+1);
            break;
        }
        if(p->info > pesq){
            p=p->esq;
            i++;
        }
        else{
            p=p->dir;
            i++;
        }
    }
    if(p==NULL)
        printf("VALOR NAO LOCALIZADO NA ARVORE\n");
}

int main(){
    int pesq,n,i,num;
    No *raiz=NULL;
    scanf("%d %d",&pesq,&n);

    for(i=0;i<n;i++){
        scanf("%d",&num);
        raiz=inserir(raiz,num);
    }
    busca(raiz,pesq);

    return 0;
}
