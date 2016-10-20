#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n,m,sm=0,sn=0,i;
  scanf("%d %d",&n,&m);

  for(i=n-1;i>0;i--){
    if(n%i == 0)
      sn+=i;

  }
  for(i=m-1;i>0;i--){
    if(m%i == 0)
      sm+=i;
  }
  if(sn==m && sm==n)
    printf("S\n");
  else
    printf("N\n" );
  return 0;
}
