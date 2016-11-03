#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica(char *s){
    char *pilha;
    int t,n,i=0;
    n=strlen(s);
    pilha=(char *)malloc(n*sizeof(char));
    t=0;
    while(s[i]!='\0'){
        switch(s[i]){
            case ')':if(t!=0 && pilha[t-1]=='(')
                        --t;
                     else
                        return 0;
                    break;
            case ']':if(t!=0 && pilha[t-1]=='[')
                        --t;
                    else
                        return 0;
                    break;
            case '}':if(t!=0 && pilha[t-1]=='{')
                      --t;
                    else
                      return 0;
                    break;
            case ' ':break;
            case '\n':break;
            default: pilha[t++]=s[i];
        }
        i++;
    }
    return t==0;

}
int main(){
  char *entrada=(char *)calloc(200,sizeof(char));
  fgets(entrada,200,stdin);

  if(verifica(entrada))
    printf("YES\n" );
  else
    printf("NO\n" );

  return 0;
}
