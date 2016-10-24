#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _p{
  char op;
  struct _p *prox, *ant;
}Pilha;


int calcula_postfix(char *exp){
  int *pilha;
  int i=0,topo=0;

  pilha=(int *)calloc(strlen(exp),sizeof(int));

  while(exp[i]!='\0'){
    switch (exp[i]) {
      case '+':pilha[topo-2]=pilha[topo-1] + pilha[topo-2];
               topo--;
               break;

      case '-':pilha[topo-2]=pilha[topo-2] - pilha[topo-1];
               topo--;
               break;

      case '*':pilha[topo-2]=pilha[topo-2] * pilha[topo-1];
               topo--;
               break;

      case '/':pilha[topo-2]=(pilha[topo-2]) / (pilha[topo-1]);
               topo--;
               break;

      default:pilha[topo++]=exp[i]-48;

    }
    i++;
  }
  return pilha[topo-1];
}

Pilha *empilha(Pilha *p,char c){
  Pilha *novo=(Pilha *)malloc(sizeof(Pilha));
  novo->op=c;
  novo->ant=p;
  novo->prox=NULL;
  p->prox=novo;
  p=novo;

  return p;
}

Pilha *desempilha(Pilha *p){
  Pilha *aux;

  aux=p->ant;
  aux->prox=NULL;
  free(p);

  return aux;
}


char *infix2posfix(char *infix){
  int i=0,j=0;
  char *postfix=(char *)calloc(strlen(infix),sizeof(char));
  Pilha *pilha=(Pilha *)malloc(sizeof(Pilha));

  pilha->prox=NULL;
  pilha->ant=NULL;
  pilha->op='(';


  while(infix[i]!='\0'){

    if(infix[i]=='('){
        pilha=empilha(pilha,infix[i]);
        i++;
    }
    
    else if(infix[i]==')'){
      while(pilha->op != '('){
        postfix[j]=pilha->op;
        pilha=desempilha(pilha);
        j++;
      }
      pilha=desempilha(pilha);
      i++;
    }

    else if(infix[i]=='+' || infix[i]=='-' ){
      while(pilha->op != '('){
        postfix[j]=pilha->op;
        pilha=desempilha(pilha);
        j++;
      }
      pilha=empilha(pilha,infix[i]);
      i++;
    }

    else if(infix[i]=='*' || infix[i]=='/'){
      while(pilha->op != '(' && pilha->op != '+' && pilha->op != '-'){
        postfix[j]=pilha->op;
        pilha=desempilha(pilha);
        j++;
      }
      pilha=empilha(pilha,infix[i]);
      i++;
    }

    else if(infix[i]==' ')
      i++;

    else{
      postfix[j]=infix[i];
      i++;
      j++;
    }
  }
  postfix[++j]='\0';

  return postfix;
}



int main(){
  char *infix=(char *)calloc(100,sizeof(char));
  char *postfix=(char *)calloc(100,sizeof(char));
  scanf("%s", infix);


  postfix=infix2posfix(infix);
  printf("%d\n",calcula_postfix(postfix));

  return 0;
}
