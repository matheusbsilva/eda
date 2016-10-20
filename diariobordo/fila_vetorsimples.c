#include <stdio.h>
#include <stdlib.h>


int main(){
    int vetor[7];
    int ini=0,fim,i;
    char op;
    fim=ini;

    while (scanf("%c",&op),op!='F') {
        switch (op) {
            case 'I':if(fim < 6)
                        scanf("%d",&vetor[fim++]);
                     else
                        printf("Fila cheia\n");
                     break;

            case 'R':if(fim!=ini)
                        ++ini;
                     else
                        printf("Fila vazia!\n");
                     break;

            case 'P':if(fim!=ini)
                        for (i = ini; i < fim ; i++)
                            printf("Posição %d: %d\n",i,vetor[i]);

                     else
                        printf("Fila Vazia!\n");
                     break;


        }
    }
    return 0;
}
