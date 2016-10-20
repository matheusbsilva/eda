#include <stdio.h>
#include <stdlib.h>

typedef struct lst{
  int info;
  struct lst *prox,*ant;

}Lista;

//Inserir elementos na lista
Lista *Inserir(Lista *lista){
  Lista *novo = (Lista*)malloc(sizeof(Lista));
  Lista *atual,*anterior;
  int info;
  scanf("%d",&info);__fpurge(stdin);
  novo->info=info;
  novo->ant =NULL; novo->prox=lista;

  return novo;

}



//Buscar elementos na lista
Lista *busca(Lista *lst,int info){
  Lista *b;

  for(b=lst;b !=NULL;b=b->prox){
    if(b->info == info)
      return b;
    }
    return NULL;
  }

//Remover elementos da lista
  Lista *remover(Lista *lst,int info){
    Lista *r = busca(lst,info);
    if(r == NULL){
      printf("Valor não encontrado\n");
      return lst;
    }

    if(lst == r)
      lst = r->prox;
    else
      r->ant->prox = r->prox;
    if(r->prox!=NULL)
      r->prox->ant = r->ant;

    free(r);
    return lst;
  }

//Mostrar a lista
  void mostra(Lista *lista){
    Lista *imp;

    for(imp=lista;imp != NULL; imp=imp->prox)
      printf("%d\n",imp->info);
    getchar();
  }

  Lista *ordena(Lista *lista){
      Lista *p;
      int tam,i,j,aux;

      for(p=lista;p!=NULL;p=p->prox){
        tam++;
      }
      for(i=tam-1;i>0;i--){
        p=lista;
        for(j=0;j < i;j++){
          if(p->info > p->prox->info){
            aux=p->info;
            p->info=p->prox->info;
            p->prox->info=aux;
          }
          p=p->prox;
        }
      }
      printf("Lista ordenada!!\n");
      mostra(lista);
  }


int main(){
  Lista *lista = NULL;
  Lista *buscar;
  int i,opt,valorBusca;

  do{
    system("clear");
    printf("1-Adicionar uma entrada a lista \n2-Buscar um valor na lista\n3-Deletar um valor da lista\n4-Mostrar a lista\n5- Ordena\n0-Sair\nOpcao:");
    scanf("%d",&opt);
    __fpurge(stdin);


    switch (opt) {
      case 1:lista=Inserir(lista);
             break;

      case 2:scanf("%d",&valorBusca);__fpurge(stdin);
             buscar=busca(lista,valorBusca);
             printf("Valor buscado: %d\n",buscar->info);
             break;

      case 3:printf("Valor deletado:");
             scanf("%d",&valorBusca);__fpurge(stdin);
             remover(lista,valorBusca);
             mostra(lista);
             break;

      case 4:mostra(lista);break;

      case 5:ordena(lista);break;

      case 0:return 0;
      default:
        printf("Opção inválida\n");
        getchar();
    }
  }while(opt);


  return 0;
}
