#include <stdio.h>
#include <stdlib.h>

int calcula_postfix(char *exp){
  int pilha[20];
  int i=0,topo=0,j;

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

      default:pilha[topo++]=exp[i]-48; //Tabela Ascii

    }
    i++;
  }
  return pilha[topo-1];
}

int main(){
  char vetor[20];
  scanf("%s",vetor);

  putchar('\n');

  printf("%d\n",calcula_postfix(vetor));
  return 0;
}
