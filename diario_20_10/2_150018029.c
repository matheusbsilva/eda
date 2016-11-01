/*  Matheus Batista Silva 150018029     */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int pilha[6],num,ca,i,topo=0,massa=0;
    pilha[topo]=0;

    scanf("%d",&num);

    for(i=0;i < num && topo < 6;i++){
        scanf("%d",&ca);
        if(pilha[topo-1] >= ca || topo==0){
            pilha[topo]=ca;
            massa=massa+pilha[topo];
            topo++;
        }
    }
    printf("MASSA EMPILHADA: %d kg\n",massa);
    return 0;
}
