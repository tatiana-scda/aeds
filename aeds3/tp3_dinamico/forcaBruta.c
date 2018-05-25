//
//  forcaBruta.c
//
//
//  Created by tatiana on 21/06/17.
//
//


#include "utils.h"

//inicia e cria a árvore, faz a força bruta para cada lado
void mainForcaBruta(tipoPares *vetor, int tamanho){
    int maiorNum;
    tipoArvore arvore;
    int *pilha = (int*) calloc(tamanho,sizeof(int));
    
    iniciaArvore(&arvore);
    iniciaArvore(&arvore->coloca);
    iniciaArvore(&arvore->naoColoca);
    
    forcaBruta(vetor, arvore->coloca, 0, pilha, 1, tamanho);
    forcaBruta(vetor, arvore->naoColoca, 0, pilha, 0, tamanho);
    
    maiorNum = maior(arvore);
    printf("%d\n", maiorNum);
    free(pilha);
    liberaArvore(arvore);
}

int maior(tipoArvore arvore){
    int valorEsquerda = 0, valorDireita = 0, maximo;
    
    if(arvore->flags == -1)
        return 0;
    if(arvore->coloca)
        valorEsquerda = maior(arvore->coloca);
    if(arvore->naoColoca)
        valorDireita = maior(arvore->naoColoca);
    if (valorEsquerda > valorDireita)
        maximo = valorEsquerda;
    else
        maximo = valorDireita;
    return maximo+arvore->flags;
}

//esquerda 1 - coloca bandeira; direita 0 - nao coloca, entao não tem colisao
void forcaBruta(tipoPares *vetor, tipoArvore arvore, int profundidade, int *pilha, int direcao, int tamanho){
    int i;
    
    if (direcao){
        if (colisaoTrue(vetor, vetor[profundidade].bar, vetor[profundidade].casa, tamanho, pilha)){
            arvore->flags = -1;
            return;
        }
        pilha[profundidade] = 1;
    }
    if(profundidade == tamanho-1){
        arvore->flags = 0;
        for(i = 0; i < tamanho; i++){
            arvore->flags += pilha[i];
        }
        pilha[profundidade] = 0;
        return;
    }
    if(!arvore->coloca){
        iniciaArvore(&arvore->coloca);
    }
    forcaBruta(vetor, arvore->coloca, profundidade+1, pilha, 1, tamanho);
    if(!arvore->naoColoca){
        iniciaArvore(&arvore->naoColoca);
    }
    forcaBruta(vetor, arvore->naoColoca, profundidade+1, pilha, 0, tamanho);
    pilha[profundidade] = 0;
}
