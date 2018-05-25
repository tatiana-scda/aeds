//
//  guloso.c
//
//
//  Created by tatiana on 21/06/17.
//
//

#include "utils.h"

void mainGuloso(tipoPares *vetor, int tamanho){
    int bandeiras = 0;
    int *pilha = (int*) calloc(tamanho,sizeof(int));
    
    guloso(pilha, vetor, tamanho, &bandeiras);
    
    printf("%d\n", bandeiras);
    free(pilha);
}

//empilha os valores que não colidem e testa colisoes
void guloso(int *pilha, tipoPares *vetor, int tamanho, int *bandeiras){
    int i;

    for (i = 0; i < tamanho; i++)
        vetor[i].colisao = colisaoNumero (vetor, vetor[i].bar, vetor[i].casa, tamanho);
    
    //ordena em funcao do numero de colisoes, crescente
    qsort (vetor, tamanho, sizeof(tipoPares), compareC);
    
    for (i = 0; i < tamanho; i++){
        if (!colisaoTrue(vetor, vetor[i].bar, vetor[i].casa, tamanho, pilha)){
            pilha[i] = 1;
            (*bandeiras) += 1;
        }
    }
}
