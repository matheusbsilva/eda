#include <stdio.h>
#include <stdlib.h>

int main(){
  char t[2];
  char *m;
  int num,i,flag=0;

  scanf("%s",t);
  scanf("%d",&num);
  m=(char *)calloc(num*3,sizeof(char));
  scanf("%[^'\n']",m);
  for(i=0;i < num*3;i++){
    if(t[0]==m[i] ||t[1]==m[i])
      flag=1;
  }
  if(flag)
    printf("S\n" );
  else
    printf("N\n" );



  return 0;
}
