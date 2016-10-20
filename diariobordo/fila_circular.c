#include <stdio.h>
#include <stdlib.h>


int main(){
    int vetor[7];
    int ini=0,fim,i;
    char op;
    fim=ini;

    while (scanf("%c",&op),op!='F') {
        switch (op) {
            case 'I':if((fim+1)%7!=ini){
                        if (fim==7)
                            fim=0;
                        scanf("%d",&vetor[fim++]);
                    }
                     else
                        printf("Fila cheia\n");
                     break;

            case 'R':if(fim!=ini)
                        ++ini;
                     else
                        printf("Fila vazia!\n");
                     break;

            case 'P':if(fim!=ini){
                        i=ini;
                        while(i!=fim){
                            if(i==7)
                                i=0;
                            printf("Posição %d: %d\n",i,vetor[i]);
                            i++;
                        }
                    }

                     else
                        printf("Fila Vazia!\n");
                     break;


        }
    }
    return 0;
}
