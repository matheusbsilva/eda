#include <stdio.h>
#include <stdlib.h>

typedef struct Ps{
  float peso;
  float altura;
  float imc;
} Pessoa;

void ordena(Pessoa *ps,int n){
  int i,j;
  float auxPeso,auxAlt,auxImc;
  for(i=n-1;i>=1;--i){
    for(j=0;j<i;j++){
      if(ps[j].imc < ps[j+1].imc){
        auxAlt=ps[j].altura; auxPeso = ps[j].peso; auxImc= ps[j].imc;
        ps[j].altura = ps[j+1].altura; ps[j].peso = ps[j+1].peso; ps[j].imc = ps[j+1].imc;
        ps[j+1].altura=auxAlt; ps[j+1].peso=auxPeso;ps[j+1].imc=auxImc;
      }
    }
  }
}

int main() {
  Pessoa *indiv;
  int i,n;

  scanf("%d",&n);
  indiv = (Pessoa *)malloc(n*sizeof(Pessoa));

  for (i = 0; i < n; i++) {
    scanf("%f %f",&indiv[i].peso, &indiv[i].altura);
    indiv[i].imc=indiv[i].peso/(indiv[i].altura*indiv[i].altura);
  }
  ordena(indiv,n);
  for (i = 0; i < n; i++) {
    printf("%.2f ",indiv[i].imc);
  }


  return 0;
}
