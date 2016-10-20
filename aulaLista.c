//Lista duplamente encadeadas com cabeçalho
//O no aponta para o inicio e o fim da lista e armazena a quantidade de elementos da listas

#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
  int info;
  struct _no *ant, *prox;
}no;

typedef struct cab{
  int qtd;
  struct _no *inicio, *fim;
}lista;

lista *definir(void){
  lista *l;
  l=(lista*)malloc(sizeof(lista));
  l->qtd=0;
  l->inicio=NULL;
  l->fim=NULL;
  return l;
}

no *inserir_inicio(lista *l){
  no *p;
  p=(no*)malloc(sizeof(no));
  scanf("%d",&p->info);
  p->ant=NULL;
  p->prox=l->inicio;
  l->inicio=p;

  if(l->fim==NULL)
    l->fim=l->inicio;
  else
    l->inicio->prox->ant=p;

  l->qtd++;
  return p;
}

int remove_inicio(lista *l){
  int x;
  no *p;
  p=l->inicio;
  l->inicio=p->prox;

  if(l->inicio==NULL)
    l->fim=NULL;
  else
    l->inicio->ant=NULL;
  x=p->info;
  free(p);

  l->qtd--;
  return x;
}

void imprimir(lista *l){
  no *imp;
  for(imp=l->inicio;imp !=NULL; imp=imp->prox){
    printf("%d\n",imp->info);
  }
  __fpurge(stdin);
  getchar();
}

int main(){
  lista *l = definir();
  int opc,x;
  do{
    system("clear");
    printf("0-Sair\n1-Inserir no inicio\n2-Remover no inicio\n3-Imprimir\nOpção:");
    scanf("%d",&opc);

    switch (opc) {
      case 1:inserir_inicio(l);break;
      case 2:printf("Valor removido: %d\n",remove_inicio(l));__fpurge(stdin);getchar();break;
      case 3:imprimir(l);break;
      case 0: return 0;
      default:
        printf("Opção inválida\n");__fpurge(stdin);getchar();break;
    }
  }while(opc);
}
