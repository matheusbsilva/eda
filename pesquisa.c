#include <stdio.h>
#define TAM 7
void entrada(int *v){
  int i;
  for(i = 0;i < TAM;i++ ){
    printf("Entre com os dados:\n");
    scanf("%d", &v[i]);
  }
}

void ordena(int *v){
  int i,j,aux;
  for(i = TAM-1;i>=1;i--){
    for(j=0; j < i ;j++){
      if(v[j] > v[j+1]){
        aux = v[j];
        v[j] = v[j +1];
        v[j+1] = aux;
      }
    }
  }
  printf("Ordenado com sucesso\n");
}

void mostra(int *v){
  int i;
  for(i = 0;i < TAM;i++)
    printf("v = %d \n",v[i]);
}

int consulta(int *v){ //PESQUISAR CONSULTA BINÁRIA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  int inf=0;
  int sup=TAM-1;
  int chave;
  int i;
  printf("Digite o número que deseja encontrar\n");
  scanf("%d",&chave);
  while(inf <= sup){
    i=(inf+sup)/2;
    if(chave == v[i]){
      printf("Posição %d vetor = %d\n",i,v[i]);
      break;
    }
    if(chave < v[i])
      sup = v[i-1];
    else
      inf = v[i+1];
  }
}

int menu(int *v){
  int opc;
  // system("clear");
  printf("Selecione:\n 0-Sair \n 1-Entradade dados \n 2-Ordenar \n 3-Impressão do vetor \n 4-consulta \n");
  scanf("%d",&opc);

  switch (opc) {
    case 0: return 0;break;
    case 1: entrada(v);menu(v);break;
    case 2: ordena(v);menu(v);break;
    case 3: mostra(v);menu(v);break;
    case 4: consulta(v);menu(v);break;
  }
}



int main(int argc, char const *argv[]) {
  int vetor[TAM];
  menu(vetor);

  return 0;
}
