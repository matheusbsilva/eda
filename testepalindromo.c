#include <stdio.h>
#include <stdlib.h>

int main(){
  int flag=1,n,i,j;
  char palavra[30],inversa[30];
  scanf("%d",&n);
  scanf("%s",palavra);
  j=n-1;
  for(i=0;i < n;i++){
    inversa[j]=palavra[i];
    j--;
  }

  for(i=0;i < n;i++){
    if(palavra[i]!=inversa[i])
      flag=0;
  }
  if(flag)
    printf("%s é um palindromo\n",palavra);
  else
    printf("%s não é um palindromo\n",palavra);
}
