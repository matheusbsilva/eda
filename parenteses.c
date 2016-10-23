#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifica(char *s){
    char *pilha;
    int t,n,i;
    n=strlen(s);
    pilha=(char *)malloc(n*sizeof(char));
    t=0;//pilha vazia
    for(i=0;s[i]!='\0';i++){
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
            default: pilha[t++]=s[i];
        }
    }
    return t==0;

}
int main(){

    return 0;
}
