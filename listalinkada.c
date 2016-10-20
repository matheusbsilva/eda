#include <stdio.h>
#include <stdlib.h>

typedef struct _no{
  int num;
  struct _no *prox,*ant;
}Node;

int main() {
  Node *l=NULL,*p;
  int n;
  int i=0;l=NULL;
  while (i< 7) {
    scanf("%d",&n);
    p = (Node*)malloc(sizeof(Node*));
    p->num = n;
    p->prox = l;
    p->ant = NULL;
    l->ant=p;
    l = p;
    i++;
  }

  p=l;
  printf("\n");
  while(p!=NULL){
    printf("%d\n",p->num);
    p=p->prox;
  }


  return 0;
}
